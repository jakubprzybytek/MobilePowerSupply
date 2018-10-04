/*
 * Screen.cpp
 *
 * Created: 2018-10-04 11:50:08
 *  Author: Rodos
 */ 

#include "Screen.hpp"
	
char buffer[22];

void Screen::init () {
	GUI_Init();
}

void Screen::drawTemplate() {
	sprintf(buffer, "Ui=");
	GUI_print3(buffer, 0, 0, 0x66);

	sprintf(buffer, "Ii=");
	GUI_print3(buffer, 0, 10, 0x66);

	sprintf(buffer, "Pi=");
	GUI_print3(buffer, 0, 20, 0x66);

	sprintf(buffer, "Uo=");
	GUI_print3(buffer, 40, 0, 0x66);

	sprintf(buffer, "Io=");
	GUI_print3(buffer, 40, 10, 0x66);

	sprintf(buffer, "Po=");
	GUI_print3(buffer, 40, 20, 0x66);

	sprintf(buffer, "Eta=");
	GUI_print3(buffer, 20, 30, 0x66);
}

void Screen::drawElectricParams(uint16_t inVoltageValue, uint16_t inCurrentValue, uint16_t outVoltageValue, uint16_t outCurrentValue) {
	sprintf(buffer, "%u.%uV", inVoltageValue / 10, inVoltageValue % 10);
	GUI_print3(buffer, 9, 0, 0xee);

	sprintf(buffer, "%u.%02uA", inCurrentValue / 100, inCurrentValue % 100);
	GUI_print3(buffer, 9, 10, 0xee);

	uint32_t inputPower = ((uint32_t) inVoltageValue) * inCurrentValue;
	sprintf(buffer, "%u.%uW", (uint16_t) inputPower / 1000, ((uint16_t) inputPower / 100) % 10);
	GUI_print3(buffer, 9, 20, 0xee);

	sprintf(buffer, "%u.%uV", outVoltageValue / 10, outVoltageValue % 10);
	GUI_print3(buffer, 49, 0, 0xee);

	sprintf(buffer, "%u.%02uA", outCurrentValue / 100, outCurrentValue % 100);
	GUI_print3(buffer, 49, 10, 0xee);

	uint32_t outputPower = ((uint32_t) outVoltageValue) * outCurrentValue;
	sprintf(buffer, "%u.%uW", (uint16_t) outputPower / 1000, ((uint16_t) outputPower / 100) % 10);
	GUI_print3(buffer, 49, 20, 0xee);

	uint16_t eta = (outputPower * 1000) / inputPower;
	sprintf(buffer, "%u.%u%% ", eta / 10, eta % 10);
	GUI_print3(buffer, 32, 30, 0xee);
}

void Screen::drawCounter(uint16_t count) {
	sprintf(buffer, "sw=%u", count);
	GUI_print3(buffer, 47, 30, 0x66);
}