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

	void drawTemplate();
	void drawElectricParams(uint16_t inVoltageValue, uint16_t inCurrentValue, uint16_t outVoltageValue, uint16_t outCurrentValue);
	void drawCounter(uint16_t count);
};

#endif /* SCREEN_H_ */