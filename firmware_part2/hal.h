/*
 * File:   hal.h
 * Author: msuzer
 *
 * Created on 08 Mart 2014 Cumartesi, 00:20
 */

#ifndef HAL_H
#define	HAL_H

#define USE_AND_OR
#define FIRMWARE_VERSION        100
#define FOSC                    32000000L
#define FCY                     FOSC/2		//instruction frequency

#include <xc.h>
#include <qei.h>
#include <spi.h>
#include <pwm12.h>
#include <ports.h>
#include <pps.h>
#include <timer.h>
#include <libpic30.h>
#include "mcu_pin_assignments.h"
#include "../../UserLibraries/MicrochipXC/Serial/lib_spi.h"
#include "../../UserLibraries/MicrochipXC/Serial/lib_serial.h"
#include "../../UserLibraries/MicrochipXC/QEI/lib_qei.h"
#include "../../UserLibraries/MicrochipXC/L6474/L6474.h"
#include "../../UserLibraries/MicrochipXC/FlashDataEEProm/dee_emulation_16bit.h"

#define HIGH                     1
#define LOW                      0
#define ON                       HIGH
#define OFF                      LOW
#define CW                       HIGH
#define CCW                      LOW

#define BAUD_RATE_9600          ((FCY/16/9600) - 1) //103@19200
#define BAUD_RATE_19200         ((FCY/16/19200) - 1) //51@19200

#define CPU_USER_TASK_FREQ      50 //Hz
#define TIMER2_PRESCALER        T2_PS_1_256
#define TIMER2_PERIOD_VAL       (FCY/CPU_USER_TASK_FREQ/256) //0.02sn
#define SWITCH_DEBOUNCE         10

#define SoftReset()             {asm ("RESET");}         //Reset in software

typedef enum {
    PWM_CH1 = '1',
    PWM_CH2 = '2'
} PWMChannel;

void init_mcu_core(void);
void init_peripherals(void);
void rs485_direction_control(BOOL transmitter);
BOOL spi_is_tx_busy(SPIChannel channel);
UINT8 spi_loop(SPIChannel, UINT8);
void spi_assert_cs(SPIChannel, BOOL);
UINT16_VAL get_sensors(void);
void read_sensors(void);
void blink_led(void);

BOOL get_stepper_flag(StepperChannel);
BOOL get_stepper_direction(StepperChannel);
void set_stepper_direction(StepperChannel, BOOL);
void assert_stepper_reset(StepperChannel, BOOL);
void set_pwm_freq(StepperChannel, UINT16);
void set_pwm_outputs(StepperChannel, BOOL);

UINT16_VAL GetSensors(void);
UINT32 millis(void);
void set_report_qei(BOOL state);

typedef enum {
    StepperMotor1 = '1',
    StepperMotor2 = '2'
} StepperMotors;

#endif	/* HAL_H */
