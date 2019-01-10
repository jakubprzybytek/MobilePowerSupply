/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define IN_VOLTAGE_A_FACTOR 0.0786
#define IN_VOLTAGE_B_FACTOR -13.46
#define IN_CURRENT_A_FACTOR 0.1127
#define IN_CURRENT_B_FACTOR -20.288
#define OUT2_VOLTAGE_A_FACTOR 0.03015
#define OUT2_VOLTAGE_B_FACTOR 0.0
#define OUT2_CURRENT_A_FACTOR 0.11
#define OUT2_CURRENT_B_FACTOR -22.8

//static uint8_t adcAInputs[] = { ADC3, ADC4 };

//static uint8_t adcBInputs[] = { ADC5, ADC6 };

void Metter::init() {
	adcA.init();
	adcA.setInput(ADC3, ADC4);
	adcB.init();
	adcB.setInput(ADC5, ADC6);

	DMAC::enable();

	dmaA.init(&ADCA.CH0RES, 128);
	dmaB.init(&ADCB.CH0RES, 128);
}

void Metter::toggleInput() {
	//activeADC = (activeADC + 1) % 2;
	//adcA.setInput(adcAInputs[activeADC]);
	//adcB.setInput(adcBInputs[activeADC]);
}

void Metter::start() {
	dmaA.start();
	dmaB.start();

	adcA.start();
	adcB.start();
}

void Metter::storeReadoutA() {
	uint16_t first;
	uint16_t second;

	dmaA.readBlockByChannels(&first, &second);

	out2VoltageValue = second * OUT2_VOLTAGE_A_FACTOR + OUT2_VOLTAGE_B_FACTOR;
	out2CurrentValue = first * OUT2_CURRENT_A_FACTOR + OUT2_CURRENT_B_FACTOR;
}

void Metter::storeReadoutB() {
	uint16_t first;
	uint16_t second;

	dmaB.readBlockByChannels(&first, &second);

	inVoltageValue = second * IN_VOLTAGE_A_FACTOR + IN_VOLTAGE_B_FACTOR;
	inCurrentValue = first * IN_CURRENT_A_FACTOR + IN_CURRENT_B_FACTOR;

/*
	switch (activeADC) {
		case 0:
			outCurrentValue = adcA.read() * OUT_CURRENT_A_FACTOR + OUT_CURRENT_B_FACTOR;
			inVoltageValue = adcB.read() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
			break;
		case 1:
			outVoltageValue = adcA.read() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
			inCurrentValue = adcB.read() * IN_CURRENT_A_FACTOR + IN_CURRENT_B_FACTOR;
			break;
	}	
*/
}
