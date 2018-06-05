/*
 * File:   hal.h
 * Author: msuzer
 *
 * Created on 08 March 2014
 */

#ifndef HAL_H
#define	HAL_H

#define USE_AND_OR
#define FIRMWARE_VERSION                100
#define FOSC                            80000000L
#define FCY                             FOSC/2		//instruction frequency

#include "mcu_pin_assignments.h"
#include <xc.h>
#include <pps.h>
#include <spi.h>
#include <uart.h>
#include <timer.h>
#include <i2c.h>
#include <comparator.h>
#include <libpic30.h>

#include "../../UserLibraries/MicrochipXC/FlashDataEEProm/dee_emulation_16bit.h"
#include "../../UserLibraries/MicrochipXC/utils/bin2str.h"
#include "../../UserLibraries/MicrochipXC/Ethernet/Ethernet.h"
#include "../../UserLibraries/MicrochipXC/Ethernet/w5500_init.h"
#include "../../UserLibraries/MicrochipXC/include/GenericTypeDefs.h"
#include "../../UserLibraries/MicrochipXC/Serial/lib_serial_new.h"
#include "../../UserLibraries/MicrochipXC/Serial/lib_spi.h"
#include "../../UserLibraries/MicrochipXC/Serial/lib_i2c.h"
#include "../../UserLibraries/MicrochipXC/utils/pic.h"
#include "../../UserLibraries/MicrochipXC/DS1820B/ds1820b.h"

#define HIGH                            1
#define LOW                             0
#define ON                          	HIGH
#define OFF                         	LOW
#define CW                          	HIGH
#define CCW                         	LOW

#define BUS_DELAY   (200/1000000000)
#define BUS_FREQ    400000
#define BRG_VAL     (((1/BUS_FREQ) + BUS_DELAY) * FCY / 2) - 2

#define BAUD_RATE_9600                  ((FCY/16/9600) - 1) //103@19200
#define BAUD_RATE_19200                 ((FCY/16/19200) - 1) //51@19200

#define CPU_USER_TASK_FREQ              50 //Hz
#define TIMER2_PRESCALER                T2_PS_1_256
#define TIMER2_PERIOD_VAL               (FCY/CPU_USER_TASK_FREQ/256) //0.02sn
#define OC1_PWM_PERIOD                  (FCY/19200)
#define OC1_PWM_DUTY_CYCLE              800
#define SWITCH_DEBOUNCE                 10

#define SoftReset()                     {asm ("RESET");}         //Reset in software

#define T2_INT_PRIORITY                 T2_INT_PRIOR_1
#define ADC_Module_Int_Flag             IFS0bits.AD1IF

#define T2_Clear_Intr_Status_Bit        {_T2IF = 0;}

#define SetOC1PWMDutyCycle(dc)           OC1R = dc

void init_mcu_core(void);
void init_peripherals(void);
void rs485_direction_control(BOOL transmitter);
BOOL spi_is_tx_busy(SPIChannel channel);
UINT8 spi_loop(SPIChannel, UINT8);
void spi_assert_cs(SPIChannel, BOOL);
void run_peristaltic_motor(INT16);
void blink_led(void);
UINT16_VAL GetSensors(void);
void read_sensors(void);
UINT32 millis(void);
BOOL get_w5500_int_flag(void);
void assert_w5500_reset(BOOL);

typedef enum {
    RFID1 = '1',
    RFID2 = '2'
} RFIDDevices;

typedef enum {
    BAL1 = '1',
    BAL2 = '2'
} BALDevices;

UINT16 GetLEDPort(void);
void SetLEDPort(UINT16 state);
BOOL SetSingleDout(int position, BOOL state, BOOL blink);

#endif	/* HAL_H */
