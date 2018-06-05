#include "hal.h"

// DSPIC33FJ32GP304 Configuration Bit Settings

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)

// FGS
#pragma config GWRP = ON                // General Code Segment Write Protect (User program memory is write-protected)
#pragma config GSS = ON                 // General Segment Code Protection (Standard Security Code Protection is Enabled)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Primary Oscillator (XT, HS, EC) w/ PLL)
#pragma config IESO = OFF               // Internal External Switch Over Mode (Start-up device with FRC, then automatically switch to user-selected oscillator source when ready)

// FOSC
#pragma config POSCMD = XT              // Primary Oscillator Source (HS Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow Only One Re-configuration)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config ALTI2C = OFF             // Alternate I2C  pins (I2C mapped to SDA1/SCL1 pins)
#pragma config LPOL = ON                // Motor Control PWM Low Side Polarity bit (PWM module low side output pins have active-high output polarity)
#pragma config HPOL = ON                // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-high output polarity)
#pragma config PWMPIN = ON              // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PORT register at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)


UINT16_VAL ExtSensorValues = {0};

void setup_timer2(void);
void setup_spi(void);
void setup_uart(void);
void setup_qei(void);
void setup_pwm(void);

void init_mcu_osc(void) {
    //_FOSCSEL(FNOSC_FRC & IESO_OFF); // Select Internal FRC at POR
    //_FOSC(FCKSM_CSECMD & OSCIOFNC_OFF & POSCMD_XT); // Enable Clock Switching and Configure POSC in XT mode

    // Configure PLL prescaler, PLL postscaler, PLL divisor
    // 8MHz XTALL * M / (N1 * N2) = 32MHz = 16MIPS
    // 8MHz XTALL * M / (N1 * N2) = 80MHz = 40MIPS
    CLKDIV = 0;
    PLLFBD = 14; // M = 16
    //PLLFBD = 38; // M = 40
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

    LATA = 0;
    LATB = 0;
    LATC = 0;

    SetAnalogPins();
    SetMCUPinDirections();
    SetMCUPinPullups();

    PMCON = 0;
    PWM2CON1 = 0;
    P2TCON = 0;

    PPSUnLock;
    iPPSOutput(SPI1SCKPin, OUT_FN_PPS_SCK1); //Assign SPI1 SCK
    iPPSOutput(SPI1MOSIPin, OUT_FN_PPS_SDO1); //Assign SPI1 SDO
    iPPSInput(IN_FN_PPS_SDI1, SPI1MISOPin); //Assign SPI1 SDI

    iPPSInput(IN_FN_PPS_QEA1, QEI1CHAPin); //Assign QEA1
    iPPSInput(IN_FN_PPS_QEB1, QEI1CHBPin); //Assign QEB1

    iPPSOutput(SPI2SCKPin, OUT_FN_PPS_SCK2); //Assign SPI2 SCK
    iPPSOutput(SPI2MOSIPin, OUT_FN_PPS_SDO2); //Assign SPI2 SDO
    iPPSInput(IN_FN_PPS_SDI2, SPI2MISOPin); //Assign SPI2 SDI

    iPPSInput(IN_FN_PPS_QEA2, QEI2CHAPin); //Assign QEA2
    iPPSInput(IN_FN_PPS_QEB2, QEI2CHBPin); //Assign QEB2

    iPPSOutput(UART1TXPin, OUT_FN_PPS_U1TX); //Assign UART1 TX
    iPPSInput(IN_FN_PPS_U1RX, UART1RXPin); //Assign UART1 RX
    PPSLock;

    PMD1 = 0xFFFF;
    PMD2 = 0xFFFF;
    PMD3 = 0xFFFF;
}

void init_peripherals(void) {
    setup_timer2();
    setup_pwm();
    setup_uart();
    setup_spi();
    setup_qei();
}

void setup_timer2(void) {
    PMD1bits.T2MD = 0;
    __delay_us(5);
    CloseTimer2();
    ConfigIntTimer2(T2_INT_ON & T2_INT_PRIOR_1);
    OpenTimer2(T2_ON & T2_IDLE_CON & T2_GATE_OFF & TIMER2_PRESCALER &
            T2_32BIT_MODE_OFF & T2_SOURCE_INT, TIMER2_PERIOD_VAL);
}

void setup_spi(void) {
    PMD1bits.SPI1MD = 0;
    PMD1bits.SPI2MD = 0;
    __delay_us(5);
#if 0
    OpenSPI1(ENABLE_SDO_PIN & ENABLE_SCK_PIN & SPI_MODE16_OFF &
            SPI_SMP_OFF & SPI_CKE_ON & SLAVE_ENABLE_OFF &
            CLK_POL_ACTIVE_HIGH & MASTER_ENABLE_ON &
            SEC_PRESCAL_8_1 & PRI_PRESCAL_4_1,
            FRAME_ENABLE_OFF & FIFO_BUFFER_DISABLE,
            SPI_ENABLE & SPI_IDLE_CON & SPI_RX_OVFLOW_CLR);
#else
    SPI1STAT = 0x0000;
    SPI1CON1 = 0x0000;
    SPI1CON2 = 0x0000;
    SPI1CON1bits.CKE = 1;
    SPI1CON1bits.MSTEN = 1;
    SPI1CON1bits.PPRE = 0b10;
    SPI1CON1bits.SPRE = 0b000;
    SPI1STATbits.SPIEN = 1;

    SPI2STAT = 0x0000;
    SPI2CON1 = 0x0000;
    SPI2CON2 = 0x0000;
    SPI2CON1bits.CKE = 1;
    SPI2CON1bits.MSTEN = 1;
    SPI2CON1bits.PPRE = 0b10;
    SPI2CON1bits.SPRE = 0b000;
    SPI2STATbits.SPIEN = 1;
#endif
}

BOOL spi_is_tx_busy(SPIChannel channel) {
    if (channel == SPI_CH1)
        return !SPI1STATbits.SPITBF;
    else if (channel == SPI_CH2)
        return !SPI2STATbits.SPITBF;
    return FALSE;
}

void setup_uart(void) {
    PMD1bits.U1MD = 0;
    __delay_us(5);
    /*
        CloseUART1();
        ConfigIntUART1(UART_RX_INT_EN & UART_RX_INT_PR6 & UART_TX_INT_DIS & UART_TX_INT_PR2);
        OpenUART1(UART_EN & UART_IDLE_CON & UART_IrDA_DISABLE &
                UART_MODE_SIMPLEX & UART_UEN_00 & UART_DIS_WAKE &
                UART_DIS_LOOPBACK & UART_DIS_ABAUD & UART_UXRX_IDLE_ONE &
                UART_BRGH_SIXTEEN & UART_NO_PAR_8BIT & UART_1STOPBIT,
                UART_INT_TX_BUF_EMPTY & UART_TX_ENABLE & UART_INT_RX_CHAR &
                UART_ADR_DETECT_DIS & UART_RX_OVERRUN_CLEAR &
                UART_IrDA_POL_INV_ZERO & UART_SYNC_BREAK_DISABLED,
                BAUD_RATE_19200);
     */
    U1BRG = BAUD_RATE_19200; // Baud Rate setting
    U1MODE = 0;
    U1STA = 0;
    IEC0bits.U1RXIE = 1; // Enable UART RX interrupt
    U1MODEbits.RTSMD = 1; //simplex mode
    U1MODEbits.UARTEN = 1; //Enable UART
    U1STAbits.UTXEN = 1; // Enable UART TX (must be after module enable!)
}

void rs485_direction_control(BOOL transmitter) {
}

void setup_qei(void) {
    PMD1bits.QEI1MD = 0;
    PMD3bits.QEI2MD = 0;
    __delay_us(5);

    POS1CNT = 0;
    POS2CNT = 0;
    MAX1CNT = 0xFFFF;
    MAX2CNT = 0xFFFF;
    OpenQEI1(QEI_DIR_SEL_CNTRL & QEI_INT_CLK & QEI_INDEX_RESET_DISABLE &
            QEI_CLK_PRESCALE_8 & QEI_GATED_ACC_DISABLE & QEI_NORMAL_IO &
            QEI_INPUTS_NOSWAP & QEI_MODE_x2_MATCH & QEI_UP_COUNT & QEI_IDLE_CON,
            QEI_QE_CLK_DIVIDE_1_32 & QEI_QE_OUT_DISABLE & POS_CNT_ERR_INT_DISABLE &
            MATCH_INDEX_PHASEB_LOW & MATCH_INDEX_PHASEA_LOW & MATCH_INDEX_INPUT_PHASEA &
            MATCH_INDEX_INPUT_LOW);
    OpenQEI2(QEI_DIR_SEL_CNTRL & QEI_INT_CLK & QEI_INDEX_RESET_DISABLE &
            QEI_CLK_PRESCALE_8 & QEI_GATED_ACC_DISABLE & QEI_NORMAL_IO &
            QEI_INPUTS_NOSWAP & QEI_MODE_x2_MATCH & QEI_UP_COUNT & QEI_IDLE_CON,
            QEI_QE_CLK_DIVIDE_1_32 & QEI_QE_OUT_DISABLE & POS_CNT_ERR_INT_DISABLE &
            MATCH_INDEX_PHASEB_LOW & MATCH_INDEX_PHASEA_LOW & MATCH_INDEX_INPUT_PHASEA &
            MATCH_INDEX_INPUT_LOW);
}

#define default_speed   500

void setup_pwm(void) {
    PMD1bits.PWM1MD = 0;
    __delay_us(5);

    P1FLTACON = 0;
    P1OVDCON = 0;
    ConfigIntMCPWM1(PWM1_INT_DIS & PWM1_FLTA_DIS_INT & PWM1_INT_PR1 & PWM1_FLTA_INT_PR0);
    SetDCMCPWM1(1, 0x3FFF, 0);
    SetDCMCPWM1(2, 0x3FFF, 0);
    OpenMCPWM1(
            0x7FFF,
            0,
            PWM1_EN & PWM1_IDLE_CON & PWM1_OP_SCALE1 & PWM1_IPCLK_SCALE4 & PWM1_MOD_FREE,
            PWM1_MOD1_IND & PWM1_MOD2_IND & PWM1_MOD3_IND & PWM1_PDIS3H & PWM1_PEN2H &
            PWM1_PEN1H & PWM1_PDIS3L & PWM1_PDIS2L & PWM1_PDIS1L,
            PWM1_SEVOPS1 & PWM1_OSYNC_PWM & PWM1_UEN
            );
}

void set_pwm_freq(StepperChannel channel, UINT16 newFreq) {
    UINT16 period, dutycycle;
    UINT8 temp;

    if (newFreq > 488) {
        temp = 0;
        period = (FCY / newFreq) - 1;
    } else if (newFreq > 123) {
        temp = 1;
        period = ((FCY / 4) / newFreq) - 1;
    } else if (newFreq > 31) {
        temp = 2;
        period = ((FCY / 16) / newFreq) - 1;
    } else {
        temp = 3;
        period = ((FCY / 64) / newFreq) - 1;
    }

    _PWM1IE = 0;
    PWM1CON2bits.UDIS = 1;
    P1TCONbits.PTCKPS = temp;
    dutycycle = period >> 1;

    P1TPER = period;
    P1DC1 = dutycycle;
    P1DC2 = dutycycle;

    PWM1CON2bits.UDIS = 0;
    _PWM1IE = 1;
}

UINT8 spi_loop(SPIChannel channel, UINT8 data) {
    UINT32 timeout = 1000000;
#ifdef SPI1BUF
    if (channel == SPI_CH1) {
        while (SPI1STATbits.SPITBF);
        SPI1BUF = data;
        while (!SPI1STATbits.SPIRBF) {
            if (--timeout == 0) return 0;
        }
        return SPI1BUF & 0xFF;
    }
#endif
#ifdef SPI2BUF
    if (channel == SPI_CH2) {
        while (SPI2STATbits.SPITBF);
        SPI2BUF = data;
        while (!SPI2STATbits.SPIRBF) {
            if (--timeout == 0) return 0;
        }
        return SPI2BUF & 0xFF;
    }
#endif
#ifdef SPI3BUF
    if (channel == SPI_CH3) {
        while (SPI3STATbits.SPITBF);
        SPI3BUF = data;
        while (!SPI3STATbits.SPIRBF) {
            if (--timeout == 0) return 0;
        }
        return SPI3BUF & 0xFF;
    }
#endif
#ifdef SPI4BUF
    if (channel == SPI_CH4) {
        while (SPI4STATbits.SPITBF);
        SPI4BUF = data;
        while (!SPI4STATbits.SPIRBF) {
            if (--timeout == 0) return 0;
        }
        return SPI4BUF & 0xFF;
    }
#endif
    return 0;
}

void spi_assert_cs(SPIChannel channel, BOOL assert) {
    if (channel == SPI_CH1) {
        SPI1AssertCS(assert);
    } else if (channel == SPI_CH2) {
        SPI2AssertCS(assert);
    }
}

UINT16_VAL get_sensors(void) {
    return ExtSensorValues;
}

BOOL get_stepper_flag(StepperChannel channel) {
    if (channel == STEPPER_MOTOR2)
        return Stepper2FLGPin;
    return Stepper1FLGPin;
}

BOOL get_stepper_direction(StepperChannel channel) {
    if (channel == STEPPER_MOTOR2)
        return Stepper2DIRPin;
    return Stepper1DIRPin;
}

void set_stepper_direction(StepperChannel channel, BOOL dir) {
    if (channel == STEPPER_MOTOR2)
        Stepper2DIRPin = dir;
    else
        Stepper1DIRPin = dir;
}

void assert_stepper_reset(StepperChannel channel, BOOL reset) {
    if (channel == STEPPER_MOTOR2)
        Stepper2RSTPin = reset;
    else
        Stepper1RSTPin = reset;
}

void set_pwm_outputs(StepperChannel channel, BOOL enable) {
    if (channel == STEPPER_MOTOR1) {
        P1OVDCONbits.POVD2H = enable;
    } else if (channel == STEPPER_MOTOR2) {
        P1OVDCONbits.POVD1H = enable;
    }
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
