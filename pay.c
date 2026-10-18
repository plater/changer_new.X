/*
 * pay.c
 *
 *  Created on: 13 Jul 2026
 *      Author: davejplater@gmail.com
 */
 
 #include "buffers.h"
#include <stdlib.h>
 
 #define MIN_WIDTH (1000 * 10)//Minimum allowable pulse width 10mS
 #define MAX_WIDTH (1000 * 1000)//Maximum allowable pulse width one second
 #define R5speed   (1000 / 3)

 char errormsg[32];
 volatile int x;
 uint16_t payed;
 volatile uint16_t credit;
 volatile uint8_t  errorflg;
 uint32_t numbs; 
 uint32_t crumbs;
 /*
  * TMR1 = 5 seconds 
  * TMR3 = 300mSec
  * TMR5 = 500mSec
  */
 
 
 void register_error(uint8_t what)
 {
	errorflg = retrieve_error();
	errorflg = errorflg + what;
	store_error(errorflg);
 }
 
void dispense_r1(void)
{
	credit = retrieve_credit();
	errorflg = retrieve_error();
	if((errorflg == 1) || (errorflg == 3) || (errorflg == 6) || (errorflg == 8))// R1 hopper not functional
	{
		hopper_emt(1);
		goto error;
	}
	numbs = credit;
	sprintf(msgbuf, "Dispense R1 x %d", (uint16_t)numbs);
	lcd_write_string(msgbuf);
	uint8_t y = pay_r1(numbs);
	switch(y)
	{
		case HOPPER_EMT :	hopper_emt(1);
							break;
		case HOPPER_JAM :	hopper_emt(1);
							break;
		case PAY_OK   	:	goto error;
	}
error:;
}

uint8_t pay_r1(uint8_t numb)
{
	R1ON;
    dly_msec(20);
    nextcoin1:
    Starttim1();
    do
	{
        dly_msec(2);
		x = PORTAbits.RA4;
		if(TMR1_HasOverflowOccured())
		{
			R1OFF;
			register_error(1);
			return HOPPER_EMT;
		}
	}while(x == 0);
    dly_msec(3);
    x = PORTAbits.RA4;
    if(x == 0)
    {
        goto nextcoin1;
    }
	Starttim5();
	do
	{
		CLRWDT();
		if(PIR4bits.TMR5IF)// Allow 500ms for the coin exit
		{
            PIR4bits.TMR5IF = 0;
			R1OFF;
			register_error(1);
			return HOPPER_JAM;
		}
        x = PORTAbits.RA4;
	}while(x == 1);// Coin on it's way out
		--numb;
		if(numb == 0)
		{
			R1OFF;
			credit = retrieve_credit();
			credit--;
			store_credit(credit);
			dly_msec(20);
		}
		else
		{
			credit = retrieve_credit();
			credit--;
			store_credit(credit);
			goto nextcoin1;
		}
	return PAY_OK;
}

void dispense_r2(void)
{
    uint8_t y;
	credit = retrieve_credit();
	errorflg = retrieve_error();
	if((errorflg == 2) || (errorflg == 3) || (errorflg == 7))//R2 hopper disabled
	{
		hopper_emt(2);
		goto error;
	}
	numbs = credit / 2;
	payed = credit % 2;
	if(numbs > 5)
	{
		numbs = 5;
	}
	sprintf(msgbuf, "Dispense R2 x %d", (uint16_t)numbs);
	lcd_write_string(msgbuf);
    if(numbs > 0)
    {
        y = pay_r2(numbs);
    }
	switch(y)
	{
		case HOPPER_EMT :	hopper_emt(2);
							break;
		case HOPPER_JAM :	hopper_emt(2);
							break;
		case PAY_OK   	:	goto error;
	}
	error:;
}

uint8_t pay_r2(uint8_t numb)
{
	uint32_t elapsed;
	R2ON;
	dly_msec(3);
	nextcoin2:
	Starttim1();
	while(R2sense)
	{
		CLRWDT();
		if(PIR4bits.TMR1IF)// Allow 5 seconds for the first coin
		{
            PIR4bits.TMR1IF = 0;
			R2OFF;
			register_error(2);
			return HOPPER_EMT;
		}
	}
	Starttim5();
	while(!R2sense)// Coin on it's way out
	{
		CLRWDT();
		if(PIR4bits.TMR5IF)// Allow 500ms for the coin exit
		{
            PIR4bits.TMR5IF = 0;
			R2OFF;
			register_error(2);
			return HOPPER_JAM;
		}
	}
	--numb;
	credit = retrieve_credit();
	if(numb > 0)
	{
		credit = credit - 2;
		store_credit(credit);
		goto nextcoin2;
	}
	else
	{
		R2OFF;
		credit = credit - 2;
		store_credit(credit);
		if(credit == 2)
		{
			goto nextcoin2;
		}
			
	}
	return PAY_OK;
}

void dispense_r5(void)
{
	credit = retrieve_credit();
	errorflg = retrieve_error();
	if(errorflg >= 5)
	{
		hopper_emt(5);
		goto error;
	}
	numbs = credit / 5;
	payed = credit % 5;
	if(numbs > 8)
	{
		numbs  = 8;
	}
	sprintf(msgbuf, "Dispense R5 x %d", (uint16_t)numbs);
	lcd_write_string(msgbuf);
	uint8_t y = pay_r5(numbs);
	switch(y)
	{
		case HOPPER_EMT :	hopper_emt(5);
							goto error;
		case HOPPER_JAM :	hopper_emt(5);
							goto error;
		case PAY_OK   	:	goto error;
	}
	error:;
}

uint8_t pay_r5(uint8_t numb)
{
	uint32_t elapsed;
	R5ON();
	dly_msec(3);
	nextcoin5:
	Starttim1();
	while(R5sense)
	{
		CLRWDT();
		if(PIR4bits.TMR1IF)// Allow 5 seconds for the first coin to appear
		{
			R5OFF();
            PIR4bits.TMR1IF = 0;
			register_error(5);
			return HOPPER_EMT;
		}
	}
	Starttim5();
	if(numb == 1) //Turn off on last coin exit
    {
        R5OFF();
    }
	while(!R5sense)// Coin on it's way out
	{
		CLRWDT();
		if(PIR4bits.TMR5IF)//low 500ms for the coin exit
		{
            PIR4bits.TMR5IF = 0;
			R5OFF();
			register_error(5);
			return HOPPER_JAM;
		}
	}
	--numb;
	credit = retrieve_credit();
	if(numb > 0)
	{
		credit = credit - 5;
		store_credit(credit);
		goto nextcoin5;
	}
	else
	{
		R5OFF();
		credit = credit - 5;
		store_credit(credit);
	}
	return PAY_OK;
}

void tens_in(void)
{
	uint32_t elapsed = 0;
	startof:
	dly_msec(5);//Wait for 5mS debounce
	if(!R10IN)
	{
		dly_msec(1);
		if(R10IN)
		{
			goto endof; //Noise? pulse is less than 5mS
		}
	}
	dly_msec(10);
	
	credit = retrieve_credit();
	credit = credit + 10;
	store_credit(credit);
	while(!R10IN)
	{
		CLRWDT();
		
	}
	endof:
	TMR3_Initialize();
    TMR3_StartTimer();
	while(!PIR4bits.TMR3IF)//wait for next pulse
	{
		if(!R10IN)
		{
			goto startof;
		}
	}
}

void ones_in(void)
{
		uint32_t elapsed =  0;
		startof:;
		dly_msec(5);//Wait for 5mS debounce
		if(!R01IN)
		{
			dly_msec(1);
			if(R01IN)
			{
				goto endof; //Noise? pulse is less than 6mS
			}
		}
		dly_msec(10);
		credit = retrieve_credit();
		credit++;
		store_credit(credit);
		TMR3_Initialize();
        TMR3_StartTimer();
		while(!R01IN)
		{
            CLRWDT();
		}
	endof:;
	while(!PIR4bits.TMR3IF)//wait for next pulse for 300mS
	{
		if(!R01IN)
		{
			goto startof;
		}
	}
}

void dly_msec(uint16_t msecs)
{
	do
    {
        __delay_ms(1);
        --msecs;
    }while(msecs != 0);
}

void store_error(int strclr)
{
	DATAEE_WriteWord(errormm, strclr);
}

uint16_t retrieve_error(void)
{	
	uint16_t strclr;
    strclr = DATAEE_ReadWord(errormm);
	return strclr;
}

void DATAEE_WriteWord(uint16_t bAdd, uint16_t bData)
{
    uint8_t x = (uint8_t)bData & 0x00FF;
    DATAEE_WriteByte(bAdd, x);
    x = (uint8_t)(bData >> 8);
    DATAEE_WriteByte(bAdd + 1, x);
}

uint16_t DATAEE_ReadWord(uint16_t bAdd)
{
    uint8_t x = DATAEE_ReadByte(bAdd);
    uint16_t y = (uint16_t) x;
    y = y & 0x00FF;
    x = DATAEE_ReadByte(bAdd + 1);//Read most significant byte
    uint16_t z = (uint16_t) x;
    z = z & 0x00FF;
    y = (y | (z << 8));
    return y;
}

uint16_t retrieve_credit(void)
{
	uint16_t x;
	x = DATAEE_ReadWord(credmem);
	return x;
}

void deduct_credit(uint16_t minus)
{
	credit = retrieve_credit();
	credit = credit - minus;
	store_credit(credit);
}

void store_credit(uint16_t x)
{
DATAEE_WriteWord(credmem, x);
}

void process_credit(void)
{
	s = 0;
	errorflg = retrieve_error();
	if(!BUTR2)
	{
		if((errorflg == 2) || (errorflg == 3) || (errorflg == 7))
		{
			lcd_write_string("R2 hopper empty");
			dly_msec(3000);
			shcred = 0;
			goto error;
		}
		NOTEDS;
		lcd_write_string("R2 button press");
		dly_msec(100);
		if(credit >= 2)
		{
			dispense_r2();
            credit = retrieve_credit();
		}
        if(credit >= 5)
        {
            dispense_r5();
        }
        if(credit != 0)
        {
            dispense_r1();
        }
		error:;
	}
	if(credit >= 5)
	{
		NOTEDS;
		if(!BUTR5)
		{
			if(errorflg >= 5)
			{
				lcd_write_string("R5 hopper empty");
				dly_msec(3000);
				shcred = 0;
				goto error5;
			}
			lcd_write_string("R5 button press");
			if(credit >= 5)
			{
				dispense_r5();
                credit = retrieve_credit();
			}
			if(credit >= 2)
			{
				dispense_r2();
			}
            if(credit != 0)
            {
                dispense_r1();
            }
		}
	}
	credit = retrieve_credit();
	error5:;
    if(credit == 0)
    {
        shcred = 0;
    }
}

void hopper_emt(int what)
{
	volatile int y = 0;
	int is;
	credit = retrieve_credit();
	errorflg = retrieve_error();
	if(errorflg == 8)
	{
		call_joe();
	}
	switch(what)
	{
		case 1 :	if((credit >= 5) && (errorflg < 5))
					{
						is = 5;
						numbs = credit / 5;
						y = pay_r5(numbs);
					}
					if((credit >= 2) && (errorflg != 2) && (errorflg != 3) && (errorflg != 7))
					{
						is = 2;
						numbs = credit / 2;
						y = pay_r2(numbs);
					}
					break;
		case 2 :	if((credit >= 5) && (errorflg < 5))
					{
						is = 5;
						numbs = credit / 5;
						y = pay_r5(numbs);
					}
					if((credit >= 1) && (errorflg != 1) && (errorflg != 3) && (errorflg != 6))
					{
						is = 1;
						numbs = credit;
						y = pay_r1(numbs);
					}
					break;
		case 5 :	if((credit >= 2) && (errorflg != 2) && (errorflg != 3) && (errorflg != 7))
					{
						is = 2;
						numbs = credit / 2;
						y = pay_r2(numbs);
					}
					if((credit >= 1) && (errorflg != 1) && (errorflg != 3) && (errorflg != 6))
					{
						is = 1;
						numbs = credit;
						y = pay_r1(numbs);
					}
					break;
	}
	
}

void Starttim0(void)//Currently set at 37mSec
{
    TMR0_Initialize();
    PIR0bits.TMR0IF = 0;
    TMR0_StartTimer();
}

void Starttim1(void)
{
    TMR1_Initialize();
    PIR4bits.TMR1IF = 0;
	TMR1_StartTimer();
}

void Starttim3(void)
{
    TMR3_Initialize();
    PIR4bits.TMR3IF = 0;
	TMR3_StartTimer();
}

void Starttim5(void)
{
    TMR5_Initialize();
    PIR4bits.TMR5IF = 0;
	TMR5_StartTimer();
}


