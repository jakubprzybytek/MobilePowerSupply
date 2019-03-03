/*
 * RTC.cpp
 *
 * Created: 2018-10-04 12:57:07
 *  Author: Rodos
 */ 

#include <avr/io.h>

#include "RTC.hpp"

void Clock::init() {
	OSC.CTRL |= OSC_RC32KEN_bm;

	do {
		/* Wait for the 32kHz oscillator to stabilize. */
	} while ( ( OSC.STATUS & OSC_RC32KRDY_bm ) == 0);


	/* Set internal 32kHz oscillator as clock source for RTC. */
	CLK.RTCCTRL = CLK_RTCSRC_RCOSC_gc | CLK_RTCEN_bm;

	RTC.PER = 1023;
	RTC.INTCTRL = RTC_OVFINTLVL_LO_gc;
}

void Clock::start() {
	RTC.CTRL = RTC_PRESCALER_DIV1_gc;
}

void Clock::countSecond() {
	seconds++;
	if (seconds >= 60) {
		minutes++;
		seconds = 0;

		if (minutes >= 60) {
			hours++;
			minutes = 0;

			if (hours >= 24) {
				days++;
				hours = 0;
			}
		}
	}
}

void Clock::reset() {
	seconds = 0;
	minutes = 0;
	hours = 0;
	days = 0;
}
