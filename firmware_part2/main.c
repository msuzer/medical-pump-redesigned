/*
 * File:   main.c
 * Author: msuzer
 *
 * Created on 08 March 2014, 00:18
 */

#include "ui.h"
#include "hal.h"

#define QEI_PRINT_FREQUENCY     4

UINT32 tick = 0;
BOOL reportQEI = FALSE;
BOOL reportQEITimeOut = FALSE;
INT16 qei1_val = -1, qei2_val = -1;
UINT8 code, task_code1, task_code2;

StepperHardwareControl hwControl__ = {
    get_stepper_flag,
    get_stepper_direction,
    set_stepper_direction,
    assert_stepper_reset,
    get_sensors,
    set_pwm_freq,
    set_pwm_outputs
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
    static UINT8 counter = 0;
    ++tick;
    timer_isr_handler(STEPPER_MOTOR1);
    timer_isr_handler(STEPPER_MOTOR2);
    read_sensors();
#ifdef SetLED
    blink_led();
#endif

    if (reportQEI) {
        if (++counter == (CPU_USER_TASK_FREQ / QEI_PRINT_FREQUENCY)) {
            counter = 0;
            reportQEITimeOut = TRUE;
        }
    } else {
        counter = 0;
    }

    _T2IF = 0;
}

void __attribute__((interrupt, no_auto_psv)) _MPWM1Interrupt(void) {
    pwm_isr_handler(STEPPER_MOTOR1);
    pwm_isr_handler(STEPPER_MOTOR2);
    _PWM1IF = 0;
}

void set_report_qei(BOOL state) {
    reportQEI = state;
    reportQEITimeOut = FALSE;
}

void print_qei_counters(void) {
    INT16 temp1, temp2;
    if (reportQEITimeOut) {
        reportQEITimeOut = FALSE;
        temp1 = QEIModule.Read(QEI_CH1);
        temp2 = QEIModule.Read(QEI_CH2);
        if (qei1_val != temp1 || qei2_val != temp2) {
            qei1_val = temp1;
            qei2_val = temp2;
            COMPort.printf(COM1, "QEI1: %06d QEI2: %06d", qei1_val, qei2_val);
        }
    }
}

int main(void) {
    init_mcu_core();
    init_peripherals();
    COMPort.Open(&uartHWControl__);
    SPIPort.Open(&spiHWControl__);
    //restore_user_data();
    __delay_ms(1000);
    __delay_ms(1000);
    __delay_ms(1000);
    StepperMotor.Init(&hwControl__);
    __delay_ms(1000);
    EnableIntT2;

    task_code1 = StepperMotor.GetTaskResultCode(STEPPER_MOTOR1);
    task_code2 = StepperMotor.GetTaskResultCode(STEPPER_MOTOR2);
    while (TRUE) {
        CheckUpUserInstruction();
        print_qei_counters();

        code = StepperMotor.GetTaskResultCode(STEPPER_MOTOR1);
        if (task_code1 != code) {
            task_code1 = code;
            StepperMotor.PrintTaskResult(STEPPER_MOTOR1);
        }

        code = StepperMotor.GetTaskResultCode(STEPPER_MOTOR2);
        if (task_code2 != code) {
            task_code2 = code;
            StepperMotor.PrintTaskResult(STEPPER_MOTOR2);
        }
        __delay_ms(10);
    }

    return 0;
}
