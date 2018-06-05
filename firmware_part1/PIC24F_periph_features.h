#ifndef __PIC24F_PERIPH_FEATURES_H
#define __PIC24F_PERIPH_FEATURES_H


/******************************************************************************
 *                  PERIPHERAL SELECT HEADER FILE
 ******************************************************************************
 * FileName:        pic24f_periph_features.h
 * Dependencies:    See include below
 * Processor:       PIC24
 * Compiler:        MPLAB C30
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PICmicro® Microcontroller is intended and
 * supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PICmicro Microcontroller products. The
 * software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *****************************************************************************/

#include <p24Fxxxx.h>
//#include <GenericTypeDefs.h>

/* By default, configuration constants are assembled from macros */
/* using the bit-wise AND operator (&). An alternate mode is */
/* available in which constants are assembled using the bit-wise */
/* OR operator (|) to set values and bit-wise AND (&) masks to */
/* clear values. To enable the alternate mode, define the */
/* USE_AND_OR symbol. */
/* */
/* To define this macro as a compiler option: */
/* -DUSE_AND_OR */
/* To define this macro in source code: */
/* #define USE_AND_OR */

#ifdef   __PIC24FJ128GA204__
/*############################################################*/
/*          Configuration for device =  'PIC24FJ128GA204'       */
/*############################################################*/

/* ADC */
#define adc_v5_2

/* CMP */
//#define cmp_v2_10

/* CN */
#define cn_v3_8 //confirmed

/* CTMU */
//#define ctmu_v3_3

/* INTERRUPT */
#define int_v1_2 //confirmed

/* INCAP */
/*No configuration chosen for this peripheral*/

/* I2C */
//#define i2c_v3_2

/* SPI */
//#define spi_v2_2

/* OUTCMP */
#define ocmp_v2_3 //confirmed

/* IOPORT */
#define port_v1_2 //confirmed

/* PWRMGNT */
#define pwrmgnt_v3_2

/* TIMERS */
#define tmr_v1_5 //confirmed

/* UART */
#define uart_v1_2 //confirmed

/* PMP */
/*No configuration chosen for this peripheral*/

/* pps */
#define pps_v1_7 //confirmed

/* CRC */
/*No configuration chosen for this peripheral*/

/* RTCC */
//#define rtcc_v1_2

/* WDT */
//#define wdt_v1_1

/* DPSLP */
/*No configuration chosen for this peripheral*/

/* SRAM */
/*No configuration chosen for this peripheral*/

/* DMA */
/*No configuration chosen for this peripheral*/

/* PWM */
/*No configuration chosen for this peripheral*/

/* DAC */
/*No configuration chosen for this peripheral*/

/* MCCP */
/*No configuration chosen for this peripheral*/

/* SCCP */
/*No configuration chosen for this peripheral*/

#endif

#endif /*__PIC24F_PERIPH_FEATURES_H*/
