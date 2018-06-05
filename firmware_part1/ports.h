#ifndef __PORTS_H
#define __PORTS_H

/******************************************************************************
 *
 *                  PORTS PERIPHERAL LIBRARY HEADER FILE
 *
 ******************************************************************************
 * FileName:        ports.h
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

#include "PIC24F_periph_features.h"
 
#define CNEN1_VALUE             0x0000
#define CNPU1_VALUE             0x0000

#define CNEN2_VALUE             0x0000
#define CNPU2_VALUE             0x0000

#define IEC0_VALUE              0x0000
#define IEC1_VALUE              0x0000
#define IEC2_VALUE              0x0000

#define IFS0_VALUE              0x0000
#define IFS1_VALUE              0x0000
#define IFS2_VALUE              0x0000

#define IPC0_VALUE              0x4444
#define IPC1_VALUE              0x4444
#define IPC2_VALUE              0x4444
#define IPC3_VALUE              0x4444
#define IPC4_VALUE              0x4444
#define IPC5_VALUE              0x4444
#define IPC6_VALUE              0x4444
#define IPC7_VALUE              0x4444
#define IPC8_VALUE              0x4444
#define IPC9_VALUE              0x4444
#define IPC10_VALUE             0x4444
#define IPC11_VALUE             0x4444

#ifndef USE_AND_OR /* Format for AND_OR based bit setting */

#else /* Format for backward compatibility (AND based bit setting). */

/* Setting the priority of External or CN interrupt */
#define INT_PRI_0           	0x0000 /*Interrupt priority 0*/
#define INT_PRI_1           	0x0001 /*Interrupt priority 1*/
#define INT_PRI_2           	0x0002 /*Interrupt priority 2*/
#define INT_PRI_3           	0x0003 /*Interrupt priority 3*/
#define INT_PRI_4           	0x0004 /*Interrupt priority 4*/
#define INT_PRI_5           	0x0005 /*Interrupt priority 5*/
#define INT_PRI_6           	0x0006 /*Interrupt priority 6*/
#define INT_PRI_7           	0x0007 /*Interrupt priority 7*/
#define INT_PRI_MASK        	(~INT_PRI_7)   

/* enable / disable External or CN interrupt */
#define INT_ENABLE          	0x0008 /*Enable Interrupt*/
#define INT_DISABLE         	0x0000 /*Disable Interrupt*/
#define INT_MASK            	(~INT_ENABLE)

/* External interrupts edge selection defines */
#define RISING_EDGE_INT         0x0000 /*Interrupt is set by a positive edge */
#define FALLING_EDGE_INT        0x0010 /*Interrupt is set by a negative edge  */
#define EDGE_INT_MASK           (~FALLING_EDGE_INT)

#endif /* USE_AND_OR */

/******************************************************************
Macro       : EnableCNx
 
Include     : ports.h
 
Description : This macro enables the individual change notification interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/

#if	defined (cn_v3_5) || defined (cn_v3_6) || defined (cn_v3_7) || defined (cn_v3_8)
#define EnableCN0               CNEN1bits.CN0IE = 1 /*enables change notification interrupt*/
#define EnableCN1               CNEN1bits.CN1IE = 1 /*enables change notification interrupt*/
#define EnableCN2               CNEN1bits.CN2IE = 1 /*enables change notification interrupt*/
#define EnableCN3               CNEN1bits.CN3IE = 1 /*enables change notification interrupt*/
#define EnableCN4               CNEN1bits.CN4IE = 1 /*enables change notification interrupt*/
#define EnableCN5               CNEN1bits.CN5IE = 1 /*enables change notification interrupt*/
#define EnableCN6               CNEN1bits.CN6IE = 1 /*enables change notification interrupt*/
#define EnableCN11              CNEN1bits.CN11IE = 1 /*enables change notification interrupt*/
#define EnableCN12              CNEN1bits.CN12IE = 1 /*enables change notification interrupt*/
#define EnableCN13              CNEN1bits.CN13IE = 1 /*enables change notification interrupt*/
#define EnableCN14              CNEN1bits.CN14IE = 1 /*enables change notification interrupt*/
#define EnableCN21               CNEN2bits.CN21IE = 1 /*enables change notification interrupt*/
#define EnableCN22               CNEN2bits.CN22IE = 1 /*enables change notification interrupt*/
#define EnableCN23               CNEN2bits.CN23IE = 1 /*enables change notification interrupt*/
#define EnableCN29               CNEN2bits.CN29IE = 1 /*enables change notification interrupt*/
#define EnableCN30               CNEN2bits.CN30IE = 1 /*enables change notification interrupt*/
#if	defined (cn_v3_6) || defined (cn_v3_7) || defined (cn_v3_8)
#define EnableCN7               CNEN1bits.CN7IE = 1 /*enables change notification interrupt*/
#define EnableCN9               CNEN1bits.CN9IE = 1 /*enables change notification interrupt*/
#define EnableCN15              CNEN1bits.CN15IE = 1 /*enables change notification interrupt*/
#define EnableCN16              CNEN2bits.CN16IE = 1 /*enables change notification interrupt*/
#define EnableCN24               CNEN2bits.CN24IE = 1 /*enables change notification interrupt*/
#define EnableCN27               CNEN2bits.CN27IE = 1 /*enables change notification interrupt*/
#endif
#if	defined (cn_v3_7)
#define EnableCN10              CNEN1bits.CN10IE = 1 /*enables change notification interrupt*/
#define EnableCN17              CNEN2bits.CN17IE = 1 /*enables change notification interrupt*/
#define EnableCN18              CNEN2bits.CN18IE = 1 /*enables change notification interrupt*/
#define EnableCN19               CNEN2bits.CN19IE = 1 /*enables change notification interrupt*/
#define EnableCN20               CNEN2bits.CN20IE = 1 /*enables change notification interrupt*/
#define EnableCN25               CNEN2bits.CN25IE = 1 /*enables change notification interrupt*/
#define EnableCN26               CNEN2bits.CN26IE = 1 /*enables change notification interrupt*/
#define EnableCN28               CNEN2bits.CN28IE = 1 /*enables change notification interrupt*/
#define EnableCN31               CNEN2bits.CN31IE = 1 /*enables change notification interrupt*/
#define EnableCN32               CNEN3bits.CN32IE = 1 /*enables change notification interrupt*/
#define EnableCN33               CNEN3bits.CN33IE = 1 /*enables change notification interrupt*/
#define EnableCN34               CNEN3bits.CN34IE = 1 /*enables change notification interrupt*/
#define EnableCN35               CNEN3bits.CN35IE = 1 /*enables change notification interrupt*/
#define EnableCN36               CNEN3bits.CN36IE = 1 /*enables change notification interrupt*/
#endif
#if	defined (cn_v3_8)
#define EnableCN8              CNEN1bits.CN8IE = 1 /*enables change notification interrupt*/
#define EnableCN10              CNEN1bits.CN10IE = 1 /*enables change notification interrupt*/
#define EnableCN17              CNEN2bits.CN17IE = 1 /*enables change notification interrupt*/
#define EnableCN18              CNEN2bits.CN18IE = 1 /*enables change notification interrupt*/
#define EnableCN19               CNEN2bits.CN19IE = 1 /*enables change notification interrupt*/
#define EnableCN20               CNEN2bits.CN20IE = 1 /*enables change notification interrupt*/
#define EnableCN25               CNEN2bits.CN25IE = 1 /*enables change notification interrupt*/
#define EnableCN26               CNEN2bits.CN26IE = 1 /*enables change notification interrupt*/
#define EnableCN28               CNEN2bits.CN28IE = 1 /*enables change notification interrupt*/
#define EnableCN33               CNEN3bits.CN33IE = 1 /*enables change notification interrupt*/
#define EnableCN34               CNEN3bits.CN34IE = 1 /*enables change notification interrupt*/
#define EnableCN35               CNEN3bits.CN35IE = 1 /*enables change notification interrupt*/
#define EnableCN36               CNEN3bits.CN36IE = 1 /*enables change notification interrupt*/
#endif
#endif

#if     defined (cn_v3_8)
#define DisableCN0               CNEN1bits.CN0IE = 0 /*Disables change notification interrupt*/
#define DisableCN1               CNEN1bits.CN1IE = 0 /*Disables change notification interrupt*/
#define DisableCN2               CNEN1bits.CN2IE = 0 /*Disables change notification interrupt*/
#define DisableCN3               CNEN1bits.CN3IE = 0 /*Disables change notification interrupt*/
#define DisableCN4               CNEN1bits.CN4IE = 0 /*Disables change notification interrupt*/
#define DisableCN5               CNEN1bits.CN5IE = 0 /*Disables change notification interrupt*/
#define DisableCN6               CNEN1bits.CN6IE = 0 /*Disables change notification interrupt*/
#define DisableCN7               CNEN1bits.CN7IE = 0 /*Disables change notification interrupt*/
#define DisableCN8              CNEN1bits.CN8IE = 0 /*Disables change notification interrupt*/
#define DisableCN9               CNEN1bits.CN9IE = 0 /*Disables change notification interrupt*/
#define DisableCN10              CNEN1bits.CN10IE = 0 /*Disables change notification interrupt*/
#define DisableCN11              CNEN1bits.CN11IE = 0 /*Disables change notification interrupt*/
#define DisableCN12              CNEN1bits.CN12IE = 0 /*Disables change notification interrupt*/
#define DisableCN13              CNEN1bits.CN13IE = 0 /*Disables change notification interrupt*/
#define DisableCN14              CNEN1bits.CN14IE = 0 /*Disables change notification interrupt*/
#define DisableCN15              CNEN1bits.CN15IE = 0 /*Disables change notification interrupt*/
#define DisableCN16              CNEN2bits.CN16IE = 0 /*Disables change notification interrupt*/
#define DisableCN17              CNEN2bits.CN17IE = 0 /*Disables change notification interrupt*/
#define DisableCN18              CNEN2bits.CN18IE = 0 /*Disables change notification interrupt*/
#define DisableCN19               CNEN2bits.CN19IE = 0 /*Disables change notification interrupt*/
#define DisableCN20               CNEN2bits.CN20IE = 0 /*Disables change notification interrupt*/
#define DisableCN21               CNEN2bits.CN21IE = 0 /*Disables change notification interrupt*/
#define DisableCN22               CNEN2bits.CN22IE = 0 /*Disables change notification interrupt*/
#define DisableCN23               CNEN2bits.CN23IE = 0 /*Disables change notification interrupt*/
#define DisableCN24               CNEN2bits.CN24IE = 0 /*Disables change notification interrupt*/
#define DisableCN25               CNEN2bits.CN25IE = 0 /*Disables change notification interrupt*/
#define DisableCN26               CNEN2bits.CN26IE = 0 /*Disables change notification interrupt*/
#define DisableCN27               CNEN2bits.CN27IE = 0 /*Disables change notification interrupt*/
#define DisableCN28               CNEN2bits.CN28IE = 0 /*Disables change notification interrupt*/
#define DisableCN29               CNEN2bits.CN29IE = 0 /*Disables change notification interrupt*/
#define DisableCN30               CNEN2bits.CN30IE = 0 /*Disables change notification interrupt*/
#define DisableCN33               CNEN3bits.CN33IE = 0 /*Disables change notification interrupt*/
#define DisableCN34               CNEN3bits.CN34IE = 0 /*Disables change notification interrupt*/
#define DisableCN35               CNEN3bits.CN35IE = 0 /*Disables change notification interrupt*/
#define DisableCN36               CNEN3bits.CN36IE = 0 /*Disables change notification interrupt*/
#endif

#if     defined (cn_v3_8)
#define EnablePullUpCN0               CNPU1bits.CN0PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN1               CNPU1bits.CN1PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN2               CNPU1bits.CN2PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN3               CNPU1bits.CN3PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN4               CNPU1bits.CN4PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN5               CNPU1bits.CN5PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN6               CNPU1bits.CN6PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN7               CNPU1bits.CN7PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN8               CNPU1bits.CN8PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN9               CNPU1bits.CN9PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN10               CNPU1bits.CN10PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN11               CNPU1bits.CN11PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN12               CNPU1bits.CN12PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN13               CNPU1bits.CN13PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN14               CNPU1bits.CN14PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN15               CNPU1bits.CN15PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN16               CNPU2bits.CN16PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN17               CNPU2bits.CN17PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN18               CNPU2bits.CN18PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN19               CNPU2bits.CN19PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN20               CNPU2bits.CN20PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN21               CNPU2bits.CN21PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN22               CNPU2bits.CN22PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN23               CNPU2bits.CN23PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN24               CNPU2bits.CN24PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN25               CNPU2bits.CN25PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN26               CNPU2bits.CN26PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN27               CNPU2bits.CN27PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN28               CNPU2bits.CN28PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN29               CNPU2bits.CN29PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN30               CNPU2bits.CN30PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN33               CNPU3bits.CN33PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN34               CNPU3bits.CN34PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN35               CNPU3bits.CN35PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#define EnablePullUpCN36               CNPU3bits.CN36PUE = 1 /*Enables  pull-up resistor for change notification pin*/
#endif

#if     defined (cn_v3_8)
#define DisablePullUpCN0               CNPU1bits.CN0PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN1               CNPU1bits.CN1PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN2               CNPU1bits.CN2PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN3               CNPU1bits.CN3PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN4               CNPU1bits.CN4PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN5               CNPU1bits.CN5PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN6               CNPU1bits.CN6PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN7               CNPU1bits.CN7PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN8               CNPU1bits.CN8PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN9               CNPU1bits.CN9PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN10               CNPU1bits.CN10PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN11               CNPU1bits.CN11PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN12               CNPU1bits.CN12PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN13               CNPU1bits.CN13PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN14               CNPU1bits.CN14PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN15               CNPU1bits.CN15PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN16               CNPU2bits.CN16PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN17               CNPU2bits.CN17PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN18               CNPU2bits.CN18PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN19               CNPU2bits.CN19PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN20               CNPU2bits.CN20PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN21               CNPU2bits.CN21PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN22               CNPU2bits.CN22PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN23               CNPU2bits.CN23PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN24               CNPU2bits.CN24PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN25               CNPU2bits.CN25PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN26               CNPU2bits.CN26PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN27               CNPU2bits.CN27PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN28               CNPU2bits.CN28PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN29               CNPU2bits.CN29PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN30               CNPU2bits.CN30PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN33               CNPU3bits.CN33PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN34               CNPU3bits.CN34PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN35               CNPU3bits.CN35PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#define DisablePullUpCN36               CNPU3bits.CN36PUE = 1 /*Disables  pull-up resistor for change notification pin*/
#endif

#if     defined (cn_v3_8)
#define EnablePullDownCN0               CNPD1bits.CN0PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN1               CNPD1bits.CN1PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN2               CNPD1bits.CN2PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN3               CNPD1bits.CN3PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN4               CNPD1bits.CN4PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN5               CNPD1bits.CN5PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN6               CNPD1bits.CN6PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN7               CNPD1bits.CN7PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN8               CNPD1bits.CN8PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN9               CNPD1bits.CN9PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN10               CNPD1bits.CN10PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN11               CNPD1bits.CN11PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN12               CNPD1bits.CN12PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN13               CNPD1bits.CN13PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN14               CNPD1bits.CN14PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN15               CNPD1bits.CN15PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN16               CNPD2bits.CN16PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN17               CNPD2bits.CN17PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN18               CNPD2bits.CN18PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN19               CNPD2bits.CN19PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN20               CNPD2bits.CN20PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN21               CNPD2bits.CN21PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN22               CNPD2bits.CN22PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN23               CNPD2bits.CN23PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN24               CNPD2bits.CN24PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN25               CNPD2bits.CN25PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN26               CNPD2bits.CN26PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN27               CNPD2bits.CN27PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN28               CNPD2bits.CN28PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN29               CNPD2bits.CN29PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN30               CNPD2bits.CN30PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN33               CNPD3bits.CN33PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN34               CNPD3bits.CN34PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN35               CNPD3bits.CN35PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#define EnablePullDownCN36               CNPD3bits.CN36PDE = 1 /*Enables  pull-Down resistor for change notification pin*/
#endif

#if     defined (cn_v3_8)
#define DisablePullDownCN0               CNPD1bits.CN0PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN1               CNPD1bits.CN1PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN2               CNPD1bits.CN2PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN3               CNPD1bits.CN3PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN4               CNPD1bits.CN4PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN5               CNPD1bits.CN5PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN6               CNPD1bits.CN6PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN7               CNPD1bits.CN7PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN8               CNPD1bits.CN8PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN9               CNPD1bits.CN9PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN10               CNPD1bits.CN10PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN11               CNPD1bits.CN11PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN12               CNPD1bits.CN12PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN13               CNPD1bits.CN13PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN14               CNPD1bits.CN14PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN15               CNPD1bits.CN15PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN16               CNPD2bits.CN16PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN17               CNPD2bits.CN17PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN18               CNPD2bits.CN18PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN19               CNPD2bits.CN19PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN20               CNPD2bits.CN20PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN21               CNPD2bits.CN21PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN22               CNPD2bits.CN22PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN23               CNPD2bits.CN23PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN24               CNPD2bits.CN24PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN25               CNPD2bits.CN25PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN26               CNPD2bits.CN26PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN27               CNPD2bits.CN27PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN28               CNPD2bits.CN28PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN29               CNPD2bits.CN29PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN30               CNPD2bits.CN30PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN33               CNPD3bits.CN33PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN34               CNPD3bits.CN34PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN35               CNPD3bits.CN35PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#define DisablePullDownCN36               CNPD3bits.CN36PDE = 0 /*Disables  pull-Down resistor for change notification pin*/
#endif

 //PORT macros and defines
#define IOPORT_BIT_0                        0x0001 /*Port Bit 0*/
#define IOPORT_BIT_1                        0x0002 /*Port Bit 1*/
#define IOPORT_BIT_2                        0x0004 /*Port Bit 2*/
#define IOPORT_BIT_3                        0x0008 /*Port Bit 3*/
#define IOPORT_BIT_4                        0x0010 /*Port Bit 4*/
#define IOPORT_BIT_5                        0x0020 /*Port Bit 5*/
#define IOPORT_BIT_6                        0x0040 /*Port Bit 6*/
#define IOPORT_BIT_7                        0x0080 /*Port Bit 7*/
#define IOPORT_BIT_8                        0x0100 /*Port Bit 8*/
#define IOPORT_BIT_9                        0x0200 /*Port Bit 9*/
#define IOPORT_BIT_10                       0x0400 /*Port Bit 10*/
#define IOPORT_BIT_11                       0x0800 /*Port Bit 11*/
#define IOPORT_BIT_12                       0x1000 /*Port Bit 12*/
#define IOPORT_BIT_13                       0x2000 /*Port Bit 13*/
#define IOPORT_BIT_14                       0x4000 /*Port Bit 14*/
#define IOPORT_BIT_15                       0x8000 /*Port Bit 15*/

#if defined (port_v1_1) || defined (port_v1_2)|| defined (port_v1_4)
/*PORTA Macros*/
#define mPORTAConfig(tris)                  { TRISA = (unsigned int)tris;}/* Configure PortA*/
#define mPORTARead()                        (PORTA) /*Read PortA*/
#define mPORTAWrite(lat)                    { LATA = (unsigned int)lat;} /*Write PortA*/
#define mPORTAReadLatch()                   (LATA) /*Reads PortA Latch*/
#define mPORTAGetConfig()                   (TRISA) /*Reads PortA Configuration value*/
#define mPORTAReadBit(_bit)                 (PORTA & (unsigned int)_bit) /*Reads given PortA bit value*/
#define mPORTAReadLatchBit(_bit)            (LATA & (unsigned int)_bit)  /*Reads given PortA bit latch value*/
#define mPORTAReadConfigBit(_bit)           (TRISA & (unsigned int)_bit)  /*Reads configuration of given PortA bit */
#define mPORTAOutputConfig(outputs)         { TRISA &= ~(unsigned int)outputs; } /*Configures PortA as output*/
#define mPORTAInputConfig(inputs)           { TRISA |= (unsigned int)inputs;} /*Configures PortA as input*/
#define mPORTASetBits(_bits)                { LATA |= (unsigned int)_bits;} /*Set PortA bit*/
#define mPORTAClearBits(_bits)              { LATA &= ~(unsigned int)_bits;}/*Clears PortA bit*/
#define mPORTAToggleBits(_bits)             { LATA ^= (unsigned int)_bits;} /*Toggles given PortA bit*/
#define mPORTACloseAll()                    { TRISA = 0xFFFF; LATA = 0;} /*Close PortA configuration, brings to default condition*/
#define mPORTACloseBits(_bits)              { TRISA |= (unsigned int)_bits; LATA &= ~(unsigned int)_bits;} /*Close PortA bit configuration*/

#endif

#if defined (port_v1_1) || defined (port_v1_2)|| defined (port_v1_3) || defined (port_v1_4) 
/*PORTB Macros*/
#define mPORTBConfig(tris)                  { TRISB = (unsigned int)tris;   }/* Configure PortA*/
#define mPORTBRead()                        (PORTB)/*Read PortB*/
#define mPORTBWrite(lat)                    { LATB = (unsigned int)lat;}/*Write PortB*/
#define mPORTBReadLatch()                   (LATB)/*Reads PortB Latch*/
#define mPORTBGetConfig()                   (TRISB)/*Reads PortB Configuration value*/
#define mPORTBReadBit(_bit)                 (PORTB & (unsigned int)_bit)/*Reads given PortB bit value*/
#define mPORTBReadLatchBit(_bit)            (LATB & (unsigned int)_bit)/*Reads given PortB bit latch value*/
#define mPORTBReadConfigBit(_bit)           (TRISB & (unsigned int)_bit)/*Reads configuration of given PortB bit */
#define mPORTBOutputConfig(outputs)         { TRISB &= ~(unsigned int)outputs;}/*Configures PortB as output*/
#define mPORTBInputConfig(inputs)           { TRISB |= (unsigned int)inputs;} /*Configures PortB as input*/
#define mPORTBSetBits(_bits)                { LATB |= (unsigned int)_bits; }/*Set PortB bit*/
#define mPORTBClearBits(_bits)              { LATB &= ~(unsigned int)_bits;}/*Clears PortB bit*/
#define mPORTBToggleBits(_bits)             { LATB ^= (unsigned int)_bits; }/*Toggles given PortB bit*/
#define mPORTBCloseAll()                    { TRISB = 0xFFFF; LATB = 0; }/*Close PortB configuration, brings to default condition*/
#define mPORTBCloseBits(_bits)              { TRISB |= (unsigned int)_bits; LATB &= ~(unsigned int)_bits;}/*Close PortB bit configuration*/

#endif  //end PORTB

#if defined (port_v1_2)|| defined (port_v1_3)|| defined (port_v1_4)
/*PORTC Macros*/
#define mPORTCConfig(tris)                  { TRISC = (unsigned int)tris;   }/* Configure PortA*/
#define mPORTCRead()                        (PORTC) /*Read PortA*/
#define mPORTCWrite(lat)                    { LATC = (unsigned int)lat;}/*Write PortA*/
#define mPORTCReadLatch()                   (LATC)/*Reads PortA Latch*/
#define mPORTCGetConfig()                   (TRISC)/*Reads PortC Configuration value*/
#define mPORTCReadBit(_bit)                 (PORTC & (unsigned int)_bit)/*Reads given PortC bit value*/
#define mPORTCReadLatchBit(_bit)            (LATC & (unsigned int)_bit) /*Reads given PortC bit latch value*/
#define mPORTCReadConfigBit(_bit)           (TRISC & (unsigned int)_bit)/*Reads configuration of given PortC bit */
#define mPORTCOutputConfig(outputs)         { TRISC &= ~(unsigned int)outputs;  }/*Configures PortC as output*/
#define mPORTCInputConfig(inputs)           { TRISC |= (unsigned int)inputs;    }/*Configures PortC as input*/
#define mPORTCSetBits(_bits)                { LATC |= (unsigned int)_bits;      }/*Set PortC bit*/
#define mPORTCClearBits(_bits)              { LATC &= ~(unsigned int)_bits;     }/*Clears PortC bit*/
#define mPORTCToggleBits(_bits)             { LATC ^= (unsigned int)_bits;      }/*Toggles given PortC bit*/
#define mPORTCCloseAll()                    { TRISC = 0xFFFF; LATC = 0;         }/*Close PortC configuration, brings to default condition*/
#define mPORTCCloseBits(_bits)              { TRISC |= (unsigned int)_bits; LATC &= ~(unsigned int)_bits;     } /*Close PortC bit configuration*/
#endif

/******************************************************************
Macro       : EnableIntInputChange
 
Include     : ports.h
 
Description : This macro enables the input change interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableIntInputChange    (IEC1bits.CNIE = 1)

/******************************************************************
Macro       : DisableIntInputChange
 
Include     : ports.h
 
Description : This macro disables the input change interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableIntInputChange    (IEC1bits.CNIE = 0)

/******************************************************************
Macro       : SetPriorityIntInputChange(priority)
 
Include     : ports.h
 
Description : This macro sets priority for input change interrupt.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : None
********************************************************************/
#define SetPriorityIntInputChange(priority)  (IPC4bits.CNIP = priority)

/*******************************************************************
Macro       : InputChange_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear input change Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define InputChange_Clear_Intr_Status_Bit     (IFS1bits.CNIF = 0)

void __attribute__ ((section (".libperi")))ConfigIntCN(unsigned int config) ;
void __attribute__ ((section (".libperi")))CloseIntCN(void) ;


#if defined (int_v1_1) || defined (int_v1_2) || defined(LIB_BUILD)
/******************************************************************
Macro       : EnableINT0
 
Include     : ports.h
 
Description : This macro enables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableINT0              (IEC0bits.INT0IE = 1)

/******************************************************************
Macro       : DisableINT0
 
Include     : ports.h
 
Description : This macro disables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableINT0             (IEC0bits.INT0IE = 0)

/******************************************************************
Macro       : SetPriorityInt0(priority)
 
Include     : ports.h
 
Description : This macro sets priority for external interrupts.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : This macro sets External Interrupt Priority bits of 
              Interrupt Priority Control register.
********************************************************************/
#define SetPriorityInt0(priority)     (IPC0bits.INT0IP = priority)

/*******************************************************************
Macro       : Int0_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define Int0_Clear_Intr_Status_Bit     (IFS0bits.INT0IF = 0)

/******************************************************************
Macro       : EnableINT1
 
Include     : ports.h
 
Description : This macro enables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableINT1            (IEC1bits.INT1IE = 1)

/******************************************************************
Macro       : DisableINT1
 
Include     : ports.h
 
Description : This macro disables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableINT1           (IEC1bits.INT1IE = 0)

/******************************************************************
Macro       : SetPriorityInt1(priority)
 
Include     : ports.h
 
Description : This macro sets priority for external interrupts.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : This macro sets External Interrupt Priority bits of 
              Interrupt Priority Control register.
********************************************************************/
#define SetPriorityInt1(priority)     (IPC5bits.INT1IP = priority)

/*******************************************************************
Macro       : Int1_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define Int1_Clear_Intr_Status_Bit     (IFS1bits.INT1IF = 0)

/******************************************************************
Macro       : EnableINT2
 
Include     : ports.h
 
Description : This macro enables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableINT2              (IEC1bits.INT2IE = 1)

/******************************************************************
Macro       : DisableINT2
 
Include     : ports.h
 
Description : This macro disables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableINT2             (IEC1bits.INT2IE = 0)

/******************************************************************
Macro       : SetPriorityInt2(priority)
 
Include     : ports.h
 
Description : This macro sets priority for external interrupts.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : This macro sets External Interrupt Priority bits of 
              Interrupt Priority Control register.
********************************************************************/
#define SetPriorityInt2(priority)     (IPC7bits.INT2IP = priority)

/*******************************************************************
Macro       : Int2_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define Int2_Clear_Intr_Status_Bit     (IFS1bits.INT2IF = 0)

void __attribute__ ((section (".libperi"))) ConfigINT0(unsigned int config) ;

void __attribute__ ((section (".libperi"))) CloseINT0(void);

void __attribute__ ((section (".libperi"))) ConfigINT1(unsigned int config);

void __attribute__ ((section (".libperi"))) CloseINT1(void);

void  __attribute__ ((section (".libperi"))) ConfigINT2(unsigned int config);

void  __attribute__ ((section (".libperi")))CloseINT2(void);

#endif 

#if defined (int_v1_2) || defined(LIB_BUILD)
/******************************************************************
Macro       : EnableINT3
 
Include     : ports.h
 
Description : This macro enables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableINT3             (IEC3bits.INT3IE = 1)

/******************************************************************
Macro       : DisableINT3
 
Include     : ports.h
 
Description : This macro disables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableINT3             (IEC3bits.INT3IE = 0)

/******************************************************************
Macro       : SetPriorityInt3(priority)
 
Include     : ports.h
 
Description : This macro sets priority for external interrupts.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : This macro sets External Interrupt Priority bits of 
              Interrupt Priority Control register.
********************************************************************/
#define SetPriorityInt3(priority)     (IPC13bits.INT3IP = priority)

/*******************************************************************
Macro       : Int3_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define Int3_Clear_Intr_Status_Bit     (IFS3bits.INT3IF = 0)

/******************************************************************
Macro       : EnableINT4
 
Include     : ports.h
 
Description : This macro enables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define EnableINT4             (IEC3bits.INT4IE = 1)

/******************************************************************
Macro       : DisableINT4
 
Include     : ports.h
 
Description : This macro disables the individual external interrupt.
               
Arguments   : None
 
Remarks     : None 
********************************************************************/
#define DisableINT4            (IEC3bits.INT4IE = 0)

/******************************************************************
Macro       : SetPriorityInt4(priority)
 
Include     : ports.h
 
Description : This macro sets priority for external interrupts.
 
Arguments   : priority - This input parameter is the level of interrupt priority
 
Remarks     : This macro sets External Interrupt Priority bits of 
              Interrupt Priority Control register.
********************************************************************/
#define SetPriorityInt4(priority)     (IPC13bits.INT4IP = priority)

/*******************************************************************
Macro       : Int4_Clear_Intr_Status_Bit

Include     : ports.h 

Description : Macro to Clear external Interrupt Status bit 

Arguments   : None 

Remarks     : None 
*******************************************************************/
#define Int4_Clear_Intr_Status_Bit     (IFS3bits.INT4IF = 0)


void __attribute__ ((section (".libperi"))) ConfigINT3(unsigned int config);

void __attribute__ ((section (".libperi"))) CloseINT3(void);

void __attribute__ ((section (".libperi"))) ConfigINT4(unsigned int config) ;

void __attribute__ ((section (".libperi"))) CloseINT4(void);

#endif /* _INT4 */

#endif
