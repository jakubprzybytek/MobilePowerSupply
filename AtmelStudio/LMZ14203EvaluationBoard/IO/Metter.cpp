/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define VOLTAGE_A_FACTOR 0.077
#define VOLTAGE_B_FACTOR -12.85
#define IN_CURRENT_A_FACTOR 0.1104
#define IN_CURRENT_B_FACTOR -17.792
#define OUT_CURRENT_A_FACTOR 0.1103
#define OUT_CURRENT_B_FACTOR -20.329

static uint8_t adcInputs[] = {ADC0, ADC1, ADC2, ADC3};

void Metter::init() {
	adc.init();
	adc.setInput(ADC2);
}

void Metter::toggleInput() {
	activeADC = (activeADC + 1) % 4;
	adc.setInput(adcInputs[activeADC]);
}

void Metter::start() {
	adc.start();
}

void Metter::storeReadout() {
	switch (activeADC) {
		case 0:
			outCurrentValue = adc.readCH0() * OUT_CURRENT_A_FACTOR + OUT_CURRENT_B_FACTOR;
			break;
		case 1:
			outVoltageValue = adc.readCH0() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
			break;
		case 2:
			inVoltageValue = adc.readCH0() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
			break;
		case 3:
			inCurrentValue = adc.readCH0() * IN_CURRENT_A_FACTOR + IN_CURRENT_B_FACTOR;
			break;
	}	
}
