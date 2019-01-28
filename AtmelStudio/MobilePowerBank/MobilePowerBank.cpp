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

#include "Screen.hpp"

#include "IO/GUI.h"
#include "IO/Metter.h"

#include "Peripheral/RTC.hpp"

#include "Tools/Timer.hpp"
#include "Tools/Switch.hpp"

Screen screen;
Metter metter;

Clock clock;
uint32_t ampsConsumed; // per second

InterruptSwitch button(&PORTF, PIN3_bm, &(PORTF.PIN3CTRL));

uint16_t count;

/* *****************
 * RTC: 1 sec INT
 ***************** */
ISR (RTC_OVF_vect) {
	clock.countSecond();
	ampsConsumed += metter.inCurrentValue;
	
	if (screen.isActive()) {
		screen.drawTime(clock.days, clock.hours, clock.minutes, clock.seconds);
		screen.drawAmpsConsumed(ampsConsumed);
	}
}

/* *****************
 * TCC5: Display refresh timer interrupt
 ***************** */
ISR (TCC0_OVF_vect) {
	PORTF.OUTTGL = PIN2_bm;
	if (screen.isActive()) {
		screen.drawElectricParams(metter.inVoltageValue, metter.inCurrentValue, metter.out2VoltageValue, metter.out2CurrentValue, metter.out3VoltageValue, metter.out3CurrentValue);
	}
	metter.start();
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

/* *****************
 * Port F: Switch 0 int
 ***************** */
ISR (PORTF_INT0_vect) {
	if (screen.isActive()) {
		screen.shutdown();
	} else {
		screen.init();
	}
}

int main(void)
{
	PORTF.DIRSET = PIN2_bm;

	Timer displayTimer(&TCC0, 200);

	screen.init();
	metter.init();
	clock.init();
	displayTimer.Init(TC_OVFINTLVL_LO_gc);
	button.init();
	
	clock.start();
	displayTimer.Enable();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

    while (1) 
    { }
}

