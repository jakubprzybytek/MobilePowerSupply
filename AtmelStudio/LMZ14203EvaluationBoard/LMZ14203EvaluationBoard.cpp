/*out
 * GccApplication1.cpp
 *
 * Created: 2018-09-22 13:35:49
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Screen.hpp"
#include "IO/Metter.h"

#include "Tools/Timer.hpp"
#include "Tools/Switch.hpp"

#include "Peripheral/RTC.hpp"

#define LED_INIT	PORTA.DIRSET = PIN6_bm
#define LED_TOGGLE	PORTA.OUTTGL = PIN6_bm

InterruptSwitch button(&PORTA, PIN7_bm, &(PORTA.PIN7CTRL));	

Screen screen;

Metter metter;

Clock clock;

uint32_t ampsConsumed; // per second

uint16_t count;

/* *****************
 * TCC5: Display refresh timer interrupt
 ***************** */
ISR (TCC5_OVF_vect) {
	TCC5.INTFLAGS = TC5_OVFIF_bm;
	screen.drawElectricParams(metter.inVoltageValue, metter.inCurrentValue, metter.outVoltageValue, metter.outCurrentValue);
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

/* *****************
 * Port A: Switch 0 int
 ***************** */
ISR (PORTA_INT_vect) {
	button.enableInterrupt();
	
	count++;
	screen.drawCounter(count);
}

/* *****************
 * RTC: 1 sec INT
 ***************** */
ISR (RTC_OVF_vect) {
	clock.countSecond();
	ampsConsumed += metter.inCurrentValue;
	screen.drawTime(clock.days, clock.hours, clock.minutes, clock.seconds);
	screen.drawAmpsConsumed(ampsConsumed);
}

int main(void) {
	LED_INIT;
	screen.init();

	Timer displayTimer(&TCC5, 500);
	Timer adcTimer(&TCD5, 100);

	displayTimer.Init(TC_OVFINTLVL_LO_gc);
	adcTimer.Init(TC_OVFINTLVL_MED_gc);
	
	clock.init();

	metter.init();
	button.init();
	
	screen.drawTemplate();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	adcTimer.Enable();
	displayTimer.Enable();

	clock.start();

    while (1) {
    }
}

