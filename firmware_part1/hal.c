#include "hal.h"

// PIC24FJ128GA204 Configuration Bit Settings
// CONFIG4
#pragma config DSWDTPS = DSWDTPSA       // Deep Sleep Watchdog Timer Postscale Select bits (1:32768 (1.057 Secs))
#pragma config DSWDTOSC = SOSC          // DSWDT Reference Clock Select (DSWDT uses SOSC as reference clock)
#pragma config DSBOREN = ON             // Deep Sleep BOR Enable bit (DSBOR Enabled)
#pragma config DSWDTEN = OFF            // Deep Sleep Watchdog Timer Enable (DSWDT Disabled)
#pragma config DSSWEN = OFF             // DSEN Bit Enable (Deep Sleep operation is always disabled)
#pragma config PLLDIV = PLL4X           // USB 96 MHz PLL Prescaler Select bits (4x PLL selected)
#pragma config I2C1SEL = DISABLE        // Alternate I2C1 enable bit (I2C1 uses SCL1 and SDA1 pins)
//#pragma config IOL1WAY = ON             // PPS IOLOCK Set Only Once Enable bit (Once set, the IOLOCK bit cannot be cleared)
#pragma config IOL1WAY = OFF            // PPS IOLOCK Set Only Once Enable bit (The IOLOCK bit can be set and cleared using the unlock sequence)

// CONFIG3
#pragma config WPFP = WPFP127           // Write Protection Flash Page Segment Boundary (Page 127 (0x1FC00))
#pragma config SOSCSEL = ON             // SOSC Selection bits (SOSC circuit selected)
#pragma config WDTWIN = PS75_0          // Window Mode Watchdog Timer Window Width Select (Watch Dog Timer Window Width is 75 percent)
#pragma config PLLSS = PLL_PRI          // PLL Secondary Selection Configuration bit (PLL is fed by the Primary oscillator)
#pragma config BOREN = ON               // Brown-out Reset Enable (Brown-out Reset Enable)
#pragma config WPDIS = WPDIS            // Segment Write Protection Disable (Disabled)
#pragma config WPCFG = WPCFGDIS         // Write Protect Configuration Page Select (Disabled)
#pragma config WPEND = WPSTARTMEM       // Segment Write Protection End Page Select (Write Protect from page 0 to WPFP)

// CONFIG2
#pragma config POSCMD = XT              // Primary Oscillator Select (HS Oscillator Enabled)
#pragma config WDTCLK = SOSC            // WDT Clock Source Select bits (WDT uses SOSC input)
#pragma config OSCIOFCN = OFF           // OSCO Pin Configuration (OSCO/CLKO/RA3 functions as port I/O (RA3))
#pragma config FCKSM = CSDCMD           // Clock Switching and Fail-Safe Clock Monitor Configuration bits (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = FRCPLL           // Initial Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))
#pragma config ALTCMPI = CxINC_RX       // Alternate Comparator Input bit (C1INC, C2INC and C3INC are on RB9)
#pragma config WDTCMX = WDTCLK          // WDT Clock Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits)
#pragma config IESO = OFF               // Internal External Switchover (Disabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler Select (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler Ratio Select (1:128)
#pragma config WINDIS = OFF             // Windowed WDT Disable (Standard Watchdog Timer)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT disabled in hardware; SWDTEN bit disabled)
#pragma config ICS = PGx1               // Emulator Pin Placement Select bits (Emulator functions are shared with PGEC1/PGED1)
#pragma config LPCFG = OFF              // Low power regulator control (Disabled - regardless of RETEN)
#pragma config GWRP = ON                // General Segment Write Protect (Write to program memory not allowed)
#pragma config GCP = ON                 // General Segment Code Protect (Code protection is enabled)
#pragma config JTAGEN = OFF             // JTAG Port Enable (Disabled)

UINT16_VAL ExtSensorValues = {0};

void setup_timer2(void);
void OpenOC1inPWMMode(void);
void setup_uart(void);

void init_mcu_osc(void) {
    // CF no clock failure; NOSC PRIPLL; SOSCEN enabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active;
    __builtin_write_OSCCONL((UINT8) (0x0302 & 0x00FF));
    //PwrMgnt_ClkDiv_Sel(PERI_CLK_RATIO_SET_1 | PLL_ENABLE);
    // PLLEN enabled; RCDIV FRC/1; DOZE 1:8; DOZEN disabled; ROI disabled;
    CLKDIV = 0x3020;
    // STOR disabled; STORPOL Interrupt when STOR is 1; STSIDL disabled; STLPOL Interrupt when STLOCK is 1; STLOCK disabled; STSRC SOSC; STEN disabled; TUN Center frequency;
    OSCTUN = 0x0000;
    // ROEN disabled; ROSEL FOSC; ROSIDL disabled; ROSWEN disabled; ROOUT disabled; ROSLP disabled;
    REFOCONL = 0x0000;
    // RODIV 0;
    REFOCONH = 0x0000;
    // ROTRIM 0;
    REFOTRIML = 0x0000;
    // WDTO disabled; TRAPR disabled; SLEEP disabled; BOR disabled; DPSLP disabled; CM disabled; SWR disabled; SWDTEN disabled; EXTR disabled; POR disabled; IDLE disabled; IOPUWR disabled; VREGS disabled;
    RCON = 0x0000;
}

void init_mcu_core(void) {
    //init_mcu_osc();

    PwrMgnt_ClkDiv_Sel(PERI_CLK_RATIO_SET_1 | PLL_ENABLE);
    LATA = 0;
    LATB = 0;
    LATC = 0;

    SetAnalogPins();
    SetMCUPinDirections();
    SetMCUPinPullups();

    PMCON1 = 0;

    PPSUnLock; //RP6 is not working !
    iPPSInput(IN_FN_PPS_U1RX, UART1RXPin); //Assign U1RX
    iPPSOutput(UART1TXPin, OUT_FN_PPS_U1TX); //Assign U1TX
    iPPSOutput(RFID1UARTTXPin, OUT_FN_PPS_U2TX); //Assign UART2 TX
    iPPSInput(IN_FN_PPS_U2RX, RFID1UARTRXPin); //Assign UART2 RX
    iPPSOutput(RFID2UARTTXPin, OUT_FN_PPS_U3TX); //Assign UART3 TX
    iPPSInput(IN_FN_PPS_U3RX, RFID2UARTRXPin); //Assign UART3 RX
    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_OC1); //
    PPSLock;

    PMD1 = 0xFFFF;
    PMD2 = 0xFFFF;
    PMD3 = 0xFFFF;
    PMD4 = 0xFFFF;
    PMD6 = 0xFFFF;
    PMD7 = 0xFFFF;
}

void init_peripherals(void) {
    setup_timer2();
    OpenOC1inPWMMode();
    setup_uart();
}

void setup_timer2(void) {
    PMD1bits.T2MD = 0;
    __delay_us(5);
    CloseTimer2();
    ConfigIntTimer2(T2_INT_OFF | T2_INT_PRIORITY);
    OpenTimer2(T2_ON | TIMER2_PRESCALER, TIMER2_PERIOD_VAL);
}

void setup_uart(void) {
    PMD1bits.U1MD = 0;
    PMD1bits.U2MD = 0;
    PMD3bits.U3MD = 0;
    __delay_us(5);
    CloseUART1();
    CloseUART2();
    CloseUART3();

    ConfigIntUART1(UART_RX_INT_EN | UART_RX_INT_PR2);
    OpenUART1(UART_EN, UART_TX_ENABLE | UART_RX_ENABLE, BAUD_RATE_19200);

    ConfigIntUART2(UART_RX_INT_EN | UART_RX_INT_PR2);
    OpenUART2(UART_EN, UART_TX_ENABLE | UART_RX_ENABLE, BAUD_RATE_19200);

    ConfigIntUART3(UART_RX_INT_EN | UART_RX_INT_PR2);
    OpenUART3(UART_EN, UART_TX_ENABLE | UART_RX_ENABLE, BAUD_RATE_19200);
}

void rs485_direction_control(BOOL transmitter) {
}

UINT16_VAL GetSensors(void) {
    return ExtSensorValues;
}

void read_sensors(void) {
    static unsigned int kbCount0 = 0;
    static unsigned int kbCount1 = 0;
    static unsigned int kbCount2 = 0;
    static unsigned int kbCount3 = 0;
    static unsigned int kbCount4 = 0;
    static unsigned int kbCount5 = 0;
    static unsigned int kbCount6 = 0;
    static unsigned int kbCount7 = 0;
    static unsigned int kbCount8 = 0;
    static unsigned int kbCount9 = 0;

    if (IsSens0Active()) {
        if (!ExtSensorValues.bits.b0)
            if (++kbCount0 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b0 = 1;
            }
    } else {
        kbCount0 = 0;
        ExtSensorValues.bits.b0 = 0;
    }

    if (IsSens1Active()) {
        if (!ExtSensorValues.bits.b1)
            if (++kbCount1 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b1 = 1;
                COMPort.println(COM1, "L310"); //Light LED3
            }
    } else {
        kbCount1 = 0;
        if (ExtSensorValues.bits.b1) {
            COMPort.println(COM1, "L311"); //Flash LED3
            ExtSensorValues.bits.b1 = 0;
        }
    }

    if (IsSens2Active()) {
        if (!ExtSensorValues.bits.b2)
            if (++kbCount2 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b2 = 1;
            }
    } else {
        kbCount2 = 0;
        ExtSensorValues.bits.b2 = 0;
    }

    if (IsSens3Active()) {
        if (!ExtSensorValues.bits.b3)
            if (++kbCount3 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b3 = 1;
            }
    } else {
        kbCount3 = 0;
        ExtSensorValues.bits.b3 = 0;
    }

    if (IsSens4Active()) {
        if (!ExtSensorValues.bits.b4)
            if (++kbCount4 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b4 = 1;
            }
    } else {
        kbCount4 = 0;
        ExtSensorValues.bits.b4 = 0;
    }

    if (IsSens5Active()) {
        if (!ExtSensorValues.bits.b5)
            if (++kbCount5 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b5 = 1;
            }
    } else {
        kbCount5 = 0;
        ExtSensorValues.bits.b5 = 0;
    }

    if (IsSens6Active()) {
        if (!ExtSensorValues.bits.b6)
            if (++kbCount6 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b6 = 1;
            }
    } else {
        kbCount6 = 0;
        ExtSensorValues.bits.b6 = 0;
    }

    if (IsSens7Active()) {
        if (!ExtSensorValues.bits.b7)
            if (++kbCount7 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b7 = 1;
            }
    } else {
        kbCount7 = 0;
        ExtSensorValues.bits.b7 = 0;
    }

    if (IsSens8Active()) {
        if (!ExtSensorValues.bits.b8)
            if (++kbCount8 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b8 = 1;
            }
    } else {
        kbCount8 = 0;
        ExtSensorValues.bits.b8 = 0;
    }

    if (IsSens9Active()) {
        if (!ExtSensorValues.bits.b9)
            if (++kbCount9 > SWITCH_DEBOUNCE) {
                ExtSensorValues.bits.b9 = 1;
            }
    } else {
        kbCount9 = 0;
        ExtSensorValues.bits.b9 = 0;
    }
}

#ifdef SetLED

void blink_led(void) {
    static unsigned int timeCtr = 0;

    if (++timeCtr == 1)
        SetLED(ON);
    else if (timeCtr == 10)
        SetLED(OFF);
    else if (timeCtr > 100)
        timeCtr = 0;
}
#endif

void OpenOC1inPWMMode(void) {
    PMD2bits.OC1MD = 0;
    __delay_us(5);

    OC1CON1 = 0;
    OC1CON2 = 0;
    OC1CON1bits.OCTSEL = 0x07; //select the peripheral clock as the clock input
    OC1R = 0; //DutyCycle
    OC1RS = DC_MOTOR_PWM_PERIOD;
    OC1CON2bits.SYNCSEL = 0x1F; //select the synchronization source as itself
    OC1CON1bits.OCM = 6; //select and start the Edge Aligned PWM mode
}

void RunDCMotors(DCMotors motor, BOOL dir, BOOL state, UINT16 dc) {
    BOOL cw = dir && state;
    BOOL ccw = !dir && state;

    if (!state)
        dc = 0;
    else if (dc > DC_MOTOR_PWM_PERIOD)
        dc = DC_MOTOR_PWM_PERIOD;

    OC1R = dc;
    OC1CON2bits.OCINV = cw;

    switch (motor) {
        case DCMotor0:
            DCMotor0SideAPin = cw;
            DCMotor0SideBPin = ccw;
            break;
        case DCMotor1:
            DCMotor1SideAPin = cw;
            DCMotor1SideBPin = ccw;
            break;
        case DCMotor2:
            if (state) {
                if (OUT_PIN_PPS_RP11 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor2SideAPin = cw;
            DCMotor2SideBPin = ccw;
            break;
        case DCMotor3:
            if (state) {
                if (OUT_PIN_PPS_RP5 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor3SideAPin = cw;
            DCMotor3SideBPin = ccw;
            break;
        case DCMotor4:
            if (state) {
                if (OUT_PIN_PPS_RP21 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor4SideAPin = cw;
            DCMotor4SideBPin = ccw;
            break;
        case DCMotor5:
            if (state) {
                if (OUT_PIN_PPS_RP19 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor5SideAPin = cw;
            DCMotor5SideBPin = ccw;
            break;
        case DCMotor6:
            if (state) {
                if (OUT_PIN_PPS_RP18 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor6SideAPin = cw;
            DCMotor6SideBPin = ccw;
            break;
        case DCMotor7:
            if (state) {
                if (OUT_PIN_PPS_RP17 != OUT_FN_PPS_OC1) {
                    PPSUnLock;
                    iPPSOutput(OUT_PIN_PPS_RP5, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP11, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP18, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP19, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP21, OUT_FN_PPS_NULL);
                    iPPSOutput(OUT_PIN_PPS_RP17, OUT_FN_PPS_OC1);
                    PPSLock;
                }
            }
            DCMotor7SideAPin = cw;
            DCMotor7SideBPin = ccw;
            break;
    }
}
