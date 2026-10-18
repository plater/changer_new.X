/*
 * buffers.h
 *
 *  Created on: 07 July 2026
 *  Converted to PIC18F47K40 18 September 2026
 *      Author: davejplater@gmail.com
 */
#pragma once

#ifndef MAIN_BUFFERS_H_
#define MAIN_BUFFERS_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "lcd.h"
#include "/opt/microchip/mplabx/v5.50/packs/Microchip/PIC18F-K_DFP/1.4.87/xc8/pic/include/proc/pic18f47k40.h""

#define COMHOP

enum { 	PAY_OK = 0,
		HOPPER_EMT = 1,
		HOPPER_JAM  = 2,
	};

#define DLY1SEC()   		__delay_ms(1000)
#define DLYHSEC()   		__delay_ms(500)
#define DLYQSEC()   		__delay_ms(250)
#define DLYMSEC()			__delay_ms(1)
#define DLY5MSEC()			__delay_ms(5)
#define DLYTMSEC()			__delay_ms(10)

/* GPIO Defines */
#define R5sense		PORTAbits.RA3 //R5 universal hopper MKII modified, sensor active low on coin exit
#define R2sense		PORTAbits.RA2 //R2 1980s Azkoyen hopper with added electronic exit sensor, active low on coin exit
#define R1sense		PORTAbits.RA4 //R1 TSP056 compact hopper electronic, active low on coin exit(manual says active high)
#define HPR1		LATBbits.LATB0//R1 hopper active low enable
#define HPR2		LATBbits.LATB2 //R2 hopper  active low enable
#define HPR5		LATDbits.LATD4 //R5 hopper active low enable
#define R1_in		PORTBbits.RB5 // Coin validator pulse input active low one pulse = R1 Coins = R1, R2, R5
#define R10_in		PORTBbits.RB4 /* Bill validator with pulse output active low one pulse = R10. Notes accepted R10, R20 & R50
  A maximum pay of R10 worth of R2 coins, Only one note allowed per transaction and R50 always pays 5 x R2 coins and 8 x R5 coins
  The R1 coins are only used as change ie. A R5 credit will give 2 x R2 and a R1 as change when the R2 button is pressed */
#define BUTR2   	PORTCbits.RC5
#define BUTR5   	PORTCbits.RC4
#define SERVICE 	PORTAbits.RA0
#define NOTEEN()	do{NOTEEN0_SetLow();NOTEEN1_SetLow();}while(0) // Bill validator enable
#define NOTEDS()	do{NOTEEN0_SetHigh();NOTEEN1_SetHigh();}while(0) // Bill validator disable

#define R10IN   !(NOTE_GetValue())
#define R01IN	!(COIN_GetValue())
#define R1cSEN   PORTAbits.RA1
#define R2cSEN   PORTAbits.RA2
#define R5cSEN   PORTAbits.RA3
#define R1SEN   (~(PORTAbits.RA1) & 1)
#define R2SEN   (~(PORTAbits.RA2) & 1)
#define R5SEN   (~(PORTAbits.RA5) & 1)
#define R1OFF	HPR1_SetLow ()
#define R1ON	HPR1_SetHigh()
#define R2OFF	HPR2_SetLow()
#define R2ON	HPR2_SetHigh()
#define R5OFF()	do{LATD = LATD & 0x0F;}while(0)
#define R5ON()	do{LATD = LATD | 0xF0;}while(0)

/* EEPROM */
volatile const uint16_t credmem = 0x00;
volatile const uint16_t errormm = 0x02;

/* Memory allocate */
extern volatile int s;
extern volatile uint16_t credit;
extern volatile uint8_t  errorflg;
extern volatile uint32_t timer;
extern volatile uint32_t tstore;
extern uint16_t shcred;
extern uint8_t iobuf;
extern double tnow;
extern double tpsw;
extern double tstr;
extern uint8_t r10add;
extern uint8_t r1add;
extern char msgbuf[128];
extern char msg16[17];
extern uint8_t scrollpos;
extern size_t msgsize;
extern int* parg;
extern char errormsg[32];
/* Function defines */
void init_gpio(void);

void i2c_init(void);
void dsp_init(void);
void lcd_write_string(const char *str);
void lcd_scroll_string(char *str);
void error_msg(char* errtype);
uint16_t retrieve_credit();
void store_credit(uint16_t x);
void credisp(void);
void loadincoin(void);
void call_joe(void);

void tens_in(void);
void ones_in(void);
void dly_msec(uint16_t msecs);
//uint32_t get_elapsed(void);
//uint16_t get_elapsedm(void);
uint8_t get_io(void);
bool get_pin_level(uint8_t pin);
//void set_io(uint8_t thedata);
void set_pin_level(uint8_t pin, uint32_t value);
uint8_t pay_r1(uint8_t numb);
uint8_t pay_r2(uint8_t numb);
uint8_t pay_r5(uint8_t numb);
void process_credit(void);
void dispense_r1(void);
void dispense_r2(void);
void dispense_r5(void);
void  disable_cn(void);

void store_error(int strclr);
uint16_t retrieve_error(void);
void hopper_emt(int what);

void empty_hoppers(void);
uint8_t empty_r1(void);
uint8_t empty_r2(void);
uint8_t empty_r5(void);

void DATAEE_WriteWord(uint16_t bAdd, uint16_t bData);
uint16_t DATAEE_ReadWord(uint16_t bAdd);


/* LCD prototypes*/
void lcd_dispadd(uint8_t lcdaddress);

void displ_code(uint8_t ercode);

void lcd_init(void);

void lcd_string(uint8_t *, uint8_t lcdline);
//Write to display character
void lcd_writeC(uint8_t);
//Write to display control
void lcd_write(uint8_t);
 //Clocks E high
void lcd_clockH(void);
 //Clocks E low
void lcd_clockL(void);
 //Clocks E low
void lcd_clockE(void);

void disp_clock(void);

void lcd_test(void);

void displ_hex(__uint24);

void displ_price(uint8_t vendprice);

void displ_nochange(void);

void displ_credit(void);

void displ_noteer(void);

void displ_test(void);

void displ_totals(void);

void displ_empty(void);

void displ_sens(uint8_t smsgpos, uint8_t dmsgpos);

void displ_lflags(uint8_t chanel, uint8_t linkflgs);

void displ_sflags(uint8_t senseflags, uint8_t channel, uint8_t chanbit);

void displ_time(uint8_t motortime, uint8_t channel);
//Pointer to note value message displays it.
uint8_t displ_note(uint8_t *notestring);

void displ_nendis(uint8_t notenum);
 //Returns busy and  character position + 1
int8_t read_busy(void);
void Starttim0(void);
void Starttim1(void);
void Starttim3(void);
void Starttim5(void);
void waitforon(void);
bool senseR1(void);

#endif /* MAIN_BUFFERS_H_ */
