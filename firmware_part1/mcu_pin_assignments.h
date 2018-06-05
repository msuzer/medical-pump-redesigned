#ifndef MCU_PIN_ASSIGNMENTS_H
#define	MCU_PIN_ASSIGNMENTS_H

#define DCMotor0SideAPin        _LATA0
#define DCMotor0SideBPin        _LATA1
#define DCMotor1SideAPin        _LATB12 //RP12
#define DCMotor1SideBPin        _LATB13 //RP13
#define DCMotor2SideAPin        _LATA10
#define DCMotor2SideBPin        _LATB11 //RP11
#define DCMotor3SideAPin        _LATB10 //RP10
#define DCMotor3SideBPin        _LATB5 //RP5
#define DCMotor4SideAPin        _LATA7
#define DCMotor4SideBPin        _LATC5 //RP21
#define DCMotor5SideAPin        _LATC4 //RP20
#define DCMotor5SideBPin        _LATC3 //RP19
#define DCMotor6SideAPin        _LATA9
#define DCMotor6SideBPin        _LATC2 //RP18
#define DCMotor7SideAPin        _LATC1 //RP17
#define DCMotor7SideBPin        _LATA8

#define Sens0BPin               _RB7 // CN23, Digital Input
#define Sens1BPin               _RB6 // CN24, Digital Input
#define Sens2BPin               _RB8 // CN22, Digital Input
#define Sens3BPin               _RB9 // CN21, Digital Input

#define Sens0CPin               _RB1 // CN5, Digital Input
#define Sens1CPin               _RB2 // CN6, Digital Input
#define Sens2CPin               _RB3 // CN7, Digital Input
#define Sens3CPin               _RC0 // CN8, Digital Input
//#define Sens4CPin               _RC1 // CN9, Digital Input
//#define Sens5CPin               _RC2 // CN10, Digital Input
#define Sens4CPin               _RA4 // CN0, Digital Input
#define Sens5CPin               _RB4 // CN1, Digital Input

// UART1 connects to PIC24EP
#define UART1TXPin              OUT_PIN_PPS_RP14 // RB14
#define UART1RXPin              IN_PIN_PPS_RP15 // RB15 Digital Input

#define RFID1UARTTXPin          OUT_PIN_PPS_RP24 // RC8
#define RFID1UARTRXPin          IN_PIN_PPS_RP25 // RC9 Digital Input

#define RFID2UARTTXPin          OUT_PIN_PPS_RP23 // RC7
#define RFID2UARTRXPin          IN_PIN_PPS_RP22 // RC6 Digital Input

#define SetMCUPinDirections()   { TRISA = 0x0010; TRISB = 0x83CE; TRISC = 0x0247; }
#define SetMCUPinPullups()      { CNPU1 = 0; CNPU2 = 0; _CN5PUE = 1; _CN6PUE = 1; \
                                _CN7PUE = 1; _CN8PUE = 1; _CN0PUE = 1; _CN1PUE = 1; \
                                _CN21PUE = 1; _CN22PUE = 1; _CN23PUE = 1; _CN24PUE = 1; }

#define SetAnalogPins()         { ANSA = 0; ANSB = 0; ANSC = 0; }

#define IsSens0Active()         !Sens0BPin
#define IsSens1Active()         !Sens1BPin
#define IsSens2Active()         !Sens2BPin
#define IsSens3Active()         !Sens3BPin
#define IsSens4Active()         !Sens0CPin
#define IsSens5Active()         !Sens1CPin
#define IsSens6Active()         !Sens2CPin
#define IsSens7Active()         !Sens3CPin
#define IsSens8Active()         !Sens4CPin
#define IsSens9Active()         !Sens5CPin

#endif
