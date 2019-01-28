/*
 * Screen.h
 *
 * Created: 2018-10-04 11:50:22
 *  Author: Rodos
 */ 


#ifndef SCREEN_H_
#define SCREEN_H_

#include <stdio.h>

#include "IO/GUI.h"

class Screen {

public:
	void init();
	void shutdown();
	bool isActive();

	void drawTemplate();
	void drawElectricParams(uint16_t inVoltageValue, uint16_t inCurrentValue, uint16_t out2VoltageValue, uint16_t out2CurrentValue, uint16_t out3VoltageValue, uint16_t out3CurrentValue);
	void drawTime(uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds);
	void drawAmpsConsumed(uint32_t ampsConsumed);
	void drawCounter(uint16_t count);
};

#endif /* SCREEN_H_ */