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

	this->transmitDMA.init(this->transmitBuffer, (void*)&(this->usart.usart->DATA), DMA_CH_TRIGSRC_USARTC1_DRE_gc, 1, DMA_CH_BURSTLEN_1BYTE_gc, 1);
	this->transmitDMA.initAddressBehaviour(DMA_CH_SRCRELOAD_TRANSACTION_gc | DMA_CH_SRCDIR_INC_gc | DMA_CH_DESTRELOAD_BURST_gc | DMA_CH_DESTDIR_FIXED_gc);
}

bool SerialCom::processReceivedData(uint8_t data) {

	// ignore \r and any other transmission when the old message is not consumed
	if (dataWaiting || data == '\r') {
		return false;
	}

	if (receiveBufferIndex == RECEIVE_BUFFER_SIZE) {
		dataWaiting = true;
		return dataWaiting;
	}

	if (data == '\n') {
		receiveBuffer[receiveBufferIndex++] = 0x00;
		dataWaiting = true;
	} else {
		receiveBuffer[receiveBufferIndex++] = data;
	}

	return dataWaiting;
}

char* SerialCom::getReceivedData() {
	receiveBufferIndex = 0;
	dataWaiting = false;
	return receiveBuffer;
}

void SerialCom::sendMessage(const char* message) {
	strcpy(this->transmitBuffer, message);
	this->transmitDMA.start(strlen(this->transmitBuffer));
}

void SerialCom::sendHelp() {
	char* buffer = this->transmitBuffer;
	buffer += sprintf(buffer, "Power Mobile Bank\n");
	buffer += sprintf(buffer, "Commands:\n");
	buffer += sprintf(buffer, " s - print current status\n");
	buffer += sprintf(buffer, " r - reset timer and counter of consumed amps\n");
	buffer += sprintf(buffer, " d - print debug information\n");
	buffer += sprintf(buffer, " i <name> - Sets display name for Input to <name>. Max 4 characters.\n");
	buffer += sprintf(buffer, " o<n> <name> - Sets display name for Output <n> to <name>. Max 4 characters. <n> can be from 1 to 5.\n");
	buffer += sprintf(buffer, " any other - this help\n");

	sprintf(buffer, "Sent %u bytes.\n", strlen(this->transmitBuffer) + 16);
	this->transmitDMA.start(strlen(this->transmitBuffer));
}

void SerialCom::sendData(char names[6][5], Measurements& m, Clock& clock, uint32_t ampsConsumed, uint8_t temp) {
	char* buffer = this->transmitBuffer;

	// In
	uint32_t inputPower = ((uint32_t) m.inVoltageValue) * m.inCurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", names[0], m.inVoltageValue / 10, m.inVoltageValue % 10, m.inCurrentValue / 100, m.inCurrentValue % 100, (uint16_t) inputPower / 1000, ((uint16_t) inputPower / 100) % 10);

	// Out 2
	uint32_t output1Power = ((uint32_t) m.out1VoltageValue) * m.out1CurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", names[1], m.out1VoltageValue / 10, m.out1VoltageValue % 10, m.out1CurrentValue / 100, m.out1CurrentValue % 100, (uint16_t) output1Power / 1000, ((uint16_t) output1Power / 100) % 10);

	// Out 2
	uint32_t output2Power = ((uint32_t) m.out2VoltageValue) * m.out2CurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", names[2], m.out2VoltageValue / 10, m.out2VoltageValue % 10, m.out2CurrentValue / 100, m.out2CurrentValue % 100, (uint16_t) output2Power / 1000, ((uint16_t) output2Power / 100) % 10);

	// Out 3
	uint32_t output3Power = ((uint32_t) m.out3VoltageValue) * m.out3CurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %i.%02i [A], %u.%u [W]\n", names[3], m.out3VoltageValue / 10, m.out3VoltageValue % 10, m.out3CurrentValue / 100, m.out3CurrentValue % 100, (uint16_t) output3Power / 1000, ((uint16_t) output3Power / 100) % 10);

	// Out 4
	uint32_t output4Power = ((uint32_t) m.out4VoltageValue) * m.out4CurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", names[4], m.out4VoltageValue / 10, m.out4VoltageValue % 10, m.out4CurrentValue / 100, m.out4CurrentValue % 100, (uint16_t) output4Power / 1000, ((uint16_t) output4Power / 100) % 10);

	// Out 5
	uint32_t output5Power = ((uint32_t) m.out5VoltageValue) * m.out5CurrentValue;
	buffer += sprintf(buffer, "%-4s: %2u.%u [V], %u.%02u [A], %u.%u [W]\n", names[5], m.out5VoltageValue / 10, m.out5VoltageValue % 10, m.out5CurrentValue / 100, m.out5CurrentValue % 100, (uint16_t) output5Power / 1000, ((uint16_t) output5Power / 100) % 10);

	// amps consumed
	uint16_t ampHours = ampsConsumed / 3600;
	buffer += sprintf(buffer, "Amps consumed: %u.%02u [A/h]\n", ampHours / 100, ampHours % 100);

	// temperature
	buffer += sprintf(buffer, "  Temperature: %u [�C]\n", temp);

	// Time
	buffer += sprintf(buffer, "      Up time: %02uh:%02um:%02us\n", clock.hours, clock.minutes, clock.seconds);

	// Batt
	buffer += sprintf(buffer, "      Battery: %i%%\n", (((int16_t) m.inVoltageValue) - BATT_MIN) * 100 / (BATT_MAX - BATT_MIN));

	sprintf(buffer, "Sent %u bytes.\n", strlen(this->transmitBuffer) + 16);
	this->transmitDMA.start(strlen(this->transmitBuffer));
}
