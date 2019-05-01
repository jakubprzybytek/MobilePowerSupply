/*
 * EEPROM.cpp
 *
 * Created: 2019-03-02 18:44:44
 *  Author: Chipotle
 */ 

#include "StatsMemory.hpp"

void StatsMemory::init() {
	EEPROM_DisableMapping();
}

void StatsMemory::loadData(Clock& clock, uint32_t* ampsConsumed) {
	uint8_t byteAddr = 0;

	uint8_t storedDataVersion = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);

	((uint8_t*) &eepromWrites)[0] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	((uint8_t*) &eepromWrites)[1] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);

	if (storedDataVersion != STATS_EEPROM_DATA_VERSION) {
		return;
	}

	clock.days = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	clock.hours = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	clock.minutes = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	clock.seconds = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[0] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[1] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[2] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
	((uint8_t*) ampsConsumed)[3] = EEPROM_ReadByte(STATS_EEPROM_PAGE, byteAddr++);
}

void StatsMemory::storeData(Clock& clock, uint32_t* ampsConsumed) {
	uint8_t byteAddr = 0;
	eepromWrites++;

	eepromPageBuffer[byteAddr++] = STATS_EEPROM_DATA_VERSION;
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
	EEPROM_AtomicWritePage(STATS_EEPROM_PAGE);
}
