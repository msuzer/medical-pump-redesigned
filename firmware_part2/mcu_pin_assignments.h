#ifndef MCU_PIN_ASSIGNMENTS_H
#define	MCU_PIN_ASSIGNMENTS_H

#ifndef IN_PIN_PPS_RP23
#define IN_PIN_PPS_RP23     23
#endif

#define Stepper1DIRPin          _LATA8
#define Stepper1RSTPin          _LATB4
#define Stepper1CLKPin          _LATB12 //PWM1H2
#define Stepper1FLGPin          !_RA4 //CN0 Digital Input
#define Stepper1CSPin           _LATA9

// SPI2 connects to L6474 of Stepper1
#define SPI1MOSIPin             OUT_PIN_PPS_RP19 // RC3
#define SPI1SCKPin              OUT_PIN_PPS_RP20 // RC4
#define SPI1MISOPin             IN_PIN_PPS_RP21  // RC5 Digital Input

// QEI1 connects to encoder of Stepper1
#define QEI1CHAPin              IN_PIN_PPS_RP8 // CN22, RB8 Digital Input
#define QEI1CHBPin              IN_PIN_PPS_RP7 // CN23, RB7 Digital Input

#define Stepper2DIRPin          _LATA10
#define Stepper2RSTPin          _LATA7
#define Stepper2STCKPin         _LATB14 //PWM1H1
//#define Stepper2STCKPin         _LATC7 //PWM2L1
#define Stepper2FLGPin          !_RC2 //CN10 Digital Input
#define Stepper2CSPin           _LATC1

// SPI1 connects to L6474 of Stepper2
#define SPI2MOSIPin             OUT_PIN_PPS_RP2 // RB2
#define SPI2SCKPin              OUT_PIN_PPS_RP3 // RB3
#define SPI2MISOPin             IN_PIN_PPS_RP16 // RC0 Digital Input

// QEI2 connects to encoder of Stepper2
#define QEI2CHAPin              IN_PIN_PPS_RP24 // CN20, RC8  Digital Input
#define QEI2CHBPin              IN_PIN_PPS_RP10 // CN16, RB10 Digital Input

#define Sens0DPin               _RA1 // CN3, Digital Input
#define Sens1DPin               _RB6 // CN24, Digital Input
#define Sens2DPin               _RB5 // CN27, Digital Input

#define Sens0EPin               _RB13 // CN13, Digital Input
#define Sens1EPin               _RB11 // CN15, Digital Input
#define Sens2EPin               _RA0 // CN2, Digital Input

#define MainVoltageSensPin      _RB15 // CN11, Digital Input

// UART1 connects to PIC24EP
#define UART1TXPin              OUT_PIN_PPS_RP22 // RC6
#define UART1RXPin              IN_PIN_PPS_RP9 // RB9 Digital Input

#define SetMCUPinDirections()   { TRISA = 0b0000000000010011; TRISB = 0b1010111111100100; TRISC = 0b0000000101100100; }
#define SetMCUPinPullups()      { CNPU1 = 0; CNPU2 = 0; _CN0PUE = 1; _CN2PUE = 1; \
                                _CN3PUE = 1; _CN10PUE = 1; _CN13PUE = 1; _CN15PUE = 1;  \
                                _CN16PUE = 1; _CN20PUE = 1; _CN22PUE = 1; _CN23PUE = 1; \
                                _CN24PUE = 1; _CN27PUE = 1;}
#define SetAnalogPins()         { AD1PCFGL = 0xFFFF; }

#define IsSens0Active()         !Sens0DPin // Step1 Enjektor On Limit Switch
#define IsSens1Active()         !Sens1DPin // Step1 Enjektor Arka Limit Switch
#define IsSens2Active()         !Sens2DPin // Pasif
#define IsSens3Active()         !Sens0EPin // Step2 Enjektor On Limit Switch
#define IsSens4Active()         !Sens1EPin // Step2 Enjektor Arka Limit Switch
#define IsSens5Active()         !Sens2EPin // Pasif

#define SPI1AssertCS(state)     Stepper1CSPin = state
#define SPI2AssertCS(state)     Stepper2CSPin = state
#endif
