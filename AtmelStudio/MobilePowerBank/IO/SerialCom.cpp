/* 
* SerialCom.cpp
*
* Created: 2019-04-12 19:11:25
* Author: Chipotle
*/

#include <stdio.h>
#include <string.h>

#include "SerialCom.h"

void SerialCom::init() {
	this->usart.init();

	// TODO: un-hardcode usartc1
	this->transmitDMA.init(this->transmitBuffer, (void*)&USARTC1.DATA, DMA_CH_TRIGSRC_USARTC1_DRE_gc, 1, DMA_CH_BURSTLEN_1BYTE_gc, 1);
	this->transmitDMA.initSourceReloadOnTransactionDestReloadOnBurst();
}

bool SerialCom::processReceivedData(uint8_t data) {
	if (dataWaiting || receiveBufferIndex == RECEIVE_BUFFER_SIZE) {
		return true;
	}

	if (data != 10 && data != 13) {
		receiveBuffer[receiveBufferIndex++] = data;
	} else {
		receiveBuffer[receiveBufferIndex] = 0;
		dataWaiting = true;
	}

	return dataWaiting;
}

char* SerialCom::getReceivedData() {
	receiveBufferIndex = 0;
	dataWaiting = false;
	return receiveBuffer;
}
#define BATT_MIN 223
#define BATT_MAX 294
void SerialCom::sendData(Measurements& m, Clock& clock, uint32_t ampsConsumed, uint8_t temp) {
	char* buffer = this->transmitBuffer;

	// In
	uint32_t inputPower = ((uint32_t) m.inVoltageValue) * m.inCurrentValue;
	buffer += sprintf(buffer, "Input: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", m.inVoltageValue / 10, m.inVoltageValue % 10, m.inCurrentValue / 100, m.inCurrentValue % 100, (uint16_t) inputPower / 1000, ((uint16_t) inputPower / 100) % 10);

	// Out 2
	uint32_t output1Power = ((uint32_t) m.out1VoltageValue) * m.out1CurrentValue;
	buffer += sprintf(buffer, "Out 1: %2u.%uV %u.%02uA %u.%uW\n", m.out1VoltageValue / 10, m.out1VoltageValue % 10, m.out1CurrentValue / 100, m.out1CurrentValue % 100, (uint16_t) output1Power / 1000, ((uint16_t) output1Power / 100) % 10);

	// Out 2
	uint32_t output2Power = ((uint32_t) m.out2VoltageValue) * m.out2CurrentValue;
	buffer += sprintf(buffer, "Out 2: %2u.%uV %u.%02uA %u.%uW\n", m.out2VoltageValue / 10, m.out2VoltageValue % 10, m.out2CurrentValue / 100, m.out2CurrentValue % 100, (uint16_t) output2Power / 1000, ((uint16_t) output2Power / 100) % 10);

	// Out 3
	uint32_t output3Power = ((uint32_t) m.out3VoltageValue) * m.out3CurrentValue;
	buffer += sprintf(buffer, "Out 3: %2u.%uV %i.%02iA %u.%uW\n", m.out3VoltageValue / 10, m.out3VoltageValue % 10, m.out3CurrentValue / 100, m.out3CurrentValue % 100, (uint16_t) output3Power / 1000, ((uint16_t) output3Power / 100) % 10);

	// Out 4
	uint32_t output4Power = ((uint32_t) m.out4VoltageValue) * m.out4CurrentValue;
	buffer += sprintf(buffer, "Out 4: %2u.%uV %u.%02uA %u.%uW\n", m.out4VoltageValue / 10, m.out4VoltageValue % 10, m.out4CurrentValue / 100, m.out4CurrentValue % 100, (uint16_t) output4Power / 1000, ((uint16_t) output4Power / 100) % 10);

	// Out 5
	uint32_t output5Power = ((uint32_t) m.out5VoltageValue) * m.out5CurrentValue;
	buffer += sprintf(buffer, "Out 5: %2u.%uV %u.%02uA %u.%uW\n", m.out5VoltageValue / 10, m.out5VoltageValue % 10, m.out5CurrentValue / 100, m.out5CurrentValue % 100, (uint16_t) output5Power / 1000, ((uint16_t) output5Power / 100) % 10);

	// amps consumed
	uint16_t ampHours = ampsConsumed / 3600;
	buffer += sprintf(buffer, "Amps consumed: %u.%02u [A/h]\n", ampHours / 100, ampHours % 100);

	// temperature
	buffer += sprintf(buffer, "Temperature: %u [`C]\n", temp);

	// Time
	buffer += sprintf(buffer, "Time: %02u:%02u:%02u\n", clock.hours, clock.minutes, clock.seconds);

	// Batt
	if (m.inVoltageValue >= BATT_MIN && m.inVoltageValue <= BATT_MAX) {
		buffer += sprintf(buffer, "Battery: %02u%%\n", (m.inVoltageValue - BATT_MIN) * 100 / (BATT_MAX - BATT_MIN));
		} else {
		buffer += sprintf(buffer, "Battery: !!!\n");
	}

	sprintf(buffer, "Sent %u bytes\n", strlen(this->transmitBuffer) + 15);

	this->transmitDMA.start(strlen(this->transmitBuffer));
}
