/*
 * NamesMemory.cpp
 *
 * Created: 2019-04-30 13:52:09
 *  Author: Chipotle
 */

#include "NamesMemory.h"

void NamesMemory::init() {
	EEPROM_DisableMapping();
}

void NamesMemory::loadData(char names[6][5]) {
	uint8_t byteAddr = 0;

	// byte 0: data version
	uint8_t storedDataVersion = EEPROM_ReadByte(NAMES_EEPROM_PAGE, byteAddr++);

	// bytes 1-2: eeprom writes
	((uint8_t*) &eepromWrites)[0] = EEPROM_ReadByte(NAMES_EEPROM_PAGE, byteAddr++);
	((uint8_t*) &eepromWrites)[1] = EEPROM_ReadByte(NAMES_EEPROM_PAGE, byteAddr++);

	if (storedDataVersion != NAMES_EEPROM_DATA_VERSION) {
		return;
	}

	// bytes 3-26: names
	for (uint8_t nameIndex = 0; nameIndex < 6; nameIndex++) {
		for (uint8_t charIndex = 0; charIndex < 4; charIndex++) {
			names[nameIndex][charIndex] = EEPROM_ReadByte(NAMES_EEPROM_PAGE, byteAddr++);
		}
	}
}

void NamesMemory::storeData(char names[6][5]) {
	uint8_t byteAddr = 0;
	eepromWrites++;

	eepromPageBuffer[byteAddr++] = NAMES_EEPROM_DATA_VERSION;
	eepromPageBuffer[byteAddr++] = ((uint8_t*) &eepromWrites)[0];
	eepromPageBuffer[byteAddr++] = ((uint8_t*) &eepromWrites)[1];

	for (uint8_t nameIndex = 0; nameIndex < 6; nameIndex++) {
		for (uint8_t charIndex = 0; charIndex < 4; charIndex++) {
			eepromPageBuffer[byteAddr++] = names[nameIndex][charIndex];
		}
	}
	
	EEPROM_FlushBuffer();
	EEPROM_LoadPage(eepromPageBuffer);
	EEPROM_AtomicWritePage(NAMES_EEPROM_PAGE);
}
