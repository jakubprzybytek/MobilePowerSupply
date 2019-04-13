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
#include "Events.h"

#include "Devices/TC74.h"

#include "IO/GUI.h"
#include "IO/Metter.h"
#include "IO/SerialCom.h"

#include "Peripheral/RTC.hpp"
#include "Peripheral/AC.hpp"

#include "Tools/Timer.hpp"
#include "Tools/Switch.hpp"
#include "Tools/EEPROM.hpp"

Screen screen;
SerialCom serialCom;
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

Events events;

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

			resetStatus();

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
 * USART C1: Received data (Low)
 ***************** */
ISR (USARTC1_RXC_vect) {
	uint8_t data = USARTC1.DATA;
	if (serialCom.processReceivedData(data)) {
		events.submit(USART_MESSAGE_RECEIVED);
	}
}

/* *****************
 * DMA CH0: DMA transaction finished interrupt (Medium)
 ***************** */
ISR (DMA_CH0_vect) {
	events.submit(ADC_DMA_A_FINISHED);
	DMA.INTFLAGS = DMA_CH0TRNIF_bm;
}

/* *****************
 * DMA CH1: DMA transaction finished interrupt (Medium)
 ***************** */
ISR (DMA_CH1_vect) {
	events.submit(ADC_DMA_B_FINISHED);
	DMA.INTFLAGS = DMA_CH1TRNIF_bm;
}

/* *****************
 * DMA CH2: DMA transaction finished interrupt (Medium)
 ***************** */
ISR (DMA_CH2_vect) {
	// TODO: disabe INT
	DMA.INTFLAGS = DMA_CH2TRNIF_bm;
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

void resetStatus() {
	clock.reset();
	ampsConsumed = 0;
}

int main(void)
{
	Timer displayTimer(&TCC0, 200);
	AC inputPowerComparator(&ACB);

	LED_INIT
	screen.init(true);
	metter.init();
	serialCom.init();
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
		Event event = events.get();
		if (event == USART_MESSAGE_RECEIVED) {
			char* command = serialCom.getReceivedData();
			switch (command[0]) {
				case 's':
					serialCom.sendData(metter.measurements, clock, ampsConsumed, temp);
					break;
				case 'r':
					resetStatus();
					serialCom.sendMessage("Clock and counters are reset!\n");
					break;
				case 'd':
					char buffer[100];
					sprintf(buffer, "Debug: EEPROM writes - %u, max waiting events - %u\n", eeprom.eepromWrites, events.maxEventsListIndex);
					serialCom.sendMessage(buffer);
					break;
				default:
					serialCom.sendHelp();
			}
		}

		if (event == ADC_DMA_A_FINISHED) {
			metter.stopA();
			metter.storeReadoutA();
		}

		if (event == ADC_DMA_B_FINISHED) {
			metter.stopB();
			metter.storeReadoutB();
		}
	}
}

