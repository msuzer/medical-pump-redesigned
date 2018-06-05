#include "hal.h"

// PIC24EP512GP806 Configuration Bit Settings

// FGS
#pragma config GWRP = OFF               // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = OFF                // General Segment Code-Protect bit (General Segment Code protect is disabled)
#pragma config GSSK = OFF               // General Segment Key bits (General Segment Write Protection and Code Protection is Disabled)

// FOSCSEL
#pragma config FNOSC = FRC              // Initial Oscillator Source Selection bits (Internal Fast RC (FRC) Oscillator with postscaler)
#pragma config IESO = OFF                // Two-speed Oscillator Start-up Enable bit (Start up device with FRC, then switch to user-selected oscillator source)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Mode Select bits (XT Crystal Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function bit (OSC2 is clock output)
#pragma config IOL1WAY = ON            // Peripheral pin select configuration (Allow only one reconfiguration)
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Both Clock switching and Fail-safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler bit (1:128)
#pragma config PLLKEN = ON              // PLL Lock Wait Enable bit (Clock switch to PLL source will wait until the PLL lock signal is valid.)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable bit (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // Power-on Reset Timer Value Select bits (128ms)
#pragma config BOREN = OFF               // Brown-out Reset (BOR) Detection Enable bit (BOR is enabled)
#pragma config ALTI2C1 = OFF            // Alternate I2C pins for I2C1 (SDA1/SCK1 pins are selected as the I/O pins for I2C1)

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1)
#pragma config RSTPRI = PF              // Reset Target Vector Select bit (Device will obtain reset instruction from Primary flash)
#pragma config JTAGEN = OFF             // JTAG Enable bit (JTAG is disabled)

// FAS
#pragma config AWRP = OFF               // Auxiliary Segment Write-protect bit (Aux Flash may be written)
#pragma config APL = OFF                // Auxiliary Segment Code-protect bit (Aux Flash Code protect is disabled)
#pragma config APLK = OFF               // Auxiliary Segment Key bits (Aux Flash Write Protection and Code Protection is Disabled)

UINT16_VAL ExtSensorValues = {0};
UINT16_VAL BlinkMask = {0};

void OpenOC1inPWMMode(void);
void setup_timer2(void);
void setup_i2c(void);
void setup_uart(void);
void setup_spi(void);
void init_comparator(void);

void init_mcu_osc(void) {
    //_FOSCSEL(FNOSC_FRC & IESO_OFF); // Select Internal FRC at POR
    //_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT); // Enable Clock Switching and Configure POSC in XT mode

    // Configure PLL prescaler, PLL postscaler, PLL divisor
    // 8MHz XTALL * M / (N1 * N2) = 80MHz = 40MIPS
    CLKDIV = 0;
    PLLFBD = 38; // M = 40
    CLKDIVbits.PLLPOST = 0; // N2=2
    CLKDIVbits.PLLPRE = 0; // N1=2
    // Initiate Clock Switch to Primary Oscillator with PLL (NOSC=0b011)
    __builtin_write_OSCCONH(0x03);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur
    while (OSCCONbits.LOCK != 1); // Wait for PLL to lock
}

void init_mcu_core(void) {
    init_mcu_osc();

    I2C1CON = 0;
    I2C2CON = 0;
    PMCON = 0;

    SetMCUPinStates();
    SetAnalogPins();
    SetMCUPinDirections();
    SetMCUPinPullups();

    SetLED(ON);

    PPSUnLock;
    iPPSOutput(PIC24FJUARTTXPin, OUT_FN_PPS_U1TX); //Assign UART1 TX
    iPPSInput(IN_FN_PPS_U1RX, PIC24FJUARTRXPin); //Assign UART1 RX
    iPPSOutput(dsPICFJUARTTXPin, OUT_FN_PPS_U2TX); //Assign UART2 TX
    iPPSInput(IN_FN_PPS_U2RX, dsPICFJUARTRXPin); //Assign UART2 RX
    iPPSOutput(BAL1UARTTXPin, OUT_FN_PPS_U3TX); //Assign UART3 TX
    iPPSInput(IN_FN_PPS_U3RX, BAL1UARTRXPin); //Assign UART3 RX
    iPPSOutput(BAL2UARTTXPin, OUT_FN_PPS_U4TX); //Assign UART4 TX
    iPPSInput(IN_FN_PPS_U4RX, BAL2UARTRXPin); //Assign UART4 RX
    iPPSOutput(SPI1SCKPin, OUT_FN_PPS_SCK1); //Assign SPI1 SCK
    iPPSOutput(SPI1MOSIPin, OUT_FN_PPS_SDO1); //Assign SPI1 SDO
    iPPSInput(IN_FN_PPS_SDI1, SPI1MISOPin); //Assign SPI1 SDI
    iPPSOutput(PumpMotorSpeedPin, OUT_FN_PPS_OC1); //Assign OC1 to pin RP84 PumpSpeedControl
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
    //setup_i2c();
    OpenOC1inPWMMode();
    setup_uart();
    setup_spi();
    init_comparator();
}

void setup_timer2(void) {
    PMD1bits.T2MD = 0;
    __delay_us(5);

    T2CON = 0;
    T2CONbits.TCKPS = 0b11;
    TMR2 = 0;
    PR2 = TIMER2_PERIOD_VAL;
    IPC1bits.T2IP = 0b001;
    IFS0bits.T2IF = 0;
    IEC0bits.T2IE = 0;
    T2CONbits.TON = 1;
    //ConfigIntTimer2(T2_INT_ON & T2_INT_PRIORITY);
    //OpenTimer2(T2_ON & T2_IDLE_CON & T2_GATE_OFF & TIMER2_PRESCALER & T2_32BIT_MODE_OFF & T2_SOURCE_INT, TIMER2_PERIOD_VAL);
}

void setup_uart1(BOOL open) {
    if (open) {
        U1BRG = BAUD_RATE_19200; // Baud Rate setting
        U1MODE = 0;
        U1STA = 0;
        IEC0bits.U1RXIE = 1; // Enable UART RX interrupt
        U1MODEbits.RTSMD = 1; //simplex mode
        U1MODEbits.UARTEN = 1; //Enable UART
        U1STAbits.UTXEN = 1; // Enable UART TX (must be after module enable!)
    } else {
        U1MODE = 0;
        U1STA = 0;
        IEC0bits.U1RXIE = 0;
    }
}

void setup_uart2(BOOL open) {
    if (open) {
        U2BRG = BAUD_RATE_19200; // Baud Rate setting
        U2MODE = 0;
        U2STA = 0;
        IEC1bits.U2RXIE = 1; // Enable UART RX interrupt
        U2MODEbits.RTSMD = 1; //simplex mode
        U2MODEbits.UARTEN = 1; //Enable UART
        U2STAbits.UTXEN = 1; // Enable UART TX (must be after module enable!)
    } else {
        U2MODE = 0;
        U2STA = 0;
        IEC1bits.U2RXIE = 0;
    }
}

void setup_uart3(BOOL open) {
    if (open) {
        U3BRG = BAUD_RATE_19200; // Baud Rate setting
        U3MODE = 0;
        U3STA = 0;
        IEC5bits.U3RXIE = 1; // Enable UART RX interrupt
        U3MODEbits.RTSMD = 1; //simplex mode
        U3MODEbits.UARTEN = 1; //Enable UART
        U3STAbits.UTXEN = 1; // Enable UART TX (must be after module enable!)
    } else {
        U3MODE = 0;
        U3STA = 0;
        IEC5bits.U3RXIE = 0;
    }
}

void setup_uart4(BOOL open) {
    if (open) {
        U4BRG = BAUD_RATE_19200; // Baud Rate setting
        U4MODE = 0;
        U4STA = 0;
        IEC5bits.U4RXIE = 1; // Enable UART RX interrupt
        U4MODEbits.RTSMD = 1; //simplex mode
        U4MODEbits.UARTEN = 1; //Enable UART
        U4STAbits.UTXEN = 1; // Enable UART TX (must be after module enable!)
    } else {
        U4MODE = 0;
        U4STA = 0;
        IEC5bits.U4RXIE = 0;
    }
}

void setup_uart(void) {
    PMD1bits.U1MD = 0;
    PMD1bits.U2MD = 0;
    PMD3bits.U3MD = 0;
    PMD4bits.U4MD = 0;
    __delay_us(5);
    setup_uart1(TRUE);
    setup_uart2(TRUE);
    setup_uart3(TRUE);
    setup_uart4(TRUE);
}

void rs485_direction_control(BOOL transmitter) {
}

void setup_spi(void) {
    PMD1bits.SPI1MD = 0;
    __delay_us(5);
    /*
        OpenSPI1(ENABLE_SDO_PIN & ENABLE_SCK_PIN & SPI_MODE16_OFF &
                SPI_SMP_OFF & SPI_CKE_ON & SLAVE_ENABLE_OFF &
                CLK_POL_ACTIVE_HIGH & MASTER_ENABLE_ON &
                SEC_PRESCAL_1_1 & PRI_PRESCAL_4_1,
                FRAME_ENABLE_OFF & FIFO_BUFFER_DISABLE,
                SPI_ENABLE & SPI_IDLE_CON);
     */
    SPI1STAT = 0x0000;
    SPI1CON1 = 0x0000;
    SPI1CON2 = 0x0000;
    SPI1CON1bits.CKE = 1;
    SPI1CON1bits.MSTEN = 1;
    SPI1CON1bits.PPRE = 0b10; //4_1
    SPI1CON1bits.SPRE = 0b111; //1_1
    SPI1CON2bits.SPIBEN = 1;
    SPI1STATbits.SPIEN = 1;
}

BOOL spi_is_tx_busy(SPIChannel channel) {
    if (channel == SPI_CH1)
        return !SPI1STATbits.SRMPT;
    else if (channel == SPI_CH2)
        return !SPI2STATbits.SRMPT;
    else if (channel == SPI_CH3)
        return !SPI3STATbits.SRMPT;
    else
        return !SPI4STATbits.SRMPT;
}

UINT8 spi_loop(SPIChannel channel, UINT8 data) {
    UINT32 timeout = 1000000;
#ifdef SPI1BUF
    if (channel == SPI_CH1) {
        while (SPI1STATbits.SPITBF);
        SPI1BUF = data;
        while (SPI1STATbits.SRXMPT) {
            if (--timeout == 0) return 0;
        }
        return SPI1BUF & 0xFF;
    }
#endif
#ifdef SPI2BUF
    if (channel == SPI_CH2) {
        while (SPI2STATbits.SPITBF);
        SPI2BUF = data;
        while (SPI2STATbits.SRXMPT) {
            if (--timeout == 0) return 0;
        }
        return SPI2BUF & 0xFF;
    }
#endif
#ifdef SPI3BUF
    if (channel == SPI_CH3) {
        while (SPI3STATbits.SPITBF);
        SPI3BUF = data;
        while (SPI3STATbits.SRXMPT) {
            if (--timeout == 0) return 0;
        }
        return SPI3BUF & 0xFF;
    }
#endif
#ifdef SPI4BUF
    if (channel == SPI_CH4) {
        while (SPI4STATbits.SPITBF);
        SPI4BUF = data;
        while (SPI4STATbits.SRXMPT) {
            if (--timeout == 0) return 0;
        }
        return SPI4BUF & 0xFF;
    }
#endif
    return 0;
}

void spi_assert_cs(SPIChannel channel, BOOL assert) {
    if (channel == SPI_CH1)
        SPI1AssertCS(assert);
    else if (channel == SPI_CH2)
        SPI1AssertCS(assert); //SPI2AssertCS not defined in this project!
}

BOOL get_w5500_int_flag(void) {
    return W5500Ready();
}

void assert_w5500_reset(BOOL assert) {
    W5500RESET(assert);
}

void run_peristaltic_motor(INT16 speed) {
    if (speed <= 0) {
        SetPumpMotorDir(CCW);
        speed = -speed;
    } else {
        SetPumpMotorDir(CW);
    }

    if (speed > OC1_PWM_DUTY_CYCLE)
        speed = OC1_PWM_DUTY_CYCLE;
    SetOC1PWMDutyCycle(speed);
}

void OpenOC1inPWMMode(void) {
    PMD2bits.OC1MD = 0;
    __delay_us(5);

    OC1CON1 = 0;
    OC1CON2 = 0;
    OC1CON1bits.OCTSEL = 0x07; //select the peripheral clock as the clock input
    SetOC1PWMDutyCycle(0); //DutyCycle set to 0 initially to stop the pump motor
    OC1RS = OC1_PWM_PERIOD;
    OC1CON2bits.SYNCSEL = 0x1F; //select the synchronization source as itself
    OC1CON1bits.OCM = 6; //select and start the Edge Aligned PWM mode
}

void setup_i2c(void) {
    /* Configure I2C for 7 bit address mode */
    PMD1bits.I2C1MD = 0;
    __delay_us(5);

    /*    MCP9804SCLPin = HIGH;
        MCP9804SDAPin = HIGH;
        OpenI2C1(I2C1_ON & I2C1_IDLE_CON & I2C1_CLK_HLD &
                I2C1_IPMI_DIS & I2C1_7BIT_ADD &
                I2C1_SLW_DIS & I2C1_SM_DIS &
                I2C1_GCALL_DIS & I2C1_STR_DIS &
                I2C1_NACK & I2C1_ACK_DIS & I2C1_RCV_DIS &
                I2C1_STOP_DIS & I2C1_RESTART_DIS &
                I2C1_START_DIS, 0x34); // Baud rate is set for 400 kHz
        IdleI2C1();
     */
    i2c_init();
}

void init_comparator(void) {
    PMD3bits.CMPMD = 0;
    __delay_us(5);
    CMSTAT = 0;
    CM3CON = 0;
    CM3MSKSRC = 0;
    CM3MSKCON = 0;
    CM3FLTR = 0;
    CVRCON = 0;

    CVRCONbits.BGSEL = 0b00; //2.20V
    //CVRCONbits.BGSEL = 0b01; //0.60V
    //CVRCONbits.BGSEL = 0b10; //0.20V
    CVRCONbits.CVREN = 1;

    //CM3CONbits.EVPOL = 0b10; Event on H->L
    // Check and Clear Event w/ CM3CONbits.CEVT
    // or check only w/ CMSTATbits.C3EVT
    CM3CONbits.CCH = 0b11;
    CM3CONbits.CREF = 0;
    CM3CONbits.CON = 1;
}

UINT16_VAL GetSensors(void) {
    return ExtSensorValues;
}

void read_sensors(void) {
    static unsigned int kbCount0 = 0;
    static unsigned int kbCount1 = 0;
    static unsigned int kbCount2 = 0;
    static unsigned int kbCount3 = 0;

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
            }
    } else {
        kbCount1 = 0;
        ExtSensorValues.bits.b1 = 0;
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
}

void blink_led(void) {
    static unsigned int timeCtr = 0;

    if (++timeCtr == 50) {
        ToggleLED();
        SetLEDPort(GetLEDPort() ^ BlinkMask.Val);
        timeCtr = 0;
    }
}

UINT16 GetLEDPort(void) {
    UINT16_VAL state = {0};

    state.bits.b0 = LED0Pin;
    state.bits.b1 = LED1Pin;
    state.bits.b2 = LED2Pin;
    state.bits.b3 = LED3Pin;
    state.bits.b4 = LED4Pin;
    state.bits.b5 = LED5Pin;
    state.bits.b6 = LED6Pin;

    return state.Val;
}

void SetLEDPort(UINT16 state) {
    UINT16_VAL st = {state};
    LED0Pin = st.bits.b0;
    LED1Pin = st.bits.b1;
    LED2Pin = st.bits.b2;
    LED3Pin = st.bits.b3;
    LED4Pin = st.bits.b4;
    LED5Pin = st.bits.b5;
    LED6Pin = st.bits.b6;
}

BOOL SetSingleDout(int position, BOOL state, BOOL blink) {
    switch (position) {
        case 0:
            LED0Pin = state;
            BlinkMask.bits.b0 = blink;
            break;
        case 1:
            LED1Pin = state;
            BlinkMask.bits.b1 = blink;
            break;
        case 2:
            LED2Pin = state;
            BlinkMask.bits.b2 = blink;
            break;
        case 3:
            LED3Pin = state;
            BlinkMask.bits.b3 = blink;
            break;
        case 4:
            LED4Pin = state;
            BlinkMask.bits.b4 = blink;
            break;
        case 5:
            LED5Pin = state;
            BlinkMask.bits.b5 = blink;
            break;
        case 6:
            LED6Pin = state;
            BlinkMask.bits.b6 = blink;
            break;
        default:
            return FALSE;
    }
    return TRUE;
}
