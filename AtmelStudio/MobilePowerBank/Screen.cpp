/*
 * Screen.cpp
 *
 * Created: 2018-10-04 11:50:08
 *  Author: Rodos
 */ 

#include "Screen.hpp"

#define BATT_MIN 223
#define BATT_MAX 295

char buffer[22];

void Screen::init () {
	GUI_Init();
	drawTemplate();
}

void Screen::shutdown() {
	GUI_Shutdown();
}

bool Screen::isActive() {
	return GUI_IsActive();
}

void Screen::drawTemplate() {
	sprintf(buffer, "I=");
	GUI_print3(buffer, 0, 0, 0x44);

	sprintf(buffer, "O2=");
	GUI_print3(buffer, 0, 9, 0x44);

	sprintf(buffer, "O3=");
	GUI_print3(buffer, 0, 18, 0x44);

	sprintf(buffer, "Bat=");
	GUI_print3(buffer, 0, 30, 0x44);

	sprintf(buffer, "Eta=");
	GUI_print3(buffer, 30, 30, 0x44);

	sprintf(buffer, "Time:");
	GUI_print3(buffer, 0, 40, 0x44);

	sprintf(buffer, "Amps:");
	GUI_print3(buffer, 0, 50, 0x44);
}

void Screen::drawElectricParams(uint16_t inVoltageValue, uint16_t inCurrentValue, uint16_t out2VoltageValue, uint16_t out2CurrentValue, uint16_t out3VoltageValue, uint16_t out3CurrentValue) {
	// In
	uint32_t inputPower = ((uint32_t) inVoltageValue) * inCurrentValue;
	sprintf(buffer, "%3u.%uV %u.%02uA %u.%uW", inVoltageValue / 10, inVoltageValue % 10, inCurrentValue / 100, inCurrentValue % 100, (uint16_t) inputPower / 1000, ((uint16_t) inputPower / 100) % 10);
	GUI_print3(buffer, 7, 0, 0xee);

	// Out 2
	uint32_t output2Power = ((uint32_t) out2VoltageValue) * out2CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW", out2VoltageValue / 10, out2VoltageValue % 10, out2CurrentValue / 100, out2CurrentValue % 100, (uint16_t) output2Power / 1000, ((uint16_t) output2Power / 100) % 10);
	GUI_print3(buffer, 9, 9, 0xee);

	// Out 3
	uint32_t output3Power = ((uint32_t) out3VoltageValue) * out3CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW", out3VoltageValue / 10, out3VoltageValue % 10, out3CurrentValue / 100, out3CurrentValue % 100, (uint16_t) output3Power / 1000, ((uint16_t) output3Power / 100) % 10);
	GUI_print3(buffer, 9, 18, 0xee);

	sprintf(buffer, "%u%%", (inVoltageValue - BATT_MIN) * 100 / (BATT_MAX - BATT_MIN));
	GUI_print3(buffer, 12, 30, 0xee);

	uint16_t eta = (output2Power * 1000) / inputPower;
	sprintf(buffer, "%u.%u%% ", eta / 10, eta % 10);
	GUI_print3(buffer, 42, 30, 0xee);
}

void Screen::drawTime(uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds) {
	sprintf(buffer, "%ud %uh:%02um:%02us", days, hours, minutes, seconds);
	GUI_print3(buffer, 15, 40, 0xee);
}

void Screen::drawAmpsConsumed(uint32_t ampsConsumed) {
	uint16_t ampHours = ampsConsumed / 3600;
	sprintf(buffer, "%u.%02uA/h", ampHours / 100, ampHours % 100);
	GUI_print3(buffer, 15, 50, 0xee);
}

void Screen::drawCounter(uint16_t count) {
	sprintf(buffer, "sw=%u", count);
	GUI_print3(buffer, 47, 30, 0x66);
}
