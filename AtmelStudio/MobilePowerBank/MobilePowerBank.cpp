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

EEPROMInterface eeprom;

/* *****************
 * RTC: 1 sec INT
 ***************** */
ISR (RTC_OVF_vect) {
	clock.countSecond();
	ampsConsumed += metter.measurements.inCurrentValue;

	drawEnvironmentalParams(false);
}

/* *****************
 * TCC5: Display refresh timer interrupt
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
 * DMA CH0: DMA transaction finished interrupt
 ***************** */
ISR (DMA_CH0_vect) {
	metter.stopA();
	metter.storeReadoutA();
	DMA.INTFLAGS = DMA_CH0TRNIF_bm;
}

/* *****************
 * DMA CH1: DMA transaction finished interrupt
 ***************** */
ISR (DMA_CH1_vect) {
	metter.stopB();
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
		screen.init(false);
	}
}

/* *****************
 * ACB: Falling edge detected in input voltage
***************** */
ISR (ACB_AC0_vect) {
	screen.shutdown();
	LED_SET
	eeprom.storeData(clock, &ampsConsumed);
}

void drawEnvironmentalParams(bool firstDraw) {
	if (clock.seconds % 10 == 0 || firstDraw) { // every ten seconds
		temp = termometer.readTemperature();
	}

	if (screen.isActive()) {
		screen.drawTime(clock.days, clock.hours, clock.minutes, clock.seconds);

		if (clock.seconds % 10 == 0 || firstDraw) {
			screen.drawTemperature(temp);
		}
		if ((clock.seconds + 5) % 10 == 0) {
			screen.drawAmpsConsumed(ampsConsumed);
		}
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

	drawEnvironmentalParams(true);

    while (1) {
	}
}

