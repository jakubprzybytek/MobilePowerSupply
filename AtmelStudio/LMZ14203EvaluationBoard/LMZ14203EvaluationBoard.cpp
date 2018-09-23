/*out
 * GccApplication1.cpp
 *
 * Created: 2018-09-22 13:35:49
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stddef.h>
#include <stdio.h>

#include "IO/GUI.h"
#include "IO/Metter.h"

#include "Tools/Timer.hpp"

#define LED_INIT	PORTA.DIRSET = PIN6_bm
#define LED_TOGGLE	PORTA.OUTTGL = PIN6_bm

Metter metter;
	
char buffer[22];

/* *****************
 * TCC5: Display refresh timer interrupt
 ***************** */
ISR (TCC5_OVF_vect) {
	TCC5.INTFLAGS = TC5_OVFIF_bm;

	sprintf(buffer, "%u.%uV", metter.inVoltageValue / 10, metter.inVoltageValue % 10);
	GUI_print3(buffer, 9, 0, 0xee);

	sprintf(buffer, "%u.%02uA", metter.inCurrentValue / 100, metter.inCurrentValue % 100);
	GUI_print3(buffer, 9, 10, 0xee);

	sprintf(buffer, "%u.%uV", metter.outVoltageValue / 10, metter.outVoltageValue % 10);
	GUI_print3(buffer, 49, 0, 0xee);

	sprintf(buffer, "%u.%02uA", metter.outCurrentValue / 100, metter.outCurrentValue % 100);
	GUI_print3(buffer, 49, 10, 0xee);

	uint16_t eta = ((uint32_t) metter.outVoltageValue * metter.outCurrentValue * 1000) / (metter.inVoltageValue * metter.inCurrentValue);
	sprintf(buffer, "%u.%u%% ", eta / 10, eta % 10);
	GUI_print3(buffer, 32, 20, 0xee);
}

/* *****************
 * TCD5: ADC conversion trigger timer interrupt
 ***************** */
ISR (TCD5_OVF_vect) {
	TCD5.INTFLAGS = TC5_OVFIF_bm;

	metter.toggleInput();
	metter.start();

	LED_TOGGLE;
}

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH0_vect) {
	metter.storeReadout();
}

int main(void) {
	LED_INIT;
	GUI_Init();

	sprintf(buffer, "Ui=");
	GUI_print3(buffer, 0, 0, 0x66);

	sprintf(buffer, "Ii=");
	GUI_print3(buffer, 0, 10, 0x66);

	sprintf(buffer, "Uo=");
	GUI_print3(buffer, 40, 0, 0x66);

	sprintf(buffer, "Io=");
	GUI_print3(buffer, 40, 10, 0x66);

	sprintf(buffer, "Eta=");
	GUI_print3(buffer, 20, 20, 0x66);

	Timer displayTimer(&TCC5, 500);
	Timer adcTimer(&TCD5, 100);

	displayTimer.Init(TC_OVFINTLVL_LO_gc);
	adcTimer.Init(TC_OVFINTLVL_MED_gc);
	metter.init();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	adcTimer.Enable();
	displayTimer.Enable();

    while (1) {
    }
}

