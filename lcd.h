/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:    lcd.h c prototypes for lcd.c  
 * Author:  Dave Plater
 * Comments:
 * Revision history: 2017/10/06
 */
#pragma once
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LCD_H
#define	LCD_H

#include "buffers.h"
//#include <p18f47k40.h>

#include <xc.h> // include processor files - each processor file is guarded. 
signed char count;
//Various lcd display constants
volatile const char dispfunc2 = 0x07;
volatile const char dispon = 0x0C;	//Display on, cursor off and blink off
volatile const char dispclr = 0x01;	//Write 20h to entire display
volatile const char dispaddr = 0xA8;	//Upper 8 digit address
volatile const char dsphome = 0x02;	//Select leftmost digit
volatile const char dispnormal = 0x06;	//Static, increment address on write/read
volatile const char dispcursor = 0x04;  // Switch on flashing cursor
volatile const char dispshright = 0x05;	//Shift display right, increment address on write/read
volatile const char dispshleft = 0x07;	//Shift display left, increment address on write/read
volatile const char dispoff = 0x08;	//Display off
volatile const char dispsr = 0x1B;	//Display shift right
volatile const char dispsl = 0x18;	//Display shift left
//Line one is 0 to 7
volatile const char line1 = 0x00;
//Line two is 8 t0 15
volatile const char line2 = 0x40;

//Message strings for 20x4 LCD
const uint8_t clrline[] ="                    ";
const uint8_t inscoin[] = "Insert Notes & PressLit Button To Vend" ;
const uint8_t nochange[] = "No Change Use Exact      Amount!";
const uint8_t credits[] = "  Credit = R";
const uint8_t emptymsg[] = "No Stock";
const uint8_t pricesetmsg[] = "   Price set mode";
const uint8_t pricesetm2[] = "Press channel button    to set price      Service = Exit";
const uint8_t vendsetup[] = "Push 1 Vend Time,   2 ChanLink 3 SensOff4 ClrTot 5 FacReset 8 exit";
const uint8_t setimemsg[] = "Push channel button Push service to exit";
const uint8_t sensoffms[] = "Hold channel button or Push service to  exit";
const uint8_t vendtimem[] = "Push 1 = +.5 second Push 2 = -.5 second ";
const uint8_t chanlinkm[] = "Press channel button    to link to      Service = Exit";
const uint8_t linkmsg[] = "linked to :";
const uint8_t chanmsg[] = "   Channel ";
const uint8_t timemsg[] = "Time in 1/2sec = ";
const uint8_t pricemsg[] = "Price R";
const uint8_t priceexit[] ="Press service to exit";
const uint8_t auditmsg[] = "  Audit Mode";
const uint8_t hoppcoin[] = "Hopper Coin         Button 1 = + & 2 = - Value = R";
const uint8_t senset[] = "  Setup Sensor";
const uint8_t credclr[] = "Push button 1 to clear credits   and exit";
const uint8_t vendtest[] = " Push button to     vend";
const uint8_t notetest[] = "  Insert Note";
//const uint8_t exit[] = "Exit";
const uint8_t servmsg[] = "1 = Audit 2 = Sensor3=Hop-Coin 4=Note-en5=Cred-clr 6=Prices 7=Vend setup 8=Exit";
const uint8_t noteerr[] = "   Note error     code = 0x";
const uint8_t inithop[] = "  Initialize Hopper";
const uint8_t initnote[] = "     Initialize          Note Reader";
const uint8_t setnotes[] = "Enable / Disable    1 = R10, 2 = R20    3 = R50, 4 = R100   5 = R200";
const uint8_t tenrand[] = "   R10  ";
const uint8_t twentyrand[] = "  R20  ";
const uint8_t fiftyrand[] = "  R50  ";
const uint8_t hundredrand[] = "  R100 ";
const uint8_t twohundredrand[] = "  R200 ";
const uint8_t enabled[] = " enabled ";
const uint8_t disabled[] = " disabled";
const uint8_t creditclr[] = "Credits Cleared";
const uint8_t sensmsg[] = "Sensor is ";
const uint8_t onmsg[] = "On ";
const uint8_t offmsg[] = "Off";
const uint8_t clrmsg[] = "         ";
const uint8_t dacmsg[] = "Sensitivity ";
const uint8_t motimemsg[] = " Press Channel Vend Button or Press       Service to Exit";
const uint8_t settimemsg[] = "Press 1 = + or 2 = -  Press 8 to Exit";
const uint8_t chanlinkmsg[] = "Push Button to Link Push again to UnlinkPush Service to Exit";
const uint8_t chanresetmsg[] = "Reset to Default    Start Again";
const uint8_t sensoffmsg[] = "Push 1 = On, 2 = Off, 8 = Exit";
const uint8_t totalmsg[] = "Total R";
const uint8_t cashinmsg[] = "Cash in R";
const uint8_t totalvendsm[] = "Vends ";
const uint8_t vendispmsg[] = "Use button / Service";
//const uint8_t clocktime[] = "Time ";
const uint8_t clockdate[] = "Date ";

volatile uint8_t bflag;
volatile uint8_t lcdfunc;
volatile uint8_t lcdata;
volatile uint8_t lcdline;
volatile uint8_t stradd;
__uint24 hexnum;
volatile uint8_t ercode;
volatile uint8_t lcdaddress;

#endif

/**
 End of File
*/


