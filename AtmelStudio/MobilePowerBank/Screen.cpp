/*
 * Screen.cpp
 *
 * Created: 2018-10-04 11:50:08
 *  Author: Rodos
 */ 

#include "Screen.hpp"

#define TEMPLATE_PATTERN 0x22
#define MAIN_PATTERN 0xee
#define MAIN_DIM_PATTERN 0x44

#define BATT_MIN 223
#define BATT_MAX 295

char buffer[22];

void Screen::init (bool clean) {
	GUI_Init();
	if (clean) {
		GUI_Clean();
	}

	drawTemplate();
}

void Screen::shutdown() {
	GUI_Shutdown();
}

bool Screen::isActive() {
	return GUI_IsActive();
}

void Screen::drawTemplate() {
	sprintf(buffer, "I");
	GUI_print3(buffer, 3, 0, TEMPLATE_PATTERN);

	sprintf(buffer, "O1");
	GUI_print3(buffer, 0, 10, TEMPLATE_PATTERN);

	sprintf(buffer, "O2");
	GUI_print3(buffer, 0, 18, TEMPLATE_PATTERN);

	sprintf(buffer, "O3");
	GUI_print3(buffer, 0, 26, TEMPLATE_PATTERN);

	sprintf(buffer, "O4");
	GUI_print3(buffer, 0, 34, TEMPLATE_PATTERN);

	sprintf(buffer, "O5");
	GUI_print3(buffer, 0, 42, TEMPLATE_PATTERN);

	//sprintf(buffer, "Eta=");
	//GUI_print3(buffer, 30, 30, 0x44);

	sprintf(buffer, "Ah");
	GUI_print3(buffer, 0, 57, TEMPLATE_PATTERN);

	sprintf(buffer, "T");
	GUI_print3(buffer, 22, 57, TEMPLATE_PATTERN);

	sprintf(buffer, "B");
	GUI_print3(buffer, 51, 57, TEMPLATE_PATTERN);
}

void Screen::drawElectricParams(Measurements& m) {
	// In
	uint32_t inputPower = ((uint32_t) m.inVoltageValue) * m.inCurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW ", m.inVoltageValue / 10, m.inVoltageValue % 10, m.inCurrentValue / 100, m.inCurrentValue % 100, (uint16_t) inputPower / 1000, ((uint16_t) inputPower / 100) % 10);
	GUI_print3(buffer, 7, 0, m.inCurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Out 1
	uint32_t output1Power = ((uint32_t) m.out1VoltageValue) * m.out1CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW ", m.out1VoltageValue / 10, m.out1VoltageValue % 10, m.out1CurrentValue / 100, m.out1CurrentValue % 100, (uint16_t) output1Power / 1000, ((uint16_t) output1Power / 100) % 10);
	GUI_print3(buffer, 7, 10, m.out1CurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Out 2
	uint32_t output2Power = ((uint32_t) m.out2VoltageValue) * m.out2CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW ", m.out2VoltageValue / 10, m.out2VoltageValue % 10, m.out2CurrentValue / 100, m.out2CurrentValue % 100, (uint16_t) output2Power / 1000, ((uint16_t) output2Power / 100) % 10);
	GUI_print3(buffer, 7, 18, m.out2CurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Out 3
	uint32_t output3Power = ((uint32_t) m.out3VoltageValue) * m.out3CurrentValue;
	sprintf(buffer, "%2u.%uV %i.%02iA %u.%uW ", m.out3VoltageValue / 10, m.out3VoltageValue % 10, m.out3CurrentValue / 100, m.out3CurrentValue % 100, (uint16_t) output3Power / 1000, ((uint16_t) output3Power / 100) % 10);
	GUI_print3(buffer, 7, 26, m.out3CurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Out 4
	uint32_t output4Power = ((uint32_t) m.out4VoltageValue) * m.out4CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW ", m.out4VoltageValue / 10, m.out4VoltageValue % 10, m.out4CurrentValue / 100, m.out4CurrentValue % 100, (uint16_t) output4Power / 1000, ((uint16_t) output4Power / 100) % 10);
	GUI_print3(buffer, 7, 34, m.out4CurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Out 5
	uint32_t output5Power = ((uint32_t) m.out5VoltageValue) * m.out5CurrentValue;
	sprintf(buffer, "%2u.%uV %u.%02uA %u.%uW ", m.out5VoltageValue / 10, m.out5VoltageValue % 10, m.out5CurrentValue / 100, m.out5CurrentValue % 100, (uint16_t) output5Power / 1000, ((uint16_t) output5Power / 100) % 10);
	GUI_print3(buffer, 7, 42, m.out5CurrentValue > 0 ? MAIN_PATTERN : MAIN_DIM_PATTERN);

	// Batt
	sprintf(buffer, "%u%%", (m.inVoltageValue - BATT_MIN) * 100 / (BATT_MAX - BATT_MIN));
	GUI_print3(buffer, 55, 57, MAIN_PATTERN);

	// eta
	//uint16_t eta = (output2Power * 1000) / inputPower;
	//sprintf(buffer, "%u.%u%% ", eta / 10, eta % 10);
	//GUI_print3(buffer, 42, 30, 0xee);
}

void Screen::drawTime(uint8_t days, uint8_t hours, uint8_t minutes, uint8_t seconds) {
	sprintf(buffer, "%u:%02u:%02u", hours, minutes, seconds);
	GUI_print3(buffer, 26, 57, 0xee);
}

void Screen::drawAmpsConsumed(uint32_t ampsConsumed) {
	uint16_t ampHours = ampsConsumed / 3600;
	sprintf(buffer, "%u.%02u", ampHours / 100, ampHours % 100);
	GUI_print3(buffer, 7, 57, 0xee);
}
