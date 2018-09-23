/*
 * ADC.cpp
 *
 * Created: 2018-04-21 19:45:35
 *  Author: Rodos
 */ 
#include "ADC.h"

void ADC::init() {
	ADC_INIT;

	ADCA.PRESCALER = ADC_PRESCALER_DIV16_gc;
	ADCA.CTRLA = ADC_ENABLE_bm;
	ADCA.CTRLB = ADC_RESOLUTION0_bm; // MT12bit
	ADCA.REFCTRL = 0; // Internal 1V
	ADCA.INTFLAGS = ADC_CH0IF_bm;
	ADCA.CH0.INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm; // High Level Interrupt
	ADCA.CH0.CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode
	ADCA.CH0.AVGCTRL = ADC_CH_RIGHTSHIFT2_bm | ADC_CH_SAMPNUM3_bm | ADC_CH_SAMPNUM1_bm; // 1024x avg
	ADCA.EVCTRL = 0x00;
}

void ADC::setInput(uint8_t input) {
	ADCA.CH0.MUXCTRL = input;
}

void ADC::start() {
	ADCA.CTRLA |= ADC_START_bm;
};

uint16_t ADC::readCH0() {
	return ADCA.CH0.RES;	
}
