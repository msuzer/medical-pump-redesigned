/*********************************************************
  * PPS Header File
  * 
  * Header for Pin Re-Mapping peripheral library functions
  *********************************************************/

#ifndef __PPS_H
#define __PPS_H

#include "PIC24F_periph_features.h"

//This preprocessor conditional statement is to avoid unintended linking for unsuppported devices.
#if defined (pps_v1_1) || defined (pps_v1_2) || defined (pps_v1_3) || defined (pps_v1_4) || defined (pps_v2_1) ||\
    defined (pps_v2_2) || defined (pps_v2_3) || defined (pps_v2_4)|| defined (pps_v2_5) || defined (pps_v2_6) || \
	defined (pps_v2_7) || defined (pps_v2_8) || defined (pps_v1_5) || defined (pps_v1_6)|| defined (pps_v3_1) ||\
	defined (pps_v3_2) || defined (pps_v3_3) || defined (pps_v3_4) || defined (pps_v3_5) || defined (pps_v1_7)

/*----------------------------------------------------------------------------------------------------*/
/*Section:  Remappable Peripheral Inputs: 								*/									  
/*----------------------------------------------------------------------------------------------------*/

#if defined (pps_v1_7)
#define IN_PIN_PPS_RP0				0   /* Assign RP0 as Input Pin */
#define IN_PIN_PPS_RP1				1   /* Assign RP1 as Input Pin */
#define IN_PIN_PPS_RP2				2   /* Assign RP2 as Input Pin */
#define IN_PIN_PPS_RP3				3   /* Assign RP3 as Input Pin */
#define IN_PIN_PPS_RPI4				4   /* Assign RP4 as Input Pin */
#define IN_PIN_PPS_RP5				5   /* Assign RP5 as Input Pin */
#define IN_PIN_PPS_RP6				6   /* Assign RP6 as Input Pin */
#define IN_PIN_PPS_RP7				7   /* Assign RP7 as Input Pin */
#define IN_PIN_PPS_RP8				8   /* Assign RP8 as Input Pin */
#define IN_PIN_PPS_RP9				9   /* Assign RP9 as Input Pin */
#define IN_PIN_PPS_RP10				10  /* Assign RP10 as Input Pin */
#define IN_PIN_PPS_RP11				11  /* Assign RP11 as Input Pin */
#define IN_PIN_PPS_RP12				12  /* Assign RP12 as Input Pin */
#define IN_PIN_PPS_RP13				13  /* Assign RP13 as Input Pin */
#define IN_PIN_PPS_RP14				14  /* Assign RP14 as Input Pin */
#define IN_PIN_PPS_RP15				15  /* Assign RP15 as Input Pin */
#define IN_PIN_PPS_RP16				16  /* Assign RP16 as Input Pin */
#define IN_PIN_PPS_RP17				17  /* Assign RP17 as Input Pin */
#define IN_PIN_PPS_RP18				18  /* Assign RP18 as Input Pin */
#define IN_PIN_PPS_RP19				19  /* Assign RP19 as Input Pin */
#define IN_PIN_PPS_RP20				20  /* Assign RP20 as Input Pin */
#define IN_PIN_PPS_RP21				21  /* Assign RP21 as Input Pin */
#define IN_PIN_PPS_RP22				22  /* Assign RP22 as Input Pin */
#define IN_PIN_PPS_RP23				23  /* Assign RP23 as Input Pin */
#define IN_PIN_PPS_RP24				24  /* Assign RP24 as Input Pin */
#define IN_PIN_PPS_RP25				25  /* Assign RP25 as Input Pin */
#endif

#define IN_PIN_PPS_MASK             (~63)

#if defined (pps_v1_7)
#define IN_FN_PPS_INT1			RPINR0bits.INT1R/* Assign External Interrupt 1 (INTR1) to the corresponding RPn pin*/
#define IN_FN_PPS_INT2			RPINR1bits.INT2R/* Assign External Interrupt 2 (INTR2) to the corresponding RPn pin*/
#define IN_FN_PPS_INT3			RPINR1bits.INT3R/* Assign External Interrupt 3 (INTR3) to the corresponding RPn pin*/
#define IN_FN_PPS_INT4			RPINR2bits.INT4R/* Assign External Interrupt 3 (INTR4) to the corresponding RPn pin*/
#define IN_FN_PPS_IC1			RPINR7bits.IC1R	/* Assign Input Capture 1 (IC1) to the corresponding RPn pin*/
#define IN_FN_PPS_IC2			RPINR7bits.IC2R	/* Assign Input Capture 2 (IC2) to the corresponding RPn pin*/
#define IN_FN_PPS_IC3			RPINR8bits.IC3R/* Assign Input Capture 3 (IC3) to the corresponding RPn pin*/
#define IN_FN_PPS_IC4			RPINR8bits.IC4R/* Assign Input Capture 4 (IC4) to the corresponding RPn pin*/
#define IN_FN_PPS_IC5			RPINR9bits.IC5R	/* Assign Input Capture 5 (IC5) to the corresponding RPn pin*/
#define IN_FN_PPS_IC6			RPINR9bits.IC6R	/* Assign Input Capture 6 (IC6) to the corresponding RPn pin*/
#define IN_FN_PPS_OCFA			RPINR11bits.OCFAR/* Assign Output Capture A (OCFA) to the corresponding RPn pin*/
#define IN_FN_PPS_OCFB			RPINR11bits.OCFBR/* Assign Output Capture B (OCFB) to the corresponding RPn pin*/
#define IN_FN_PPS_OCTRIG1		RPINR0bits.OCTRIG1R/* Assign Output Capture A (OCTRIG1) to the corresponding RPn pin*/
#define IN_FN_PPS_OCTRIG2		RPINR2bits.OCTRIG2R/* Assign Output Capture B (OCTRIG2) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK1IN		RPINR20bits.SCK1R/* Assign SCK1 Clock Input (SCK1IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SDI1			RPINR20bits.SDI1R/* Assign SDI1 Data Input (SDI1) to the corresponding RPn pin*/
#define IN_FN_PPS_SS1IN			RPINR21bits.SS1R/* Assign SS1 Slave Select Input (SS1IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK2IN		RPINR22bits.SCK2R/* Assign SCK2 Clock Input (SCK2IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SDI2			RPINR22bits.SDI2R/* Assign SDI2 Data Input (SDI2) to the corresponding RPn pin*/
#define IN_FN_PPS_SS2IN			RPINR23bits.SS2R/* Assign SS2 Slave Select Input (SS2IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SCK3IN		RPINR28bits.SCK3R/* Assign SCK3 Clock Input (SCK3IN) to the corresponding RPn pin*/
#define IN_FN_PPS_SDI3			RPINR28bits.SDI3R/* Assign SDI3 Data Input (SDI3) to the corresponding RPn pin*/
#define IN_FN_PPS_SS3IN			RPINR29bits.SS3RR/* Assign SS3 Slave Select Input (SS3IN) to the corresponding RPn pin*/
#define IN_FN_PPS_TMRCK			RPINR23bits.TMRCKR/* Assign Generic Timer External Clock (TMRCKR) to the corresponding RPn pin*/
#define IN_FN_PPS_U1CTS			RPINR18bits.U1CTSR/* Assign UART1 Clear to Send (U1CTS) to the corresponding RPn pin*/
#define IN_FN_PPS_U1RX			RPINR18bits.U1RXR/* Assign UART1 Receive (U1RX) to the corresponding RPn pin*/
#define IN_FN_PPS_U2CTS			RPINR19bits.U2CTSR/* Assign UART2 Clear to Send (U2CTS) to the corresponding RPn pin*/
#define IN_FN_PPS_U2RX			RPINR19bits.U2RXR/* Assign UART2 Receive (U2RX) to the corresponding RPn pin*/
#define IN_FN_PPS_U3CTS			RPINR21bits.U3CTSR/* Assign UART3 Clear to Send (U3CTS) to the corresponding RPn pin*/
#define IN_FN_PPS_U3RX			RPINR17bits.U3RXR/* Assign UART3 Receive (U3RX) to the corresponding RPn pin*/
#define IN_FN_PPS_U4CTS			RPINR27bits.U4CTSR/* Assign UART4 Clear to Send (U4CTS) to the corresponding RPn pin*/
#define IN_FN_PPS_U4RX			RPINR27bits.U4RXR/* Assign UART4 Receive (U4RX) to the corresponding RPn pin*/
#define IN_FN_PPS_MDMIN			RPINR30bits.MDMIRR/* Assign DSM Modulation input to the corresponding RPn pin*/
#define IN_FN_PPS_MDCIN1		RPINR31bits.MDC1R/* Assign DSM Carrier 1 Input to the corresponding RPn pin*/
#define IN_FN_PPS_MDCIN2		RPINR31bits.MDC2R/* Assign DSM Carrier 2 Input to the corresponding RPn pin*/
#endif

 /*********************************************************************
 Macro:          	iPPSInput(fn,pin)
 
 PreCondition:     None 
 
 Side Effects:     None
 
 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.
 
 Parameters:  	fn - function to be assigned for particular pin
			*	IN_FN_PPS_TxCK
			*	IN_FN_PPS_INTx
			*	IN_FN_PPS_ICx 
			*	IN_FN_PPS_OCFx	
			*	IN_FN_PPS_UxRX	
			*	IN_FN_PPS_UxCTS
			*	IN_FN_PPS_SDIx	
			*	IN_FN_PPS_SCKxIN
			*	IN_FN_PPS_SSxIN
			
			pin - pin number(x) for which functionality has to be assigned
			*	IN_PIN_PPS_RPx
			
 Returns: 		None		
 
 Note:            	None
 ********************************************************************/
#define iPPSInput(fn,pin)		    fn=pin

/*********************************************************************
 Macro:          	PPSInput(fn,pin)
 
 PreCondition:     None 
 
 Side Effects:     None
 
 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.
 
 Parameters:  	fn - function to be assigned for particular pin
			*	PPS_TxCK
			*	PPS_INTx
			*	PPS_ICx 
			*	PPS_OCFx	
			*	PPS_UxRX	
			*	PPS_UxCTS
			*	PPS_SDIx	
			*	PPS_SCKxIN
			*	PPS_SSxIN
			
			pin - pin number(x) for which functionality has to be assigned
			*	PPS_RPx
			
 Returns: 		None		
 
 Note:            	None
 ********************************************************************/
#define PPSInput(fn,pin)	    	iPPSInput(IN_FN_##fn,IN_PIN_##pin)

/*----------------------------------------------------------------------------------------------------*/
/*Section:  Remappable Peripheral Outputs: 					         */												
/*----------------------------------------------------------------------------------------------------*/

#if defined (pps_v1_7)
#define OUT_FN_PPS_NULL				 0  /* RPn tied to default port pin */
#define OUT_FN_PPS_C1OUT			 1  /* RPn tied to comparator 1 output */
#define OUT_FN_PPS_C2OUT			 2  /* RPn tied to comparator 2 output */
#define OUT_FN_PPS_U1TX				 3  /* RPn tied to UART1 Transmit */
#define OUT_FN_PPS_U1RTS			 4  /* RPn tied to UART1 Ready To Send */
#define OUT_FN_PPS_U2TX				 5  /* RPn tied to UART2 Transmit */
#define OUT_FN_PPS_U2RTS			 6  /* RPn tied to UART2 Ready To Send */
#define OUT_FN_PPS_SDO1				 7  /* RPn tied to SPI1 Data Output */
#define OUT_FN_PPS_SCK1OUT			 8  /* RPn tied to SPI1 Clock Output */
#define OUT_FN_PPS_SS1OUT			 9  /* RPn tied to SPI1 Slave Select Output */
#define OUT_FN_PPS_SDO2				10  /* RPn tied to SPI2 Data Output */
#define OUT_FN_PPS_SCK2OUT			11  /* RPn tied to SPI2 Clock Output */
#define OUT_FN_PPS_SS2OUT                       12  /* RPn tied to SPI2 Slave Select Output */
#define OUT_FN_PPS_OC1				13	/* RPn tied to Output Compare 1 */
#define OUT_FN_PPS_OC2				14	/* RPn tied to Output Compare 2 */
#define OUT_FN_PPS_OC3				15  /* RPn tied to Output Compare 3 */
#define OUT_FN_PPS_OC4				16  /* RPn tied to Output Compare 4 */
#define OUT_FN_PPS_OC5				17  /* RPn tied to Output Compare 5 */
#define OUT_FN_PPS_OC6				18  /* RPn tied to Output Compare 6 */
#define OUT_FN_PPS_U3TX				19  /* RPn tied to UART3 Transmit */
#define OUT_FN_PPS_U3RTS			20  /* RPn tied to UART3 Ready To Send */
#define OUT_FN_PPS_U4TX				21  /* RPn tied to UART4 Transmit */
#define OUT_FN_PPS_U4RTS			22  /* RPn tied to UART4 Ready To Send */
#define OUT_FN_PPS_SDO3				23  /* RPn tied to SPI3 Data Output */
#define OUT_FN_PPS_SCK3OUT			24  /* RPn tied to SPI3 Clock Output */
#define OUT_FN_PPS_SS3OUT                       25  /* RPn tied to SPI3 Slave Select Output */
#define OUT_FN_PPS_C3OUT			26  /* RPn tied to comparator 3 output */
#define OUT_FN_PPS_MDOUT			27  /* RPn tied to DSM Modulator output */
#endif

#if defined (pps_v1_7)
#define OUT_PIN_PPS_RP0				RPOR0bits.RP0R/* Assign RP0 as Output Pin */
#define OUT_PIN_PPS_RP1				RPOR0bits.RP1R/* Assign RP1 as Output Pin */
#define OUT_PIN_PPS_RP2				RPOR1bits.RP2R/* Assign RP2 as Output Pin */
#define OUT_PIN_PPS_RP3				RPOR1bits.RP3R/* Assign RP3 as Output Pin */
#define OUT_PIN_PPS_RP5				RPOR2bits.RP5R/* Assign RP5 as Output Pin */
#define OUT_PIN_PPS_RP6				RPOR3bits.RP6R/* Assign RP6 as Output Pin */
#define OUT_PIN_PPS_RP7				RPOR3bits.RP7R	/* Assign RP7 as Output Pin */
#define OUT_PIN_PPS_RP8				RPOR4bits.RP8R/* Assign RP8 as Output Pin */
#define OUT_PIN_PPS_RP9				RPOR4bits.RP9R/* Assign RP9 as Output Pin */
#define OUT_PIN_PPS_RP10			RPOR5bits.RP10R	/* Assign RP10 as Output Pin */
#define OUT_PIN_PPS_RP11			RPOR5bits.RP11R/* Assign RP11 as Output Pin */
#define OUT_PIN_PPS_RP12			RPOR6bits.RP12R/* Assign RP12 as Output Pin */
#define OUT_PIN_PPS_RP13			RPOR6bits.RP13R	/* Assign RP13 as Output Pin */
#define OUT_PIN_PPS_RP14			RPOR7bits.RP14R	/* Assign RP14 as Output Pin */
#define OUT_PIN_PPS_RP15			RPOR7bits.RP15R/* Assign RP15 as Output Pin */
#define OUT_PIN_PPS_RP16			RPOR8bits.RP16R	/* Assign RP16 as Output Pin */
#define OUT_PIN_PPS_RP17			RPOR8bits.RP17R	/* Assign RP17 as Output Pin */
#define OUT_PIN_PPS_RP18			RPOR9bits.RP18R/* Assign RP18 as Output Pin */
#define OUT_PIN_PPS_RP19			RPOR9bits.RP19R/* Assign RP19 as Output Pin */
#define OUT_PIN_PPS_RP20			RPOR10bits.RP20R/* Assign RP20 as Output Pin */
#define OUT_PIN_PPS_RP21			RPOR10bits.RP21R/* Assign RP21 as Output Pin */
#define OUT_PIN_PPS_RP22			RPOR11bits.RP22R/* Assign RP22 as Output Pin */
#define OUT_PIN_PPS_RP23			RPOR11bits.RP23R/* Assign RP23 as Output Pin */
#define OUT_PIN_PPS_RP24			RPOR12bits.RP24R/* Assign RP24 as Output Pin */
#define OUT_PIN_PPS_RP25			RPOR12bits.RP25R/* Assign RP25 as Output Pin */
#endif

 /*********************************************************************
 Macro:          	iPPSOutput(pin,fn)
 
 PreCondition:     None 
 
 Side Effects:     None
 
 Overview:          The macro assigns given pin as output pin by configuring register RPORx.
 
 Parameters:  	pin - pin number(x) for which functionality has to be assigned
			*	OUT_PIN_PPS_RPx
			
            fn - function to be assigned for particular pin
			*	OUT_FN_PPS_NULL
			*	OUT_FN_PPS_CxOUT
			*	OUT_FN_PPS_UxTX
			*	OUT_FN_PPS_UxRTS
			*	OUT_FN_PPS_SDOx	
			*	OUT_FN_PPS_SCKxOUT	
			*	OUT_FN_PPS_SSxOUT	
			*	OUT_FN_PPS_OCx		
			*	OUT_FN_PPS_CTMU			
			
 Returns: 		None		
 
 Note:            	None
 ********************************************************************/
#define iPPSOutput(pin,fn)		    pin=fn

 /*********************************************************************
  Macro:          	PPSOutput(pin,fn)
 
  PreCondition:     None 
 
  Side Effects:     None
 
  Overview:          The macro assigns given pin as output pin by configuring register RPORx.
 
  Parameters:  	pin - pin number(x) for which functionality has to be assigned
			*	PPS_RPx
			
                                fn - function to be assigned for particular pin
			*	PPS_NULL
			*	PPS_CxOUT
			*	PPS_UxTX
			*	PPS_UxRTS
			*	PPS_SDOx	
			*	PPS_SCKxOUT	
			*	PPS_SSxOUT	
			*	PPS_OCx		
			*	PPS_CTMU			
			
  Returns: 		None		
 
  Note:            	None
 ********************************************************************/
#define PPSOutput(pin,fn)		    iPPSOutput(OUT_PIN_##pin,OUT_FN_##fn)
/*----------------------------------------------------------------------------------------------------*/

 /*********************************************************************
  Macro:          	PPSUnLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the unlocking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
  Note:            	None
 ********************************************************************/
#define  PPSUnLock  				__builtin_write_OSCCONL(OSCCON & 0xbf)

 /*********************************************************************
  Macro:          	PPSLock
  PreCondition:     None 
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:  	None
  Returns: 		None		
 Note:            	None
 ********************************************************************/
#define  PPSLock 					__builtin_write_OSCCONL(OSCCON | 0x40)

#else		//This preprocessor conditional statement is to avoid unintended linking for unsuppported devices.
#warning "Does not build on this target"
#endif

#endif /*__PPS_H */
