#ifndef MCU_PIN_ASSIGNMENTS_H
#define	MCU_PIN_ASSIGNMENTS_H

#define PIC24FJUARTTXPin        OUT_PIN_PPS_RP67 //RD3
#define PIC24FJUARTRXPin        IN_PIN_PPS_RP68 // RD4 Digital Input

#define dsPICFJUARTTXPin        OUT_PIN_PPS_RP98 //RF2
#define dsPICFJUARTRXPin        IN_PIN_PPS_RP99 // RF3 Digital Input

#define BAL1UARTTXPin           OUT_PIN_PPS_RP64 // RD0
#define BAL1UARTRXPin           IN_PIN_PPS_RPI74 // RD10 Digital Input

#define BAL2UARTTXPin           OUT_PIN_PPS_RP102 // RF6
#define BAL2UARTRXPin           IN_PIN_PPS_RPI75 // RD11 Digital Input

// SPI1 connects to W5500
#define SPI1MOSIPin             OUT_PIN_PPS_RP100 // RF4
#define SPI1MISOPin             IN_PIN_PPS_RPI47 // RB15 Digital Input
#define SPI1SCKPin              OUT_PIN_PPS_RP101 // RF5

#define W5500RSTPin             _LATB4
#define W5500INTPin             _RB5 // Digital Input
#define W5500CSPin              _LATE6

#define PumpMotorDirPin         _LATG6
#define PumpMotorSpeedPin       OUT_PIN_PPS_RP87 //RE7

#define Sens0Pin                _RB3 // Digital Input
#define Sens1Pin                _RB2 // Digital Input
#define Sens2Pin         		_RB1 // Digital Input
#define Sens3Pin         		_RB0 // Digital Input

#define BatteryVoltagePin  		_RD7 // C3IN1+ Digital Input

#define LED0Pin         		_LATB8
#define LED1Pin        			_LATB9
#define LED2Pin         		_LATB10
#define LED3Pin         		_LATB11
#define LED4Pin         		_LATB12
#define LED5Pin         		_LATB13
#define LED6Pin         		_LATB14

#define LED7Pin                 _LATE3

#define SetMCUPinStates()       { LATB = 0; LATC = 0; LATD = 0; LATE = 0; LATF = 0; LATG = 0x000C; }
#define SetAnalogPins()         {ANSELB = 0; ANSELC = 0; ANSELD = 0; ANSELE = 0; ANSELG = 0;}
#define SetMCUPinDirections()   { TRISB = 0x802F; TRISC = 0; TRISD = 0x0C90; TRISE = 0; TRISF = 0x0008; TRISG = 0; }
#define SetMCUPinPullups()      { CNPUB = 0; CNPUC = 0; CNPUD = 0; CNPUE = 0; CNPUF = 0; CNPUG = 0; \
                                  _CNPUB0 = 1; _CNPUB1 = 1; _CNPUB2 = 1; _CNPUB3 = 1; _CNPUB5 = 1; \
                                  _CNPUG2 = 1; _CNPUG3 = 1; }

#define IsSens0Active()         !Sens0Pin
#define IsSens1Active()         !Sens1Pin
#define IsSens2Active()         !Sens2Pin //El Sens
#define IsSens3Active()         !Sens3Pin

#define SPI1AssertCS(state)     W5500CSPin = state
#define W5500RESET(state)       W5500RSTPin = state
#define W5500Ready()            W5500INTPin

#define SetPumpMotorDir(state)  PumpMotorDirPin = state

#define SetLED(state)           LED7Pin = state
#define GetLED()                LED7Pin
#define ToggleLED()             SetLED(!GetLED())

#endif
