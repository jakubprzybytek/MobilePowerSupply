/* 
* SerialCom.cpp
*
* Created: 2019-04-12 19:11:25
* Author: Chipotle
*/


#include "SerialCom.h"

void SerialCom::init() {
	usart.init();
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