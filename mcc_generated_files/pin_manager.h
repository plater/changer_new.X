/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SERVICE aliases
#define SERVICE_TRIS                 TRISAbits.TRISA0
#define SERVICE_LAT                  LATAbits.LATA0
#define SERVICE_PORT                 PORTAbits.RA0
#define SERVICE_WPU                  WPUAbits.WPUA0
#define SERVICE_OD                   ODCONAbits.ODCA0
#define SERVICE_ANS                  ANSELAbits.ANSELA0
#define SERVICE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SERVICE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SERVICE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SERVICE_GetValue()           PORTAbits.RA0
#define SERVICE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SERVICE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SERVICE_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SERVICE_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SERVICE_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SERVICE_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SERVICE_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define SERVICE_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set SPR aliases
#define SPR_TRIS                 TRISAbits.TRISA1
#define SPR_LAT                  LATAbits.LATA1
#define SPR_PORT                 PORTAbits.RA1
#define SPR_WPU                  WPUAbits.WPUA1
#define SPR_OD                   ODCONAbits.ODCA1
#define SPR_ANS                  ANSELAbits.ANSELA1
#define SPR_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SPR_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SPR_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SPR_GetValue()           PORTAbits.RA1
#define SPR_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SPR_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SPR_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SPR_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SPR_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define SPR_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define SPR_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define SPR_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set R2sense aliases
#define R2sense_TRIS                 TRISAbits.TRISA2
#define R2sense_LAT                  LATAbits.LATA2
#define R2sense_PORT                 PORTAbits.RA2
#define R2sense_WPU                  WPUAbits.WPUA2
#define R2sense_OD                   ODCONAbits.ODCA2
#define R2sense_ANS                  ANSELAbits.ANSELA2
#define R2sense_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define R2sense_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define R2sense_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define R2sense_GetValue()           PORTAbits.RA2
#define R2sense_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define R2sense_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define R2sense_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define R2sense_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define R2sense_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define R2sense_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define R2sense_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define R2sense_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set R5sense aliases
#define R5sense_TRIS                 TRISAbits.TRISA3
#define R5sense_LAT                  LATAbits.LATA3
#define R5sense_PORT                 PORTAbits.RA3
#define R5sense_WPU                  WPUAbits.WPUA3
#define R5sense_OD                   ODCONAbits.ODCA3
#define R5sense_ANS                  ANSELAbits.ANSELA3
#define R5sense_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define R5sense_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define R5sense_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define R5sense_GetValue()           PORTAbits.RA3
#define R5sense_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define R5sense_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define R5sense_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define R5sense_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define R5sense_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define R5sense_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define R5sense_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define R5sense_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set R1sense aliases
#define R1sense_TRIS                 TRISAbits.TRISA4
#define R1sense_LAT                  LATAbits.LATA4
#define R1sense_PORT                 PORTAbits.RA4
#define R1sense_WPU                  WPUAbits.WPUA4
#define R1sense_OD                   ODCONAbits.ODCA4
#define R1sense_ANS                  ANSELAbits.ANSELA4
#define R1sense_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define R1sense_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define R1sense_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define R1sense_GetValue()           PORTAbits.RA4
#define R1sense_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define R1sense_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define R1sense_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define R1sense_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define R1sense_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define R1sense_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define R1sense_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define R1sense_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS                 TRISAbits.TRISA5
#define IO_RA5_LAT                  LATAbits.LATA5
#define IO_RA5_PORT                 PORTAbits.RA5
#define IO_RA5_WPU                  WPUAbits.WPUA5
#define IO_RA5_OD                   ODCONAbits.ODCA5
#define IO_RA5_ANS                  ANSELAbits.ANSELA5
#define IO_RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_RA5_GetValue()           PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_RA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_RA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_RA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_RA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_RA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define IO_RA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set NOTEEN0 aliases
#define NOTEEN0_TRIS                 TRISAbits.TRISA6
#define NOTEEN0_LAT                  LATAbits.LATA6
#define NOTEEN0_PORT                 PORTAbits.RA6
#define NOTEEN0_WPU                  WPUAbits.WPUA6
#define NOTEEN0_OD                   ODCONAbits.ODCA6
#define NOTEEN0_ANS                  ANSELAbits.ANSELA6
#define NOTEEN0_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define NOTEEN0_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define NOTEEN0_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define NOTEEN0_GetValue()           PORTAbits.RA6
#define NOTEEN0_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define NOTEEN0_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define NOTEEN0_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define NOTEEN0_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define NOTEEN0_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define NOTEEN0_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define NOTEEN0_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define NOTEEN0_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set IO_RA7 aliases
#define IO_RA7_TRIS                 TRISAbits.TRISA7
#define IO_RA7_LAT                  LATAbits.LATA7
#define IO_RA7_PORT                 PORTAbits.RA7
#define IO_RA7_WPU                  WPUAbits.WPUA7
#define IO_RA7_OD                   ODCONAbits.ODCA7
#define IO_RA7_ANS                  ANSELAbits.ANSELA7
#define IO_RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_RA7_GetValue()           PORTAbits.RA7
#define IO_RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_RA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_RA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_RA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_RA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_RA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define IO_RA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set HPR1 aliases
#define HPR1_TRIS                 TRISBbits.TRISB0
#define HPR1_LAT                  LATBbits.LATB0
#define HPR1_PORT                 PORTBbits.RB0
#define HPR1_WPU                  WPUBbits.WPUB0
#define HPR1_OD                   ODCONBbits.ODCB0
#define HPR1_ANS                  ANSELBbits.ANSELB0
#define HPR1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define HPR1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define HPR1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define HPR1_GetValue()           PORTBbits.RB0
#define HPR1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define HPR1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define HPR1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define HPR1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define HPR1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define HPR1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define HPR1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define HPR1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set HPR1b aliases
#define HPR1b_TRIS                 TRISBbits.TRISB1
#define HPR1b_LAT                  LATBbits.LATB1
#define HPR1b_PORT                 PORTBbits.RB1
#define HPR1b_WPU                  WPUBbits.WPUB1
#define HPR1b_OD                   ODCONBbits.ODCB1
#define HPR1b_ANS                  ANSELBbits.ANSELB1
#define HPR1b_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define HPR1b_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define HPR1b_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define HPR1b_GetValue()           PORTBbits.RB1
#define HPR1b_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define HPR1b_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define HPR1b_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define HPR1b_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define HPR1b_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define HPR1b_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define HPR1b_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define HPR1b_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set HPR2 aliases
#define HPR2_TRIS                 TRISBbits.TRISB2
#define HPR2_LAT                  LATBbits.LATB2
#define HPR2_PORT                 PORTBbits.RB2
#define HPR2_WPU                  WPUBbits.WPUB2
#define HPR2_OD                   ODCONBbits.ODCB2
#define HPR2_ANS                  ANSELBbits.ANSELB2
#define HPR2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define HPR2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define HPR2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define HPR2_GetValue()           PORTBbits.RB2
#define HPR2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define HPR2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define HPR2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define HPR2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define HPR2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define HPR2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define HPR2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define HPR2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set HPR2b aliases
#define HPR2b_TRIS                 TRISBbits.TRISB3
#define HPR2b_LAT                  LATBbits.LATB3
#define HPR2b_PORT                 PORTBbits.RB3
#define HPR2b_WPU                  WPUBbits.WPUB3
#define HPR2b_OD                   ODCONBbits.ODCB3
#define HPR2b_ANS                  ANSELBbits.ANSELB3
#define HPR2b_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define HPR2b_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define HPR2b_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define HPR2b_GetValue()           PORTBbits.RB3
#define HPR2b_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define HPR2b_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define HPR2b_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define HPR2b_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define HPR2b_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define HPR2b_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define HPR2b_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define HPR2b_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set NOTE aliases
#define NOTE_TRIS                 TRISBbits.TRISB4
#define NOTE_LAT                  LATBbits.LATB4
#define NOTE_PORT                 PORTBbits.RB4
#define NOTE_WPU                  WPUBbits.WPUB4
#define NOTE_OD                   ODCONBbits.ODCB4
#define NOTE_ANS                  ANSELBbits.ANSELB4
#define NOTE_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define NOTE_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define NOTE_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define NOTE_GetValue()           PORTBbits.RB4
#define NOTE_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define NOTE_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define NOTE_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define NOTE_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define NOTE_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define NOTE_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define NOTE_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define NOTE_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set COIN aliases
#define COIN_TRIS                 TRISBbits.TRISB5
#define COIN_LAT                  LATBbits.LATB5
#define COIN_PORT                 PORTBbits.RB5
#define COIN_WPU                  WPUBbits.WPUB5
#define COIN_OD                   ODCONBbits.ODCB5
#define COIN_ANS                  ANSELBbits.ANSELB5
#define COIN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define COIN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define COIN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define COIN_GetValue()           PORTBbits.RB5
#define COIN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define COIN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define COIN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define COIN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define COIN_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define COIN_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define COIN_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define COIN_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set NOTEEN aliases
#define NOTEEN_TRIS                 TRISCbits.TRISC3
#define NOTEEN_LAT                  LATCbits.LATC3
#define NOTEEN_PORT                 PORTCbits.RC3
#define NOTEEN_WPU                  WPUCbits.WPUC3
#define NOTEEN_OD                   ODCONCbits.ODCC3
#define NOTEEN_ANS                  ANSELCbits.ANSELC3
#define NOTEEN_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define NOTEEN_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define NOTEEN_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define NOTEEN_GetValue()           PORTCbits.RC3
#define NOTEEN_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define NOTEEN_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define NOTEEN_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define NOTEEN_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define NOTEEN_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define NOTEEN_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define NOTEEN_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define NOTEEN_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set R5BUT aliases
#define R5BUT_TRIS                 TRISCbits.TRISC4
#define R5BUT_LAT                  LATCbits.LATC4
#define R5BUT_PORT                 PORTCbits.RC4
#define R5BUT_WPU                  WPUCbits.WPUC4
#define R5BUT_OD                   ODCONCbits.ODCC4
#define R5BUT_ANS                  ANSELCbits.ANSELC4
#define R5BUT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define R5BUT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define R5BUT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define R5BUT_GetValue()           PORTCbits.RC4
#define R5BUT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define R5BUT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define R5BUT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define R5BUT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define R5BUT_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define R5BUT_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define R5BUT_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define R5BUT_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set R2BUT aliases
#define R2BUT_TRIS                 TRISCbits.TRISC5
#define R2BUT_LAT                  LATCbits.LATC5
#define R2BUT_PORT                 PORTCbits.RC5
#define R2BUT_WPU                  WPUCbits.WPUC5
#define R2BUT_OD                   ODCONCbits.ODCC5
#define R2BUT_ANS                  ANSELCbits.ANSELC5
#define R2BUT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define R2BUT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define R2BUT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define R2BUT_GetValue()           PORTCbits.RC5
#define R2BUT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define R2BUT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define R2BUT_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define R2BUT_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define R2BUT_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define R2BUT_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define R2BUT_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define R2BUT_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCD0 aliases
#define LCD0_TRIS                 TRISDbits.TRISD0
#define LCD0_LAT                  LATDbits.LATD0
#define LCD0_PORT                 PORTDbits.RD0
#define LCD0_WPU                  WPUDbits.WPUD0
#define LCD0_OD                   ODCONDbits.ODCD0
#define LCD0_ANS                  ANSELDbits.ANSELD0
#define LCD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCD0_GetValue()           PORTDbits.RD0
#define LCD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define LCD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define LCD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define LCD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define LCD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define LCD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LCD1 aliases
#define LCD1_TRIS                 TRISDbits.TRISD1
#define LCD1_LAT                  LATDbits.LATD1
#define LCD1_PORT                 PORTDbits.RD1
#define LCD1_WPU                  WPUDbits.WPUD1
#define LCD1_OD                   ODCONDbits.ODCD1
#define LCD1_ANS                  ANSELDbits.ANSELD1
#define LCD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LCD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LCD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LCD1_GetValue()           PORTDbits.RD1
#define LCD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LCD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LCD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LCD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LCD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LCD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LCD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LCD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set LCD2 aliases
#define LCD2_TRIS                 TRISDbits.TRISD2
#define LCD2_LAT                  LATDbits.LATD2
#define LCD2_PORT                 PORTDbits.RD2
#define LCD2_WPU                  WPUDbits.WPUD2
#define LCD2_OD                   ODCONDbits.ODCD2
#define LCD2_ANS                  ANSELDbits.ANSELD2
#define LCD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LCD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LCD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LCD2_GetValue()           PORTDbits.RD2
#define LCD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LCD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LCD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LCD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LCD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LCD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LCD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define LCD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set LCD3 aliases
#define LCD3_TRIS                 TRISDbits.TRISD3
#define LCD3_LAT                  LATDbits.LATD3
#define LCD3_PORT                 PORTDbits.RD3
#define LCD3_WPU                  WPUDbits.WPUD3
#define LCD3_OD                   ODCONDbits.ODCD3
#define LCD3_ANS                  ANSELDbits.ANSELD3
#define LCD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LCD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LCD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LCD3_GetValue()           PORTDbits.RD3
#define LCD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LCD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LCD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define LCD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define LCD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define LCD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define LCD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define LCD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set HPR5 aliases
#define HPR5_TRIS                 TRISDbits.TRISD4
#define HPR5_LAT                  LATDbits.LATD4
#define HPR5_PORT                 PORTDbits.RD4
#define HPR5_WPU                  WPUDbits.WPUD4
#define HPR5_OD                   ODCONDbits.ODCD4
#define HPR5_ANS                  ANSELDbits.ANSELD4
#define HPR5_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define HPR5_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define HPR5_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define HPR5_GetValue()           PORTDbits.RD4
#define HPR5_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define HPR5_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define HPR5_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define HPR5_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define HPR5_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define HPR5_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define HPR5_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define HPR5_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set HPR5b aliases
#define HPR5b_TRIS                 TRISDbits.TRISD5
#define HPR5b_LAT                  LATDbits.LATD5
#define HPR5b_PORT                 PORTDbits.RD5
#define HPR5b_WPU                  WPUDbits.WPUD5
#define HPR5b_OD                   ODCONDbits.ODCD5
#define HPR5b_ANS                  ANSELDbits.ANSELD5
#define HPR5b_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define HPR5b_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define HPR5b_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define HPR5b_GetValue()           PORTDbits.RD5
#define HPR5b_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define HPR5b_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define HPR5b_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define HPR5b_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define HPR5b_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define HPR5b_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define HPR5b_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define HPR5b_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set HPR5c aliases
#define HPR5c_TRIS                 TRISDbits.TRISD6
#define HPR5c_LAT                  LATDbits.LATD6
#define HPR5c_PORT                 PORTDbits.RD6
#define HPR5c_WPU                  WPUDbits.WPUD6
#define HPR5c_OD                   ODCONDbits.ODCD6
#define HPR5c_ANS                  ANSELDbits.ANSELD6
#define HPR5c_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define HPR5c_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define HPR5c_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define HPR5c_GetValue()           PORTDbits.RD6
#define HPR5c_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define HPR5c_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define HPR5c_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define HPR5c_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define HPR5c_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define HPR5c_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define HPR5c_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define HPR5c_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set HPR5d aliases
#define HPR5d_TRIS                 TRISDbits.TRISD7
#define HPR5d_LAT                  LATDbits.LATD7
#define HPR5d_PORT                 PORTDbits.RD7
#define HPR5d_WPU                  WPUDbits.WPUD7
#define HPR5d_OD                   ODCONDbits.ODCD7
#define HPR5d_ANS                  ANSELDbits.ANSELD7
#define HPR5d_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define HPR5d_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define HPR5d_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define HPR5d_GetValue()           PORTDbits.RD7
#define HPR5d_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define HPR5d_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define HPR5d_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define HPR5d_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define HPR5d_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define HPR5d_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define HPR5d_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define HPR5d_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set E aliases
#define E_TRIS                 TRISEbits.TRISE0
#define E_LAT                  LATEbits.LATE0
#define E_PORT                 PORTEbits.RE0
#define E_WPU                  WPUEbits.WPUE0
#define E_OD                   ODCONEbits.ODCE0
#define E_ANS                  ANSELEbits.ANSELE0
#define E_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define E_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define E_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define E_GetValue()           PORTEbits.RE0
#define E_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define E_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define E_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define E_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define E_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define E_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define E_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define E_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set R_W aliases
#define R_W_TRIS                 TRISEbits.TRISE1
#define R_W_LAT                  LATEbits.LATE1
#define R_W_PORT                 PORTEbits.RE1
#define R_W_WPU                  WPUEbits.WPUE1
#define R_W_OD                   ODCONEbits.ODCE1
#define R_W_ANS                  ANSELEbits.ANSELE1
#define R_W_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define R_W_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define R_W_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define R_W_GetValue()           PORTEbits.RE1
#define R_W_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define R_W_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define R_W_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define R_W_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define R_W_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define R_W_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define R_W_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define R_W_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set RS aliases
#define RS_TRIS                 TRISEbits.TRISE2
#define RS_LAT                  LATEbits.LATE2
#define RS_PORT                 PORTEbits.RE2
#define RS_WPU                  WPUEbits.WPUE2
#define RS_OD                   ODCONEbits.ODCE2
#define RS_ANS                  ANSELEbits.ANSELE2
#define RS_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define RS_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define RS_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define RS_GetValue()           PORTEbits.RE2
#define RS_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define RS_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define RS_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define RS_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define RS_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define RS_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/