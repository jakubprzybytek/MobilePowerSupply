/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define IN_VOLTAGE_A_FACTOR 0.0786
#define IN_VOLTAGE_B_FACTOR -13.46
#define IN_CURRENT_A_FACTOR 0.1127
#define IN_CURRENT_B_FACTOR -20.288
#define OUT1_VOLTAGE_A_FACTOR 0.0544
#define OUT1_VOLTAGE_B_FACTOR -9.84
#define OUT1_CURRENT_A_FACTOR 0.112
#define OUT1_CURRENT_B_FACTOR -19.71
#define OUT2_VOLTAGE_A_FACTOR 0.0318
#define OUT2_VOLTAGE_B_FACTOR -5.76
#define OUT2_CURRENT_A_FACTOR 0.111
#define OUT2_CURRENT_B_FACTOR -21.72
#define OUT3_VOLTAGE_A_FACTOR 0.0317
#define OUT3_VOLTAGE_B_FACTOR -5.73
#define OUT3_CURRENT_A_FACTOR 0.112
#define OUT3_CURRENT_B_FACTOR -21.46
#define OUT4_VOLTAGE_A_FACTOR 0.0322
#define OUT4_VOLTAGE_B_FACTOR -5.825
#define OUT4_CURRENT_A_FACTOR 0.112
#define OUT4_CURRENT_B_FACTOR -19.95
#define OUT5_VOLTAGE_A_FACTOR 0.0321
#define OUT5_VOLTAGE_B_FACTOR -5.8
#define OUT5_CURRENT_A_FACTOR 0.112
#define OUT5_CURRENT_B_FACTOR -18.55

/**
 * PORT A: 
 ** ADC1 / ADC2 - Out 3 Curr / Volt 
 ** ADC3 / ADC4 - Out 2 Curr / Volt
 ** ADC5 / ADC6 - Out 1 Curr / Volt
 ** ADC7        - Out 5 Curr
 **
 * PORT B:
 ** ADC0        - Out 5        Volt
 ** ADC1 / ADC2 - Out 4 Curr / Volt
 ** ADC5 / ADC6 - IN    Curr / Volt
*/

void Metter::init() {
	adcA.init();
	adcB.init();

	DMAC::enable();

	dmaA.init(&ADCA.CH0RES, 0x13, 128);
	dmaB.init(&ADCB.CH0RES, 0x23, 128);
}

void Metter::toggleInput() {
	activeADC = (activeADC + 1) % 2;

	if (activeADC == 0) {
		adcA.setInput(ADC1, ADC2, ADC3, ADC4);
		adcB.setInput(ADC1, ADC2, ADC5, ADC6);
	} else {
		adcA.setInput(ADC5, ADC6, ADC7, ADC0);
		adcB.setInput(ADC7, ADC0, ADC3, ADC4);
	}
}

void Metter::start() {
	dmaA.start();
	dmaB.start();

	adcA.start();
	adcB.start();
}

void Metter::stopA() {
	adcA.stop();
}

void Metter::stopB() {
	adcB.stop();
}

void Metter::storeReadoutA() {
	uint16_t first;
	uint16_t second;
	uint16_t third;
	uint16_t fourth;

	dmaA.readBlockByChannels(&first, &second, &third, &fourth);

	if (activeADC == 0) {
		measurements.out2VoltageValue = fourth * OUT2_VOLTAGE_A_FACTOR + OUT2_VOLTAGE_B_FACTOR;
		measurements.out2CurrentValue = MAX(third * OUT2_CURRENT_A_FACTOR + OUT2_CURRENT_B_FACTOR, 0.0);
		measurements.out3VoltageValue = second * OUT3_VOLTAGE_A_FACTOR + OUT3_VOLTAGE_B_FACTOR;
		measurements.out3CurrentValue = MAX(first * OUT3_CURRENT_A_FACTOR + OUT3_CURRENT_B_FACTOR, 0.0);
	} else {
		measurements.out1VoltageValue = second * OUT1_VOLTAGE_A_FACTOR + OUT1_VOLTAGE_B_FACTOR;
		measurements.out1CurrentValue = MAX(first * OUT1_CURRENT_A_FACTOR + OUT1_CURRENT_B_FACTOR, 0.0);
		measurements.out5CurrentValue = MAX(third * OUT5_CURRENT_A_FACTOR + OUT5_CURRENT_B_FACTOR, 0.0);
	}
}

void Metter::storeReadoutB() {
	uint16_t first;
	uint16_t second;
	uint16_t third;
	uint16_t fourth;

	dmaB.readBlockByChannels(&first, &second, &third, &fourth);

	if (activeADC == 0) {
		measurements.inVoltageValue = fourth * IN_VOLTAGE_A_FACTOR + IN_VOLTAGE_B_FACTOR;
		measurements.inCurrentValue = MAX(third * IN_CURRENT_A_FACTOR + IN_CURRENT_B_FACTOR, 0.0);
		measurements.out4VoltageValue = second * OUT4_VOLTAGE_A_FACTOR + OUT4_VOLTAGE_B_FACTOR;
		measurements.out4CurrentValue = MAX(first * OUT4_CURRENT_A_FACTOR + OUT4_CURRENT_B_FACTOR, 0.0);
	} else {
		measurements.out5VoltageValue = second * OUT5_VOLTAGE_A_FACTOR + OUT5_VOLTAGE_B_FACTOR;
	}
}
