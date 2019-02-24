#include "../Peripheral/TWI.h"

#define TC74A0_ADDRESS 0b10010000 >> 1

#define TC74A0_READ_TEMPERATURE 0x00
#define TC74A0_READ_WRITE_CONFIGURATION 0x01

class TC74 {

public:
	TC74() {}

	void init();
	uint8_t readTemperature();
};
