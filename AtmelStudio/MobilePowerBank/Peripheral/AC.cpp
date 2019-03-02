/*
 * CPPFile1.cpp
 *
 * Created: 2019-03-02 18:13:04
 *  Author: Chipotle
 */ 

#include "AC.hpp"

void AC::init() {
	ACB.AC0MUXCTRL = AC_MUXPOS2_bm | AC_MUXPOS1_bm | AC_MUXNEG2_bm | AC_MUXNEG1_bm | AC_MUXNEG0_bm; // Positive is PIN6, Negative is Vcc Scaler
	ACB.CTRLB = AC_SCALEFAC3_bm + AC_SCALEFAC1_bm; // Scaler is (10+1)/64 * Vcc
	ACB.AC0CTRL = AC_INTMODE_FALLING_gc | AC_INTLVL_HI_gc | AC_HYSMODE_LARGE_gc | AC_HSMODE_bm;
}

void AC::start() {
	ACB.AC0CTRL |= AC_ENABLE_bm;
}
