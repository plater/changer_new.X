/*
 * main.c
 *
 *  Created on: 07 Jul 2026
 *      Author: davejplater@gmail.com
 */

			
#include "buffers.h"

uint8_t iobuf;
uint16_t shcred;
volatile uint32_t timer;
volatile uint32_t tstore;
volatile uint32_t elapsed;
volatile int s;

void main(void)
{
    SYSTEM_Initialize();
    lcd_init();
    dly_msec(500);
	lcd_write_string("0123456789ABCDEF");
	if(!SERVICE)
	{
		store_credit(0);
		store_error(0);
		lcd_write_string("Push R5 to empty");
	}
	do
	{
		CLRWDT();
		if(!BUTR5)
		{
			empty_hoppers();
		}
	}while(!SERVICE);
	errorflg = retrieve_error();
	if(errorflg == 8)	
	{
		call_joe();
	}
	credit = retrieve_credit();
	if(credit)
	{
		credisp();
	}
	else
	{
		loadincoin();
	}
	scrollpos = 0;
	int x = 0;
	shcred = credit;
	uint32_t elapsed;
	uint32_t tstore2;
	uint32_t tstore4;
	uint8_t timeout = 0;
	Starttim5();
	s = 0;
    while (true) 
	{
		CLRWDT();
		x = R10IN | R01IN;
		while(x)
		{
			if(R10IN)
			{
				tens_in();
				x = 10;
			}
			if(R01IN)
			{
				ones_in();
				x = 1;
			}
			x = R10IN | R01IN;
		}
		if(credit)
		{
			process_credit();
			s = 0;
		}
		else
		{
			if(s == 0)
			{
				loadincoin();
				s = 1;
			}
		}
		if(credit >= 10)
		{
			NOTEDS();
		}
		if(PIR4bits.TMR5IF) //500 mSec
		{
            Starttim5();
			credit = retrieve_credit();
			if(credit)
			{
				if(shcred != credit)
				{
					credisp();
					shcred = credit;
				}
			}
			else
			{
				NOTEEN();
				lcd_scroll_string(msgbuf);
			}
/*			if(!SERVICE)
			{
				credit = retrieve_credit();
				credit = credit + 5;
				store_credit(credit);
			}
			while(!SERVICE)
			{
				CLRWDT();
				
			}*/
		}
    }
}









