/*
 * Metter.h
 *
 * Created: 2018-04-21 19:50:27
 *  Author: Rodos
 */ 


#ifndef METTER_H_
#define METTER_H_

#include "../Peripheral/ADC.h"
#include "../Peripheral/DMA.h"

class Metter {

private:
	ADC adcA;
	ADC adcB;

	DMAC dmaA;
	DMAC dmaB;

public:
	uint8_t activeADC;

	uint16_t inVoltageValue;
	uint16_t inCurrentValue;
	uint16_t out2VoltageValue;
	uint16_t out2CurrentValue;

public:
	Metter() : 
		adcA(&ADCA, 0, &PORTA), adcB(&ADCB, 0, &PORTB), 
		dmaA(&DMA.CH0), dmaB(&DMA.CH1), 
		activeADC(0) {}

	void init();

	void toggleInput();
	void start();

	void storeReadoutA();
	void storeReadoutB();
};

#endif /* METTER_H_ */