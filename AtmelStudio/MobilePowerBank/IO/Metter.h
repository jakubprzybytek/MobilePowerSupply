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

#define ADC_CHANNELS 4
#define READS_TO_AVARAGE 128

struct Measurements {
	uint16_t inVoltageValue;
	uint16_t inCurrentValue;
	uint16_t out1VoltageValue;
	uint16_t out1CurrentValue;
	uint16_t out2VoltageValue;
	uint16_t out2CurrentValue;
	uint16_t out3VoltageValue;
	int16_t out3CurrentValue;
	uint16_t out4VoltageValue;
	uint16_t out4CurrentValue;
	uint16_t out5VoltageValue;
	uint16_t out5CurrentValue;
};

class Metter {

private:
	ADC adcA;
	ADC adcB;

	DMAC dmaA;
	DMAC dmaB;

	uint8_t activeADC;

	uint16_t* readsBufferA;
	uint16_t* readsBufferB;

public:
	Measurements measurements;

public:
	Metter() : 
		adcA(&ADCA, 0, &PORTA), adcB(&ADCB, 0, &PORTB), 
		dmaA(&DMA.CH0), dmaB(&DMA.CH1), 
		activeADC(0) {}

	void init();

	void toggleInput();
	void start();
	void stopA();
	void stopB();

	void readBlockByChannels(uint16_t* buffer, uint16_t* first, uint16_t* second, uint16_t* third, uint16_t* fourth);

	void storeReadoutA();
	void storeReadoutB();
};

#endif /* METTER_H_ */