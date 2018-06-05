/*
 * File:   main.c
 * Author: msuzer
 *
 * Created on 08 March 2014, 00:18
 */

#include "ui.h"
#include "hal.h"

const char* BoardName = "MainBoard";

UINT16_VAL SensorStateOld = {0};
UINT32 tick = 0;

EthernetHardwareControl ethHWControl__ = {
    get_w5500_int_flag,
    assert_w5500_reset
};

UARTHardwareControl uartHWControl__ = {
    rs485_direction_control
};

SPIHardwareControl spiHWControl__ = {
    spi_loop,
    spi_assert_cs,
    spi_is_tx_busy
};

UINT32 millis(void) {
    return tick;
}

void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void) {
    ++tick;
    read_sensors();
#ifdef SetLED
    blink_led();
#endif
    T2_Clear_Intr_Status_Bit;
}

int main(void) {
    init_mcu_core();
    init_peripherals();
    SPIPort.Open(&spiHWControl__);
    COMPort.Open(&uartHWControl__);
    __delay_ms(1000);
    DataEEInit();
    dataEEFlags.val = 0;
    W5500_Init(&ethHWControl__);
    Set_Net_Conf(Get_Net_Info());
    restore_service_counter();
    EnableIntT2;

    while (TRUE) {
        tcp_server_socket(SOCK_TCPS, PORT_TCPS);
        tcp_client_socket(SOCK_TCPC, PORT_TCPC);
        udp_server_socket(SOCK_UDPS, PORT_UDPS, BoardName);
        CheckUpUserInstruction();
        CheckUpDeviceResponse();
        if (SensorStateOld.Val != GetSensors().Val) {
            SensorStateOld.Val = GetSensors().Val;
            EthernetPort.printf(SOCK_TCPC, "<CPU0> ExtSens: %s\r\n", bin2str(GetSensors().Val, 6));
        }
    }

    return 0;
}
