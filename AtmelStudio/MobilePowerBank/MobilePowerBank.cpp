/*
 * MobilePowerBank.cpp
 *
 * Created: 2019-01-05 21:44:43
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "IO/GUI.h"
#include "IO/Metter.h"
#include "Screen.hpp"

Metter metter;

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH1_vect) {
	//metter.storeReadoutA();
}

/* *****************
 * ADCB: Conversion Complete interrupt
 ***************** */
ISR (ADCB_CH1_vect) {
	//metter.storeReadoutB();
}

/* *****************
 * DMA CH0: DMA transaction finished interrupt
 ***************** */
ISR (DMA_CH0_vect) {
	metter.storeReadoutA();
	DMA.INTFLAGS = DMA_CH0TRNIF_bm;
}

/* *****************
 * DMA CH1: DMA transaction finished interrupt
 ***************** */
ISR (DMA_CH1_vect) {
	metter.storeReadoutB();
	DMA.INTFLAGS = DMA_CH1TRNIF_bm;
}

int main(void)
{
	PORTF.DIRSET = PIN2_bm;

	Screen screen;
	
	screen.init();
	metter.init();
//	PORTB.OUTSET = 0x00;

	screen.drawTemplate();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

    while (1) 
    {
		//metter.toggleInput();
		metter.start();

		PORTF.OUTTGL = PIN2_bm;
		_delay_ms(100);

		screen.drawElectricParams(metter.inVoltageValue, metter.inCurrentValue, metter.out2VoltageValue, metter.out2CurrentValue);
    }
}

