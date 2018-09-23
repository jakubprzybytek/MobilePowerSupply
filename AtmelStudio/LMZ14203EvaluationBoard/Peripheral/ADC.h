/*
 * ADC.h
 *
 * Created: 2018-04-21 19:45:22
 *  Author: Rodos
 */ 

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

#define ADC_INIT PORTA.DIRCLR = PIN3_bm | PIN2_bm | PIN1_bm | PIN0_bm

#define ADC0 0
#define ADC1 ADC_CH_MUXPOS0_bm
#define ADC2 ADC_CH_MUXPOS1_bm
#define ADC3 ADC_CH_MUXPOS1_bm | ADC_CH_MUXPOS0_bm

class ADC {
	
public:
	void init();

	void setInput(uint8_t input);
	void start();

	uint16_t readCH0();
};

#endif /* ADC_H_ */