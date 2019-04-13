/*
 * EEPROM.h
 *
 * Created: 2019-03-02 18:42:07
 *  Author: Chipotle
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include "../Peripheral/eeprom_driver.h"
#include "../Peripheral/RTC.hpp"

#define EEPROM_PAGE 0
#define EEPROM_DATA_VERSION 4

class EEPROMInterface {

public:
	uint16_t eepromWrites;

private:
	uint8_t eepromPageBuffer[EEPROM_PAGESIZE];

public:
	void init();

	void loadData(Clock& clock, uint32_t* ampsConsumed);
	void storeData(Clock& clock, uint32_t* ampsConsumed);
};

#endif /* EEPROM_H_ */