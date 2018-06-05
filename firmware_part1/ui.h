/*
 * File:   ui.h
 * Author: msuzer
 *
 * Created on 09.04.2014, 22:06
 */

#ifndef USER_INTERFACE_H
#define	USER_INTERFACE_H

typedef enum {
    PRINT_SENSORS = 'A',
    TEST_SENSORS,
    EL_SENS,
    RUN_DC_MOTORS,
    INS_RFIDS,
    BOARD_LOOPBACK,
    PRINT_FW_VER
} UserInstructions;

typedef enum {
    ParkState = '0',
    State1 = '1',
    State2 = '2',
    State3 = '3'
} StateMachine;

void CheckUpUserInstruction(void);

#endif	/* USER_INTERFACE_H */
