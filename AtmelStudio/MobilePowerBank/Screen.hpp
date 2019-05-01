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
#include "IO/Metter.h"

class Screen {

public:
	void init(char names[][5], bool clean);
	void shutdown();
	bool isActive();

	void drawTemplate(char names[][5]);
	void drawElectricParams(Measurements& measurements);
	void drawTime(uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds);
	void drawAmpsConsumed(uint32_t ampsConsumed);
	void drawTemperature(uint8_t temp);
	void drawSecondsToReset(uint8_t seconds);
};

#endif /* SCREEN_H_ */