/*
 * File:   ui.h
 * Author: msuzer
 *
 * Created on 09.04.2014, 22:06
 */

#ifndef USER_INTERFACE_H
#define	USER_INTERFACE_H

#include "hal.h"

typedef enum {
    PRINT_SENSORS = 'A',
    PRINT_TEMPERATURE,
    PRINT_ALL_DOUTS,
    SET_SINGLE_DOUT,
    SET_ALL_DOUTS,
    RUN_PERISTATIC_PUMP,
    LOCK_EL_SENS,
    INS_PIC24FJ,
    INS_DSPIC33FJ,
    INS_BALANCERS,
    PRINT_BOARD_NET_CONFIG,
    SET_BOARD_IP,
    BOARD_LOOPBACK,
    PRINT_FW_VER
} UserInstructions;

typedef enum {
    SPECIAL_SIGN_UP_COUNT = '+',
    SPECIAL_SIGN_PRT_COUNTER = '?',
    SPECIAL_SIGN_RST_COUNTER = '!'
} SpecialSign;

#define     SERVICE_TIME_REMINDER   100000
#define     SPECIAL_SIGN_RST_PASS   "0123456789abcdef"

void restore_service_counter(void);
wiz_NetInfo* Get_Net_Info(void);
void CheckUpUserInstruction(void);
void CheckUpDeviceResponse(void);

#endif	/* USER_INTERFACE_H */
