/*
 * Switch.cpp
 *
 * Created: 2017-06-28 22:00:45
 *  Author: Rodos
 */ 
#include <avr/io.h>

#include "Switch.hpp"

void InterruptSwitch::init() {

	port->DIRCLR = pin;
	*(portCtrl) = PORT_OPC_PULLUP_gc | PORT_ISC_FALLING_gc;
	port->INTMASK = pin;

	enableInterrupt();
}

void InterruptSwitch::enableInterrupt() {
	port->INTCTRL = PORT_INTLVL_LO_gc;
	port->INTFLAGS = PORT_INT7IF_bm;
}

void InterruptSwitch::disableInterrupt() {
	port->INTCTRL = PORT_INTLVL_OFF_gc;
}

bool InterruptSwitch::isUp() {
	return port->IN & pin;
}
