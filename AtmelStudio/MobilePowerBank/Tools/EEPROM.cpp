/*
 * EEPROM.cpp
 *
 * Created: 2019-03-02 18:44:44
 *  Author: Chipotle
 */ 

#include "EEPROM.hpp"

void EEPROMInterface::init() {
	EEPROM_DisableMapping();
}

void EEPROMInterface::loadData(Clock& clock, uint32_t* ampsConsumed) {
	uint8_t byteAddr = 0;

	uint8_t storedDataVersion = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	if (storedDataVersion != EEPROM_DATA_VERSION) {
		return;
	}

	((uint8_t*) &eepromWrites)[0] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	((uint8_t*) &eepromWrites)[1] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	clock.days = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	clock.hours = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	clock.minutes = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	clock.seconds = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[0] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[1] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[2] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[3] = EEPROM_ReadByte(EEPROM_PAGE, byteAddr++);
}

void EEPROMInterface::storeData(Clock& clock, uint32_t* ampsConsumed) {
	uint8_t byteAddr = 0;
	eepromWrites++;

	eepromPageBuffer[byteAddr++] = EEPROM_DATA_VERSION;
	eepromPageBuffer[byteAddr++] = ((uint8_t*) &eepromWrites)[0];
	eepromPageBuffer[byteAddr++] = ((uint8_t*) &eepromWrites)[1];
	eepromPageBuffer[byteAddr++] = clock.days;
	eepromPageBuffer[byteAddr++] = clock.hours;
	eepromPageBuffer[byteAddr++] = clock.minutes;
	eepromPageBuffer[byteAddr++] = clock.seconds;
	eepromPageBuffer[byteAddr++] = ((uint8_t*) ampsConsumed)[0];
	eepromPageBuffer[byteAddr++] = ((uint8_t*) ampsConsumed)[1];
	eepromPageBuffer[byteAddr++] = ((uint8_t*) ampsConsumed)[2];
	eepromPageBuffer[byteAddr++] = ((uint8_t*) ampsConsumed)[3];
	
	EEPROM_FlushBuffer();
	EEPROM_LoadPage(eepromPageBuffer);
	EEPROM_AtomicWritePage(EEPROM_PAGE);
}
