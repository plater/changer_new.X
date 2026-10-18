/*
 *test.c
 *
 *  Created on: Sat 05 Sep 2026 11:38:24 SAST

 *      Author: davejplater@gmail.com
 */
 
#include "buffers.h"


void empty_hoppers(void)
{
	volatile uint8_t y;
	volatile int posit = 0;
	while(SERVICE){}
	lcd_write_string("Empty R1 push R2");
	repeat:
	if(!BUTR2)
	{
		switch(posit)
		{
			case 0 : y = empty_r1();
            memset(msgbuf, 0, 32);
			sprintf(msgbuf, "R1 count %d", y);
			break;
			case 1 : y = empty_r2();
            memset(msgbuf, 0, 32);
			sprintf(msgbuf, "R2 count %d", y);
			break;
			case 2 : y = empty_r5();
            memset(msgbuf, 0, 32);
			sprintf(msgbuf, "R5 count %d", y);
			break;
			case 3 : goto exit;
		}
		lcd_write_string(msgbuf);
		while(!BUTR2)
		{
			CLRWDT();
		}
	}
	if(!BUTR5)
	{
		posit++;
		posit = posit & 0x3;
		switch(posit)
		{
			case 0 : sprintf(msgbuf, "Empty R1 coins");
			break;
			case 1 : sprintf(msgbuf, "Empty R2 coins");
			break;
			case 2 : sprintf(msgbuf, "Empty R5 coins");
			break;
			case 3 : sprintf(msgbuf, "Exit");
			break;
			default : posit = 0;
		}
		lcd_write_string(msgbuf);
		while(!BUTR5)
		{
			CLRWDT();
		}
	}
	CLRWDT();
	goto repeat;
	exit:;
    CLRWDT();
}


//!PIR0bits.TMR0IF
uint8_t empty_r1(void)
{
	volatile int x;
	uint8_t count = 0;
	lcd_write_string("Empty R1 hopper");
	while(!BUTR2)
	{
		CLRWDT();
	}
    
	LATBbits.LATB0 = 1;
    dly_msec(20);
    R1BEG:
    Starttim1();
    do
	{
		x = PORTAbits.RA4;
		if(TMR1_HasOverflowOccured())
		{
			R1OFF;
			goto R1FIN;
		}
	}while(x == 0);
	CLRWDT();	
    //R1OFF;
	count++;
	do
	{
		x = PORTAbits.RA4;
	}while(x != 0);
	sprintf(msgbuf, "count %d coins", count);
	lcd_write_string(msgbuf);
	goto R1BEG;
	R1FIN:
	R1OFF;
	return count;
}

uint8_t empty_r2(void)
{
	volatile int x;
	uint32_t elapsed;
	uint16_t timeout;
	uint8_t count = 0;
	lcd_write_string("Empty R2 hopper");
	while(!BUTR2)
	{
		CLRWDT();
	}
	timeout = 0;
	R2ON;
	dly_msec(3);
	R2BEG:
    Starttim1();
    while(R2sense)
	{
		CLRWDT();
		if(PIR4bits.TMR1IF)
		{
			R1OFF;
			goto R2FIN;
		}
	}
		
		count++;
	while(!R2sense)
	{
		CLRWDT();
	}
	sprintf(msgbuf, "dispensed %d coins", count);
	lcd_write_string(msgbuf);
	goto R2BEG;
	R2FIN:
	R2OFF;
	return count;
}

uint8_t empty_r5(void)
{
	volatile int x;
	uint32_t elapsed;
	uint16_t timeout;
	uint8_t count = 0;
	lcd_write_string("Empty R5 hopper");
	while(!BUTR2)
	{
		CLRWDT();
	}
	timeout = 0;
	R5ON();
	dly_msec(3);
	R5BEG:
    Starttim1();
    while(R5sense)
	{
		CLRWDT();
		if(PIR4bits.TMR1IF)
		{
			R5OFF();
			goto R5FIN;
		}
	}
		
		count++;
	while(!R5sense)
	{
		CLRWDT();
	}
	sprintf(msgbuf, "dispensed %d coins", count);
	lcd_write_string(msgbuf);
	goto R5BEG;
	R5FIN:
	R5OFF();
	return count;
}




