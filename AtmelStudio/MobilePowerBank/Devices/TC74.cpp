#include <avr/io.h>

#include "TC74.h"

void TC74::init() {
	TWI_init();
}

uint8_t TC74::readTemperature() {
	uint8_t read;
	TWI_write_reg(TC74A0_ADDRESS, TC74A0_READ_TEMPERATURE, 0, 0);
	TWI_read(TC74A0_ADDRESS, &read, 1);
	return read;
}
