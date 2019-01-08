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

Metter metter;

char buffer[22];

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH0_vect) {
	metter.storeReadout();
}

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH1_vect) {
	metter.storeReadout();
}

/* *****************
 * ADCB: Conversion Complete interrupt
 ***************** */
ISR (ADCB_CH0_vect) {
	metter.storeReadout();
}

/* *****************
 * ADCB: Conversion Complete interrupt
 ***************** */
ISR (ADCB_CH1_vect) {
	metter.storeReadout();
}

int main(void)
{
	PORTF.DIRSET = PIN2_bm;

	GUI_Init();
	GUI_print3("Hello world!", 10, 10, 0xaa);
	
	metter.init();
	PORTB.OUTSET = 0x00;
	
	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

    while (1) 
    {
		
		metter.toggleInput();
		metter.start();

		
		PORTF.OUTTGL = PIN2_bm;
		_delay_ms(250);

		sprintf(buffer, "In: %u %u", metter.inVoltageValue, metter.inCurrentValue);
		GUI_print3(buffer, 9, 20, 0xee);

		sprintf(buffer, "Out2: %u %u", metter.out2VoltageValue, metter.out2CurrentValue);
		GUI_print3(buffer, 9, 30, 0xee);
    }
}

