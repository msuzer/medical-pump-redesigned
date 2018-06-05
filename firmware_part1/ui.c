#include "ui.h"
#include "hal.h"
#include <stdio.h>

unsigned int n, value, duty_cycle;
BOOL run, dir;
BOOL someFlag = FALSE;
UINT32 timeout1 = 0xFFFFFFFF;
UINT32 timeout2 = 0xFFFFFFFF;
DCMotors motor_running = 0;
UARTPorts device_need_to_respond = 0;
StateMachine currentState1 = ParkState;
StateMachine currentState2 = ParkState;

void cancelTimerAlarm(DCMotors motor) {
    if (motor_running == motor)
        timeout1 = 0xFFFFFFFF;
}

void setTimerAlarm(DCMotors motor, UINT16 tout) {
    timeout1 = millis() + tout;
    motor_running = motor;
}

void checkTimerAlarm(void) {
    BOOL flashLED2 = FALSE;
    if (millis() > timeout1) {
        timeout1 = 0xFFFFFFFF;
        if (motor_running == DCMotor0 || motor_running == DCMotor1 ||
                motor_running == DCMotor4 || motor_running == DCMotor5) {
            currentState1 = ParkState; // Durum makinesini kapat
            __delay_ms(10);
            if (DCMotor0SideBPin) {
                COMPort.println(COM1, "Sens0B Timeout!");
                flashLED2 = TRUE;
            } else if (DCMotor0SideAPin) {
                COMPort.println(COM1, "Sens1B Timeout!");
                flashLED2 = TRUE;
            } else if (DCMotor1SideBPin) {
                COMPort.println(COM1, "Sens2B Timeout!");
                flashLED2 = TRUE;
            } else if (DCMotor1SideAPin) {
                COMPort.println(COM1, "Sens3B Timeout!");
                flashLED2 = TRUE;
            } else if (DCMotor4SideAPin || DCMotor4SideBPin) {
                COMPort.println(COM1, "Sens2C Timeout!");
                flashLED2 = TRUE;
            } else if (DCMotor5SideAPin || DCMotor5SideBPin) {
                COMPort.println(COM1, "Sens3C Timeout!");
                flashLED2 = TRUE;
            }
        } else {
            COMPort.printf(COM1, "DCMotor%c timeout", motor_running);
            flashLED2 = TRUE;
        }
        RunDCMotors(motor_running, 0, 0, 0);
        motor_running = 0;
        if (flashLED2) {
            //__delay_ms(20);
            COMPort.println(COM1, "L211"); //Flash LED2
            flashLED2 = FALSE;
        }
    } else if (someFlag) {
        if (GetSensors().bits.b0) { //Sens0B: Motor0 CCW Limit
            if (DCMotor0SideBPin) {
                RunDCMotors(DCMotor0, 0, 0, 0);
                COMPort.println(COM1, "Sens0B Active!");
            }
        } else if (GetSensors().bits.b1) { //Sens1B: Motor0 CW Limit
            if (DCMotor0SideAPin) {
                RunDCMotors(DCMotor0, 0, 0, 0);
                COMPort.println(COM1, "Sens1B Active!");
            }
        }

        if (GetSensors().bits.b2) { //Sens2B: Motor1 CCW Limit
            if (DCMotor1SideBPin) {
                RunDCMotors(DCMotor1, 0, 0, 0);
                COMPort.println(COM1, "Sens2B Active!");
            }
        } else if (GetSensors().bits.b3) { //Sens3B: Motor1 CW Limit
            if (DCMotor1SideAPin) {
                RunDCMotors(DCMotor1, 0, 0, 0);
                COMPort.println(COM1, "Sens3B Active!");
            }
        }

        if (GetSensors().bits.b6) { //Sens2C: Motor4 Limit
            if (DCMotor4SideAPin || DCMotor4SideBPin) {
                RunDCMotors(DCMotor4, 0, 0, 0);
                COMPort.println(COM1, "Sens2C Active!");
            }
        }

        if (GetSensors().bits.b7) { //Sens3C: Motor4 Limit
            if (DCMotor5SideAPin || DCMotor5SideBPin) {
                RunDCMotors(DCMotor5, 0, 0, 0);
                COMPort.println(COM1, "Sens3C Active!");
            }
        }
    }
}

void RunStateMachine1(void) {
    switch (currentState1) {
        case State1: // Durum makinesi baslangici
            if (GetSensors().bits.b0) { //
                cancelTimerAlarm(DCMotor0); //Alarmi durdur
                RunDCMotors(DCMotor0, 0, 0, 0); // Motoru durdur
                timeout2 = millis() + (TIME_LIMIT1 / (1000 / CPU_USER_TASK_FREQ)); //Gecikmeyi baslat
                currentState1 = State2; //Durum makinesini ikinci duruma al
            }
            break;
        case State2:
            if (millis() > timeout2) { // Gecikme bitti mi?
                timeout2 = 0xFFFFFFFF;
                RunDCMotors(DCMotor0, 1, 1, 0); // Motoru CW baslat
                setTimerAlarm(DCMotor0, (TIME_LIMIT2 / (1000 / CPU_USER_TASK_FREQ))); //Alarm kur
                currentState1 = State3; //Durum makinesini ucuncu duruma al
            }
            break;
        case State3:
            if (GetSensors().bits.b1) {
                cancelTimerAlarm(DCMotor0); //Alarmi durdur
                RunDCMotors(DCMotor0, 0, 0, 0); // Motoru durdur
                currentState1 = ParkState; // Durum makinesini kapat
            }
            break;
        default:
            break;
    }
}

void RunStateMachine2(void) {
    switch (currentState2) {
        case State1: // Durum makinesi baslangici
            if (GetSensors().bits.b1) { //Sens1B
                currentState2 = State2; //Durum makinesini ikinci duruma al
                RunDCMotors(DCMotor0, 0, 1, 0);
                COMPort.println(COM1, "Sens1B Active!");
            }
            break;
        case State2:
            if (GetSensors().bits.b0) { //Sens0B
                currentState2 = ParkState; // Durum makinesini kapat
                RunDCMotors(DCMotor0, 0, 0, 0);
                COMPort.println(COM1, "Sens0B Active!");
            }
            break;
        case State3:
        default:
            break;
    }
}

static void ParseAndApplyCommand(char * param) {
    UserInstructions instruction = (UserInstructions) param[0];
    char * args = &param[1];
    char channel = *args;

    COMPort.println(COM1, "L200"); //Turn off LED2
    switch (instruction) {
        case PRINT_SENSORS:
            COMPort.printf(COM1, "ExtSens: %s", bin2str(GetSensors().Val, 10));
            break;
        case TEST_SENSORS:
            currentState2 = State1; // Durum makinesini calistir
            RunDCMotors(DCMotor0, 1, 1, 0); // Motoru CW baslat
            someFlag = FALSE;
            break;
        case EL_SENS:
            //El Sense basilinca buraya gelir.
            if (GetSensors().bits.b1) { //Sens1B aktif mi?
                dir = (args[1] == '1'); // yön bilgisi al
                run = (args[2] == '1'); //dur/kalk bilgisi al
                RunDCMotors(DCMotor0, dir, run, 0); // ilgili motora gönder (DCMotor0)
                setTimerAlarm(DCMotor0, (TIME_LIMIT2 / (1000 / CPU_USER_TASK_FREQ))); //Alarm kur
                currentState1 = State1; // Durum makinesini calistir
                someFlag = FALSE;
            }
            break;
        case RUN_DC_MOTORS:
            dir = (args[1] == '1');
            run = (args[2] == '1');
            if (run) {
                someFlag = TRUE;
                n = sscanf(&args[3], "%d%d", &value, &duty_cycle);
                if (n > 0 && value) {
                    setTimerAlarm(channel, value / (1000 / CPU_USER_TASK_FREQ));
                }
                if (n == 2) {
                    RunDCMotors(channel, dir, run, duty_cycle);
                } else {
                    RunDCMotors(channel, dir, run, DC_MOTOR_PWM_PERIOD);
                }
                if (dir) {
                    COMPort.printf(COM1, "DC motor%c runs CW", channel);
                } else {
                    COMPort.printf(COM1, "DC motor%c runs CCW", channel);
                }
            } else {
                COMPort.printf(COM1, "DC motor%c stopped", channel);
                RunDCMotors(channel, 0, 0, 0);
            }
            break;
        case INS_RFIDS:
            device_need_to_respond = (args[0] == '1') ? COM2 : COM3;
            COMPort.println(device_need_to_respond, ++args);
            break;
        case BOARD_LOOPBACK:
            COMPort.printf(COM1, "Loopback test: \"%s\"", args);
            break;
        case PRINT_FW_VER:
            COMPort.println(COM1, "Mainboard DC Motor Controller v2.1");
            break;
        default:
            COMPort.printf(COM1, "Invalid instruction: \"%s\"", param);
            break;
    }
}

void CheckUpUserInstruction(void) {
    if (COMPort.GetMessageLen(COM1) > 0) {
        ParseAndApplyCommand(COMPort.GetMessage(COM1));
    }

    if (COMPort.GetMessageLen(COM2) > 0) {
        COMPort.printf(COM1, "<RFID1> %s", COMPort.GetMessage(COM2));
    }

    if (COMPort.GetMessageLen(COM3) > 0) {
        COMPort.printf(COM1, "<RFID2> %s", COMPort.GetMessage(COM3));
    }

    checkTimerAlarm();
    RunStateMachine1();
    RunStateMachine2();
}
