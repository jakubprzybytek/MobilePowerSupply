/*
 * ADC.cpp
 *
 * Created: 2018-04-21 19:45:35
 *  Author: Rodos
 */ 
#include "ADC.h"

void ADC::init() {
	port->OUTCLR = 0xff;

	adc->PRESCALER = ADC_PRESCALER_DIV32_gc;
	adc->CTRLA = ADC_ENABLE_bm;
	adc->CTRLB = 0; // MT12bit
	adc->REFCTRL = 0; // Internal 1V
	//adc->INTFLAGS = (2 << channelNumber); //ADC_CH0IF_bm;
	//firstChannel->INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm; // High Level Interrupt
	firstChannel->CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode
//	secondChannel->INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm; // High Level Interrupt
	secondChannel->CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode

	adc->EVCTRL = ADC_SWEEP0_bm; // ADC_SWEEP_enum.ADC_SWEEP_01_gc; // free run with 0-1 channels
}

void ADC::setInput(uint8_t input1, uint8_t input2) {
	firstChannel->MUXCTRL = input1;
	secondChannel->MUXCTRL = input2;
}

void ADC::start() {
	//adc->CTRLA |= (3 << (ADC_CH0START_bp + channelNumber)); //ADC_CH0START_bm;
	adc->CTRLB = ADC_FREERUN_bm;
};

uint16_t ADC::readFirst() {
	return firstChannel->RES;	
}

uint16_t ADC::readSecond() {
	return secondChannel->RES;
}
