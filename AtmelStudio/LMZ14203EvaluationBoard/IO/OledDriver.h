/*
 * oledDriver.h
 *
 * Created: 2015-06-07 12:16:43
 *  Author: Rodos
 */ 
#include <avr/io.h>
#include <util/delay.h>

#ifndef OLEDDRIVER_H_
#define OLEDDRIVER_H_

#define OLED_OUT PORTC.OUT

#define OLED_INIT_PORTS		PORTD.DIRSET = PIN3_bm | PIN4_bm | PIN5_bm | PIN6_bm | PIN7_bm; PORTC.DIRSET = 0xff;

#define OLED_RESET_HIGH		PORTD.OUTSET = PIN6_bm;
#define OLED_RESET_LOW		PORTD.OUTCLR = PIN6_bm;

#define OLED_W_HIGH			PORTD.OUTSET = PIN4_bm;
#define OLED_W_LOW			PORTD.OUTCLR = PIN4_bm;

#define OLED_DATA			PORTD.OUTSET = PIN5_bm;
#define OLED_COMMAND		PORTD.OUTCLR = PIN5_bm;

#define OLED_CHIP_DISABLE	PORTD.OUTSET = PIN7_bm;
#define OLED_CHIP_SELECT	PORTD.OUTCLR = PIN7_bm;

#define OLED_RD_HIGH		PORTD.OUTSET = PIN3_bm;
#define OLED_RD_LOW			PORTD.OUTCLR = PIN3_bm;

#define OLED_READ			OLED_RD_LOW OLED_RD_HIGH;
#define OLED_WRITE			OLED_W_LOW OLED_W_HIGH;

unsigned char Bit_Reverse(unsigned char x);

void OLED_Set_Remap_Format(unsigned char d);

void OLED_Set_Start_Line(unsigned char d);

void OLED_Set_Display_Offset(unsigned char d);

void OLED_Set_Display_Mode(unsigned char d);

void OLED_Set_Multiplex_Ratio(unsigned char d);

void OLED_Set_Master_Config(unsigned char d);

void OLED_Set_Display_On_Off(unsigned char d);

void OLED_Set_Gray_Scale_Table();

void OLED_Set_Column_Address(unsigned char a, unsigned char b);

void OLED_Set_Row_Address(unsigned char a, unsigned char b);

void OLED_Draw_Rectangle(unsigned char startCol, unsigned char startRow, unsigned char endCol, unsigned char endRow, unsigned char pattern);

#endif /* OLEDDRIVER_H_ */