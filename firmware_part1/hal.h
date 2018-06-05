/*
 * File:   hal.h
 * Author: msuzer
 *
 * Created on 08 Mart 2014, 00:20
 */

#ifndef HAL_H
#define	HAL_H

#define TIME_LIMIT1             5000
#define TIME_LIMIT2             6000

#define USE_AND_OR
#define FIRMWARE_VERSION        100
#define FOSC                    32000000L
#define FCY                     FOSC/2		//instruction frequency

#include "../../UserLibraries/MicrochipXC/include/GenericTypeDefs.h"
#include "PIC24F_periph_features.h"
#include "mcu_pin_assignments.h"
#include "PPS.h"
#include "ports.h"
#include "PwrMgnt.h"
#include <uart.h>
#include <timer.h>
#include <libpic30.h>
#include "../../UserLibraries/MicrochipXC/Serial/lib_serial.h"
#include "../../UserLibraries/MicrochipXC/utils/bin2str.h"

#define LOW                     0
#define HIGH                    1
#define DISABLED                0
#define ON                      HIGH
#define OFF                     LOW
#define CW                      HIGH
#define CCW                     LOW

#define CPU_USER_TASK_FREQ      50 //Hz
#define TIMER2_PRESCALER        T2_PS_1_256
#define TIMER2_PERIOD_VAL       (FCY/CPU_USER_TASK_FREQ/256) //0.02sn
#define SWITCH_DEBOUNCE         3
#define SoftReset()             {asm ("RESET");}         //Reset in software
#define T2_INT_PRIORITY         T2_INT_PRIOR_1

#define BAUD_RATE_9600          ((FCY/16/9600) - 1) //103@19200
#define BAUD_RATE_19200         ((FCY/16/19200) - 1) //51@19200

#define DC_MOTOR_PWM_PERIOD              832 //19230 Hz

void init_mcu_core(void);
void init_peripherals(void);
void rs485_direction_control(BOOL transmitter);
void blink_led(void);
void read_sensors(void);
UINT32 millis(void);
UINT16_VAL GetSensors(void);

typedef enum {
    DCMotor0 = '0',
    DCMotor1 = '1',
    DCMotor2 = '2',
    DCMotor3 = '3',
    DCMotor4 = '4',
    DCMotor5 = '5',
    DCMotor6 = '6',
    DCMotor7 = '7'
} DCMotors;

void RunDCMotors(DCMotors motor, BOOL dir, BOOL state, UINT16 dc);

#endif	/* HAL_H */
