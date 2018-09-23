/*
 * Metter.h
 *
 * Created: 2018-04-21 19:50:27
 *  Author: Rodos
 */ 


#ifndef METTER_H_
#define METTER_H_

#include "../Peripheral/ADC.h"

class Metter {

private:
	ADC adc;

public:
	uint8_t activeADC;

	uint16_t inVoltageValue;
	uint16_t inCurrentValue;
	uint16_t outVoltageValue;
	uint16_t outCurrentValue;

public:
	Metter() : activeADC(0) {}

	void init();

	void toggleInput();
	void start();

	void storeReadout();

};

#endif /* METTER_H_ */