/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define VOLTAGE_A_FACTOR 1.0
#define VOLTAGE_B_FACTOR 0.0
#define IN_CURRENT_A_FACTOR 1.0
#define IN_CURRENT_B_FACTOR 0.0
#define OUT_CURRENT_A_FACTOR 1.0
#define OUT_CURRENT_B_FACTOR 0.0

static uint8_t adcAInputs[] = { ADC3, ADC4 };

static uint8_t adcBInputs[] = { ADC5, ADC6 };

void Metter::init() {
	adcA.init();
	adcA.setInput(ADC3, ADC4);
	adcB.init();
	adcB.setInput(ADC5, ADC6);

	dma.init();
	dma.start();
}

void Metter::toggleInput() {
	//activeADC = (activeADC + 1) % 2;
	//adcA.setInput(adcAInputs[activeADC]);
	//adcB.setInput(adcBInputs[activeADC]);
}

void Metter::start() {
	adcA.start();
	adcB.start();
}

void Metter::storeAvgReadoutA() {
	dma.readBlockByChannels(&(this->first), &(this->second));
	dma.start();
}

void Metter::storeReadoutA() {
	out2CurrentValue = adcA.readFirst() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
	out2VoltageValue = adcA.readSecond() * OUT_CURRENT_A_FACTOR + OUT_CURRENT_B_FACTOR;
}

void Metter::storeReadoutB() {
	inCurrentValue = adcB.readFirst() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
	inVoltageValue = adcB.readSecond() * IN_CURRENT_A_FACTOR + IN_CURRENT_B_FACTOR;

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
