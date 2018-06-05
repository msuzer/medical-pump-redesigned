/*
 * File:   main.c
 * Author: msuzer
 *
 * Created on 08 March 2014, 00:18
 */

#include "ui.h"
#include "hal.h"
#include <stdlib.h>

UARTHardwareControl __uartHWControl = {
    rs485_direction_control
};

UINT32 tick = 0;

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
    COMPort.Open(&__uartHWControl);

    __delay_ms(1000);
    EnableIntT2;

    while (TRUE) {
        CheckUpUserInstruction();
        __delay_ms(10);
    }

    return 0;
}
