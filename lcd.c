/*This file contains all the functions for the LCD display
 Author:   Dave Plater
 Date:     2017/10/06*/
//#include "lcd.h"
#include "buffers.h"
volatile uint8_t bf;

/* Initialize display E=RE0 R/W=RE1 RS=RE2 D4 to D7 = RD0 to RD3
   All bits initialized as digital outputs */
//Initialize LCD display
void lcd_init(void)
{
    LATE = 0x00;
    //write 0011 first
    LATD = 0x03;
    for(count = 3; count > 0; count-- )
    {
        lcd_clockE();
        __delay_ms(5);
        
    }
    __delay_us(50);
    LATD = 0x02;
    lcd_clockE();
    
    //4 bit interface two line 5x8 character
    lcd_write(dispfunc2);
    //Display off
    lcd_write(dispon);
    //Entry mode Increment address and no shift
    lcd_write(dispnormal);
    //Display clear
    lcd_write(dispclr);
    //Display characters from 0 to >
    lcd_test();
}

//Write string to display
void lcd_string(uint8_t *lcdstring, uint8_t lcdline)
{
    asm("BCF LATE, 2"); //RS low
    if(lcdline == 0)
    {
        lcd_write(dispclr);
    }
    else
    {
        //MSB high for address
        lcd_dispadd(lcdline | 0x80);
    }
    stradd = 0;
    do
    {
        lcdata = lcdstring[stradd];
        if(lcdata == 0)
        {
            break;
        }
        lcd_writeC(lcdata);
        stradd++;
    }while(stradd < 0x08);
}

//Write character to LCD
void lcd_writeC(uint8_t lcdata)
{
    asm("BCF LATE, 2"); //RS low
    bf = read_busy();
    //Set RS High for character write
    asm("BSF LATE, 2");
    __delay_ms(1);
    lcd_write(lcdata);
    //Check if end of line is reached
    //and start a new one.
    asm("BCF LATE, 2");
}

void lcd_dispadd(uint8_t lcdaddress)
{
        uint8_t lcdatasave = lcdata;
        asm("BCF LATE, 2");
        //Change digit address to 0x40
        lcd_write(lcdaddress | 0x80);
        asm("BSF LATE, 2");
        lcdata = lcdatasave;

}
//Write 4 bit data to display from 8 bits
//Calling program sets up LATE for character write
void lcd_write(uint8_t lcdata)
{
    uint8_t savelatd = LATD;
//Output upper nibble
    
    do
    {
      bf = read_busy();
    }while(bf & 0x80);
    LATD = (lcdata >> 4) & 0x0F;
//Output lower nibble
    lcd_clockE();
    
    LATD = lcdata & 0x0F;
    lcd_clockE();
    LATD = savelatd;
    __delay_ms(1);
}

void lcd_test(void)
{
    lcd_write(dispclr);
    lcd_dispadd(line1);
    uint8_t character = 0x30;
    while(character < 0x40)
    {
        lcd_writeC(character);
        character = character+ 1;
        if(character == 0x38)
        {
            lcd_dispadd(0x40);
        }
    }
}

//Read busy flag at DB7
int8_t read_busy(void)
{
    uint8_t savelate = LATE;
    uint8_t savelatd = LATD;
    asm("BCF LATE, 2"); //RS low
    asm("BSF LATE, 1"); //set R/W high
    TRISD = (TRISD | 0x0F); //Lower nibble to input
    lcd_clockH(); //Clock E high
    bflag = (PORTD << 4);//Lower nibble to upper nibble
    lcd_clockL(); //Set E low
    lcd_clockH();
    bflag = bflag | (PORTD & 0x0F);// Or the last lower nibble in
    asm("BCF LATE, 0"); //Set E low
    TRISD = (TRISD & 0xF0); //Lower nibble to output
    asm("BCF LATE, 1");
    LATD = savelatd;
    LATE = savelate;
    return(bflag); //Return the result
    
}

//Perform write or read to display toggling E clocking data
//All other registers TRISD LATD TRISE and LATE must be setup first
//Depending on the length of the cable delays may need tuning
void lcd_clockH(void)
{
    asm("BSF LATE, 0"); //Set E high
    __delay_us(12);
}
//Perform write or read to display toggling E clocking data
//All other registers TRISD LATD TRISE and LATE must be setup first
//Depending on the length of the cable delays may need tuning
void lcd_clockL(void)
{
    asm("BCF LATE, 0"); //Set E low
    __delay_us(12);
}
//Perform write or read to display toggling E clocking data
//All other registers TRISD LATD TRISE and LATE must be setup first
//Depending on the length of the cable delays may need tuning
void lcd_clockE(void)
{
     asm("BSF LATE, 0"); //Set E high
    __delay_us(12);
     asm("BCF LATE, 0"); //Set E low
    __delay_us(12);
}
