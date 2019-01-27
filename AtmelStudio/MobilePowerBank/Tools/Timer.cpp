/*
 * Switch.cpp
 *
 * Created: 2017-06-28 22:00:45
 *  Author: Rodos
 */ 
#include <avr/io.h>

#include "Timer.hpp"

void Timer::Init(uint8_t intLevel) {
	timer->PER = per;
	timer->INTCTRLA = intLevel;
}

void Timer::Enable() {
	timer->CTRLA = TC_CLKSEL_DIV1024_gc;
	timer->INTFLAGS = TC0_OVFIF_bm;
}

void Timer::Disable() {
	timer->CTRLA = TC_CLKSEL_OFF_gc;
	timer->INTFLAGS = TC0_OVFIF_bm;
}
