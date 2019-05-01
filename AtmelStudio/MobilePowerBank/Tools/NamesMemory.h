/*
 * NamesMemory.h
 *
 * Created: 2019-04-30 13:49:02
 *  Author: Chipotle
 */ 


#ifndef NAMESMEMORY_H_
#define NAMESMEMORY_H_

#include "../Peripheral/eeprom_driver.h"

#define NAMES_EEPROM_PAGE 1
#define NAMES_EEPROM_DATA_VERSION 3

class NamesMemory {

	public:
	uint16_t eepromWrites;

	private:
	uint8_t eepromPageBuffer[EEPROM_PAGESIZE];

	public:
	void init();

	void loadData(char names[6][5]);
	void storeData(char names[6][5]);
};

#endif /* NAMESMEMORY_H_ */