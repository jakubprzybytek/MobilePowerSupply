/*
 * OledDriver.c
 *
 * Created: 2015-06-10 21:24:13
 *  Author: Rodos
 */ 
#include <util/delay.h>

#include "OledDriver.h"

unsigned char Bit_Reverse( unsigned char x ) {
	x = ((x >> 1) & 0x55) | ((x << 1) & 0xaa);
	x = ((x >> 2) & 0x33) | ((x << 2) & 0xcc);
	x = ((x >> 4) & 0x0f) | ((x << 4) & 0xf0);
	return x;
}

void OLED_Set_Remap_Format(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xA0); OLED_WRITE
	OLED_OUT = Bit_Reverse(d); OLED_WRITE
}

void OLED_Set_Start_Line(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xA1); OLED_WRITE
	OLED_OUT = Bit_Reverse(d); OLED_WRITE
}

void OLED_Set_Display_Offset(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xA2); OLED_WRITE
	OLED_OUT = Bit_Reverse(d); OLED_WRITE
}

void OLED_Set_Display_Mode(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xA4 | d); OLED_WRITE
	_delay_ms(1);
}

void OLED_Set_Multiplex_Ratio(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xA8 | d); OLED_WRITE
	_delay_ms(1);
}

void OLED_Set_Master_Config(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xad); OLED_WRITE
	_delay_ms(1);
	OLED_OUT = Bit_Reverse(0x02 | d); OLED_WRITE
	_delay_ms(1);
}

void OLED_Set_Display_On_Off(unsigned char d)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xAE | d); OLED_WRITE
	_delay_ms(100);
}

void OLED_Set_Gray_Scale_Table()
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0xB8); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x01); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x11); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x22); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x32); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x43); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x54); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x65); OLED_WRITE
	OLED_OUT = Bit_Reverse(0x76); OLED_WRITE
}

void OLED_Set_Column_Address(unsigned char a, unsigned char b)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0x15); OLED_WRITE
	OLED_OUT = Bit_Reverse(a); OLED_WRITE
	OLED_OUT = Bit_Reverse(b); OLED_WRITE
}

void OLED_Set_Row_Address(unsigned char a, unsigned char b)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0x75); OLED_WRITE
	OLED_OUT = Bit_Reverse(a + 4); OLED_WRITE
	OLED_OUT = Bit_Reverse(b + 4); OLED_WRITE
}

void OLED_Draw_Rectangle(unsigned char startCol, unsigned char startRow, unsigned char endCol, unsigned char endRow, unsigned char pattern)
{
	OLED_COMMAND
	OLED_OUT = Bit_Reverse(0x24); OLED_WRITE
	OLED_OUT = Bit_Reverse(startCol); OLED_WRITE
	OLED_OUT = Bit_Reverse(startRow); OLED_WRITE
	OLED_OUT = Bit_Reverse(endCol); OLED_WRITE
	OLED_OUT = Bit_Reverse(endRow); OLED_WRITE
	OLED_OUT = Bit_Reverse(pattern); OLED_WRITE
	
	_delay_us(200);
}