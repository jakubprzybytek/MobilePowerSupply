/*
 * GUI.c
 *
 * Created: 2015-06-10 21:08:21
 *  Author: Rodos
 */ 

#include <string.h>

#include "GUI.h"
#include "OledDriver.h"

#include "../Fonts/font.h"

#define MIN(a,b) ((a) < (b) ? (a) : (b))

bool isActive = false;

void GUI_Init() {
	OLED_INIT_PORTS

	OLED_RD_HIGH
	OLED_RESET_HIGH
	OLED_CHIP_SELECT

	OLED_RESET_LOW
	_delay_ms(1);

	OLED_RESET_HIGH

	OLED_COMMAND

	OLED_Set_Display_On_Off(0x00);

	OLED_Set_Master_Config(0x00);
	//OLED_Set_Gray_Scale_Table();
	//OLED_Set_Contrast(0x00);
	OLED_Set_Remap_Format(0x52);
	OLED_Set_Multiplex_Ratio(64);
	OLED_Set_Start_Line(0);
	OLED_Set_Display_Offset(0);
		
	OLED_Set_Display_On_Off(0x01);

	isActive = true;
}

void GUI_Shutdown() {
	OLED_Set_Display_On_Off(0x00);

	isActive = false;
}

bool GUI_IsActive() {
	return isActive;
}

void GUI_Clean() {
	OLED_Draw_Rectangle(0, 0, 63, 79, 0x00);
}

void GUI_print3(char* text, unsigned char x, unsigned char y, unsigned char pattern) {
	
	uint8_t strLen = strlen(text);
	
	OLED_Set_Remap_Format(0x56);

	OLED_Set_Column_Address(x, MIN (x + strLen * 3 - 1, MAX_X));
	OLED_Set_Row_Address(y, y + 6);

	OLED_DATA
	
	unsigned char left, right;
	
	for (uint8_t i = 0; i < strLen; i++) {
		
		unsigned int charIndex = (text[i] - ' ') * 5;
		
		for (uint8_t k = 0; k < 3; k++) {
		
			left = font_5x7_data[charIndex++];
			right = k < 2 ? font_5x7_data[charIndex++] : 0;
		
			for (uint8_t j = 0; j < 7; j++) {
				unsigned char output = ((left & 0x01) ? 0xf0 : 0x00) | ((right & 0x01) ? 0x0f : 0x00);
				OLED_OUT = output & pattern;
				OLED_WRITE
			
				right = right >> 1;
				left = left >> 1;
			}
		}
	}	
}