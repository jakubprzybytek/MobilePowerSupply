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

#include "MobilePowerBank.h"

#include "Screen.hpp"

#include "Devices/TC74.h"

#include "IO/GUI.h"
#include "IO/Metter.h"

#include "Peripheral/RTC.hpp"
#include "Peripheral/AC.hpp"

#include "Tools/Timer.hpp"
#include "Tools/Switch.hpp"
#include "Tools/EEPROM.hpp"

Screen screen;
Metter metter;
TC74 termometer;

Clock clock;
uint32_t ampsConsumed; // per second
uint8_t temp;

InterruptSwitch button(&PORTF, PIN3_bm, &(PORTF.PIN3CTRL));
Timer buttonTimer(&TCD0, 50);
uint16_t buttonCounter;
uint8_t secondsToReset;

EEPROMInterface eeprom;

/* *****************
 * RTC: 1 sec INT (Low)
 ***************** */
ISR (RTC_OVF_vect) {
	clock.countSecond();
	ampsConsumed += metter.measurements.inCurrentValue;

	if (screen.isActive()) {
		drawStatusBar(false);
	}
}

/* *****************
 * TCC0: Display refresh timer interrupt (Low)
 ***************** */
ISR (TCC0_OVF_vect) {
	LED_TOGGLE
	if (screen.isActive()) {
		screen.drawElectricParams(metter.measurements);
	}
	metter.toggleInput();
	metter.start();
}

/* *****************
 * TCD0: Button check timer interrupt (Low)
 ***************** */
ISR (TCD0_OVF_vect) {
	LED_TOGGLE

	if (button.isUp()) {
		buttonTimer.Disable();

		if (secondsToReset == 5) { // quick button press: toggle screen
			if (screen.isActive()) {
				screen.shutdown();
			} else {
				screen.init(false);
			}
		}

		secondsToReset = 0;

		if (screen.isActive()) {
			drawStatusBar(true);
		}
	} else { // button still pressed
		buttonCounter++;
		secondsToReset = 5 - MIN(buttonCounter/39, 5);

		if (secondsToReset == 0) {
			buttonTimer.Disable();

			clock.reset();
			ampsConsumed = 0;

			if (screen.isActive()) {
				drawStatusBar(true);
			}
		}
	}
}

/* *****************
 * Port F: Switch 0 int (Low)
 ***************** */
ISR (PORTF_INT0_vect) {
	buttonCounter = 0;
	buttonTimer.Enable();
}

/* *****************
 * DMA CH0: DMA transaction finished interrupt (Medium)
 ***************** */
ISR (DMA_CH0_vect) {
	metter.stopA();
	metter.storeReadoutA();
	DMA.INTFLAGS = DMA_CH0TRNIF_bm;
}

/* *****************
 * DMA CH1: DMA transaction finished interrupt (Medium)
 ***************** */
ISR (DMA_CH1_vect) {
	metter.stopB();
	metter.storeReadoutB();
	DMA.INTFLAGS = DMA_CH1TRNIF_bm;
}

/* *****************
 * ACB: Falling edge detected in input voltage (High)
***************** */
ISR (ACB_AC0_vect) {
	screen.shutdown();
	LED_SET
	eeprom.storeData(clock, &ampsConsumed);
}

void drawStatusBar(bool firstDraw) {
	
	if (secondsToReset > 0 && secondsToReset < 5) {
		screen.drawSecondsToReset(secondsToReset);
		return;
	}
	
	if (clock.seconds % 10 == 0 || firstDraw) { // every ten seconds
		temp = termometer.readTemperature();
	}

	screen.drawTime(clock.days, clock.hours, clock.minutes, clock.seconds);

	if (clock.seconds % 10 == 0 || firstDraw) {
		screen.drawTemperature(temp);
	}
	if ((clock.seconds + 5) % 10 == 0) {
		screen.drawAmpsConsumed(ampsConsumed);
	}
}

int main(void)
{
	Timer displayTimer(&TCC0, 200);
	AC inputPowerComparator(&ACB);

	LED_INIT
	screen.init(true);
	metter.init();
	clock.init();
	displayTimer.Init(TC_OVFINTLVL_LO_gc);
	buttonTimer.Init(TC_OVFINTLVL_MED_gc);
	button.init();
	termometer.init();
	inputPowerComparator.init();
	
	displayTimer.Enable();
	inputPowerComparator.start();

	eeprom.loadData(clock, &ampsConsumed);
	clock.start();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	drawStatusBar(true);

    while (1) {
	}
}

