/*
 * ADC.h
 *
 * Created: 2018-04-21 19:45:22
 *  Author: Rodos
 */ 

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#define ADC1  ADC_CH_MUXPOS0_bm
#define ADC2  ADC_CH_MUXPOS1_bm
#define ADC3  ADC_CH_MUXPOS1_bm | ADC_CH_MUXPOS0_bm
#define ADC4  ADC_CH_MUXPOS2_bm
#define ADC5  ADC_CH_MUXPOS2_bm | ADC_CH_MUXPOS0_bm
#define ADC6  ADC_CH_MUXPOS2_bm | ADC_CH_MUXPOS1_bm

class ADC {

private:
	ADC_t* adc;
	ADC_CH_t* firstChannel;
	ADC_CH_t* secondChannel;
	uint8_t channelNumber;
	PORT_t* port;

public:
	ADC(ADC_t* adc, uint8_t channelNumber, PORT_t* port) : 
		adc(adc), 
		channelNumber(channelNumber), 
		port(port) {}
	
	void init();

	void setInput(uint8_t input1, uint8_t input2, uint8_t input3, uint8_t input4);
	void start();

};

#endif /* ADC_H_ */