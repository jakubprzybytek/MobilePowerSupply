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
	void init(bool clean);
	void shutdown();
	bool isActive();

	void drawTemplate();
	void drawElectricParams(Measurements& measurements);
	void drawTime(uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds);
	void drawAmpsConsumed(uint32_t ampsConsumed);
	void drawTemperature(uint8_t temp);
};

#endif /* SCREEN_H_ */