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
//	secondChannel->INTCTRL = ADC_CH_INTLVL1_bm | ADC_CH_INTLVL0_bm; // High Level Interrupt

	adc->CH0.CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode
	adc->CH1.CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode
	adc->CH2.CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode
	adc->CH3.CTRL = ADC_CH_INPUTMODE0_bm; // Single-Ended mode

	adc->EVCTRL = ADC_SWEEP1_bm | ADC_SWEEP0_bm; // ADC_SWEEP_enum.ADC_SWEEP_11_gc; // free run with 0-3 channels
}

void ADC::setInput(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4) {
	adc->CH0.MUXCTRL = input1;
	adc->CH1.MUXCTRL = input2;
	adc->CH2.MUXCTRL = input3;
	adc->CH3.MUXCTRL = input4;
}

void ADC::start() {
	adc->CTRLB = ADC_FREERUN_bm;
};

void ADC::stop() {
	adc->CTRLB &= !ADC_FREERUN_bm;
};