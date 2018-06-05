#include "ui.h"
#include "hal.h"
#include <stdio.h>
#include <string.h>

#define RESPONSE_TIMEOUT            300

UINT32_VAL ucServiceCounter;
UINT32 timeout = 0xFFFFFFFF;
UARTPorts device_need_to_respond = 0;
int position, value, control_signal, n, ip_digit, mac_digit;
INT32 balancer_value;
BOOL blink, state;
BOOL el_sens_locked = FALSE;

wiz_NetInfo gWIZNETINFO = {
    .mac =
    {0x00, 0x08, 0xDC, 0xAB, 0xCD, 0xEA},
    .ip =
    {192, 168, 1, 100},
    .sn =
    {255, 255, 255, 0},
    .gw =
    {192, 168, 1, 1},
    .dns =
    {192, 168, 1, 1},
    .dhcp = NETINFO_DHCP
};

void backup_service_counter(void);

BOOL backup_board_net_info(UINT16 ip, UINT16 mac) {
    BOOL changed = FALSE;

    if (ip < 2 || ip > 254)
        ip = gWIZNETINFO.ip[3];

    if (mac > 255)
        mac = gWIZNETINFO.mac[5];

    if (DataEERead(1) != ip) {
        DataEEWrite(ip, 1);
        changed = TRUE;
    }

    if (DataEERead(2) != mac) {
        DataEEWrite(mac, 2);
        changed = TRUE;
    }

    backup_service_counter();

    if (DataEERead(0) != 0x55)
        DataEEWrite(0x55, 0);

    return changed;
}

void restore_board_net_info(void) {
    char val;
    if (DataEERead(0) == 0x55) {
        val = DataEERead(1);
        if (val > 1 && val < 255)
            gWIZNETINFO.ip[3] = val;
        gWIZNETINFO.mac[5] = DataEERead(2);
    }
}

void backup_service_counter(void) {
    if (ucServiceCounter.byte.MB != DataEERead(3))
        DataEEWrite(ucServiceCounter.byte.MB, 3);

    if (ucServiceCounter.byte.UB != DataEERead(4))
        DataEEWrite(ucServiceCounter.byte.UB, 4);

    if (ucServiceCounter.byte.HB != DataEERead(5))
        DataEEWrite(ucServiceCounter.byte.HB, 5);

    if (ucServiceCounter.byte.LB != DataEERead(6))
        DataEEWrite(ucServiceCounter.byte.LB, 6);
}

void restore_service_counter(void) {
    if (DataEERead(0) == 0x55) {
        ucServiceCounter.byte.MB = DataEERead(3);
        ucServiceCounter.byte.UB = DataEERead(4);
        ucServiceCounter.byte.HB = DataEERead(5);
        ucServiceCounter.byte.LB = DataEERead(6);
    } else {
        ucServiceCounter.Val = 0;
    }
}

wiz_NetInfo* Get_Net_Info(void) {
    restore_board_net_info();
    return &gWIZNETINFO;
}

void cancelTimerAlarm(UARTPorts dev) {
    if (device_need_to_respond == dev)
        timeout = 0xFFFFFFFF;
}

void setTimerAlarm(UARTPorts device, UINT16 tout) {
    timeout = millis() + tout;
    device_need_to_respond = device;
}

void checkTimerAlarm(void) {
    if (millis() > timeout) {
        switch (device_need_to_respond) {
            case COM1:
                EthernetPort.println(SOCK_TCPC, "<CPU0> CPU1 not responded!\r\n");
                break;
            case COM2:
                EthernetPort.println(SOCK_TCPC, "<CPU0> CPU2 not responded!\r\n");
                break;
            case COM3:
                EthernetPort.println(SOCK_TCPC, "<CPU0> BAL1 not responded!\r\n");
                break;
            case COM4:
                EthernetPort.println(SOCK_TCPC, "<CPU0> BAL2 not responded!\r\n");
                break;
        }
        timeout = 0xFFFFFFFF;
    }
}

static void ParseAndApplyEthCommand(char * param) {
    SpecialSign special_sign = (SpecialSign) * param;
    UserInstructions instruction = (UserInstructions) * param;
    char * args = &param[1];

    switch (special_sign) {
        case SPECIAL_SIGN_UP_COUNT:
            ucServiceCounter.Val += 1;
            backup_board_net_info(256, 256);
            //backup_service_counter();
            instruction = *args++; //this is for the instruction parameters
            break;
        case SPECIAL_SIGN_PRT_COUNTER:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> Remaining: %ld\r\n", (SERVICE_TIME_REMINDER - ucServiceCounter.Val));
            return;
        case SPECIAL_SIGN_RST_COUNTER:
            if (strcmp(args, SPECIAL_SIGN_RST_PASS) == 0) {
                ucServiceCounter.Val = 0;
                backup_board_net_info(256, 256);
                //backup_service_counter();
                EthernetPort.println(SOCK_TCPC, "<CPU0> Service Counter reset!\r\n");
                SetSingleDout(2, 0, 0);
            }
            return;
        default: // If we are here, then there is no "special_sign"
            break;
    }

    if (ucServiceCounter.Val >= SERVICE_TIME_REMINDER) {
        EthernetPort.println(SOCK_TCPC, "<CPU0> Service Time!\r\n");
        SetSingleDout(2, 1, 1);
        return;
    }

    switch (instruction) {
        case PRINT_SENSORS:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> ExtSens: %s\r\n",
                    bin2str(GetSensors().Val, 6));
            if (!CMSTATbits.C3OUT) {
                EthernetPort.println(SOCK_TCPC, "<CPU0> Battery Low!\r\n");
            }
            break;
        case PRINT_TEMPERATURE:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> Temperature: %3.1f\r\n", ds1820_read());
            break;
        case PRINT_ALL_DOUTS:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> LEDs: %s\r\n", bin2str(GetLEDPort(), 7));
            break;
        case SET_SINGLE_DOUT:
            position = (args[0] & 0x0F);
            state = (args[1] == '1');
            blink = (args[2] == '1');
            SetSingleDout(position, state, blink);
            EthernetPort.printf(SOCK_TCPC, "<CPU0> Set LED%d: <%d><%d>\r\n", position, state, blink);
            break;
        case SET_ALL_DOUTS:
            if (sscanf(args, "%d", &value) == 1) {
                SetLEDPort(value);
                EthernetPort.println(SOCK_TCPC, "<CPU0> Set all LEDs!\r\n");
            } else {
                EthernetPort.println(SOCK_TCPC, "<CPU0> I need 1 parameter!\r\n");
            }
            break;
        case RUN_PERISTATIC_PUMP:
            instruction = *args++;
            if (sscanf(args, "%d", &value) == 1) {
                if (instruction == 'A') {
                    if (value > 0)
                        EthernetPort.println(SOCK_TCPC, "<CPU0> Peristatic pump runs CW\r\n");
                    else if (value < 0)
                        EthernetPort.println(SOCK_TCPC, "<CPU0> Peristatic pump runs CCW\r\n");
                    else
                        EthernetPort.println(SOCK_TCPC, "<CPU0> Peristatic pump stopped\r\n");
                    run_peristaltic_motor(value);
                } else if (instruction == 'B') {
                    if (!PIController.enabled) {
                        PIController.Init(value);
                        EthernetPort.println(SOCK_TCPC, "<CPU0> Peristatic pump filling-up\r\n");
                        COMPort.println(COM3, "B");
                        setTimerAlarm(COM3, RESPONSE_TIMEOUT);
                    } else {
                        PIController.enabled = 0;
                        run_peristaltic_motor(0);
                        //COMPort.println(COM3, "A");
                        EthernetPort.println(SOCK_TCPC, "<CPU0> Cancelling previous fill!\r\n");
                    }
                }
            } else {
                EthernetPort.println(SOCK_TCPC, "<CPU0> I need 1 parameter!\r\n");
            }
            break;
        case LOCK_EL_SENS:
            if (*args == '1') {
                el_sens_locked = TRUE;
                EthernetPort.println(SOCK_TCPC, "<CPU0> ElSens is locked!\r\n");
            } else {
                el_sens_locked = FALSE;
                EthernetPort.println(SOCK_TCPC, "<CPU0> ElSens is unlocked!\r\n");
            }
            break;
        case INS_PIC24FJ:
            COMPort.println(COM1, args);
            setTimerAlarm(COM1, RESPONSE_TIMEOUT);
            break;
        case INS_DSPIC33FJ:
            COMPort.println(COM2, args);
            setTimerAlarm(COM2, RESPONSE_TIMEOUT);
            break;
        case INS_BALANCERS:
            device_need_to_respond = (args[0] == '1') ? COM3 : COM4;
            COMPort.println(device_need_to_respond, ++args);
            setTimerAlarm(device_need_to_respond, RESPONSE_TIMEOUT);
            break;
        case PRINT_BOARD_NET_CONFIG:
            print_net_info(&gWIZNETINFO);
            break;
        case SET_BOARD_IP:
            n = sscanf(args, "%d%d", &ip_digit, &mac_digit);
            if (n == 1) {
                mac_digit = gWIZNETINFO.mac[5];
                n++;
            }

            if (n == 2) {
                if (backup_board_net_info(ip_digit, mac_digit)) {
                    restore_board_net_info();
                    EthernetPort.println(SOCK_TCPC, "<CPU4> Board Network Configuration changed!\r\n");
                    print_net_info(&gWIZNETINFO);
                    EthernetPort.println(SOCK_TCPC, "<CPU4> Board restarting!\r\n");
                    __delay_ms(1000);
                    SoftReset();
                } else {
                    EthernetPort.println(SOCK_TCPC, "<CPU4> Nothing changed!\r\n");
                }
            } else {
                EthernetPort.println(SOCK_TCPC, "<CPU4> I need 1 parameter!\r\n");
            }
            break;
        case BOARD_LOOPBACK:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> Loopback test: \"%s\"\r\n", args);
            break;
        case PRINT_FW_VER:
            EthernetPort.println(SOCK_TCPC, "<CPU0> Mainboard v2.1\r\n");
            break;
        default:
            EthernetPort.printf(SOCK_TCPC, "<CPU0> Invalid instruction: \"%s\"\r\n", param);
            break;
    }
}

void CheckUpUserInstruction(void) {
    static BOOL sens2_activated = FALSE;

    if (EthernetPort.GetMessageLen() > 0) {
        ParseAndApplyEthCommand(EthernetPort.GetMessage());
    }

    if (!el_sens_locked) {
        if (GetSensors().bits.b2) { //ElSens Active?
            if (!sens2_activated) {
                sens2_activated = TRUE;
                COMPort.println(COM1, "C001");
                setTimerAlarm(COM1, RESPONSE_TIMEOUT);
            }
        } else {
            sens2_activated = FALSE;
        }
    }
}

void CheckUpDeviceResponse(void) {
    char * temp;
    if (COMPort.GetMessageLen(COM1) > 0) {
        temp = COMPort.GetMessage(COM1);
        if (temp[0] == 'L') {
            position = (temp[1] & 0x000F);
            state = (temp[2] == '1');
            blink = (temp[3] == '1');
            SetSingleDout(position, state, blink);
        } else {
            EthernetPort.println(SOCK_TCPC, "<CPU1> ");
            EthernetPort.println(SOCK_TCPC, temp);
            EthernetPort.println(SOCK_TCPC, "\r\n");
            cancelTimerAlarm(COM1);
        }
    }

    if (COMPort.GetMessageLen(COM2) > 0) {
        temp = COMPort.GetMessage(COM2);
        if (temp[0] == 'L') {
            position = (temp[1] & 0x000F);
            state = (temp[2] == '1');
            blink = (temp[3] == '1');
            SetSingleDout(position, state, blink);
        } else {
            EthernetPort.println(SOCK_TCPC, "<CPU2> ");
            EthernetPort.println(SOCK_TCPC, COMPort.GetMessage(COM2));
            EthernetPort.println(SOCK_TCPC, "\r\n");
            cancelTimerAlarm(COM2);
        }
    }

    if (COMPort.GetMessageLen(COM3) > 0) {
        temp = COMPort.GetMessage(COM3);
        if (PIController.enabled) {
            sscanf(&temp[8], "%ld", &balancer_value);
            balancer_value /= 100;
            control_signal = PIController.ControlLoop(balancer_value);
            run_peristaltic_motor(control_signal);
            if (!PIController.enabled) { //if "ControlLoop" altered "enabled"
                EthernetPort.println(SOCK_TCPC, "<CPU0> Peristatic pump filled-up!\r\n");
                //COMPort.println(COM3, "A");
            }
        }

        EthernetPort.println(SOCK_TCPC, "<BAL1> ");
        EthernetPort.println(SOCK_TCPC, temp);
        EthernetPort.println(SOCK_TCPC, "\r\n");
        cancelTimerAlarm(COM3);
    }

    if (COMPort.GetMessageLen(COM4) > 0) {
        EthernetPort.println(SOCK_TCPC, "<BAL2> ");
        EthernetPort.println(SOCK_TCPC, COMPort.GetMessage(COM4));
        EthernetPort.println(SOCK_TCPC, "\r\n");
        cancelTimerAlarm(COM4);
    }

    checkTimerAlarm();
}
