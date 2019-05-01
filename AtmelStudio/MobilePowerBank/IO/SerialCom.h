/* 
* SerialCom.h
*
* Created: 2019-04-12 19:11:25
* Author: Chipotle
*/


#ifndef __SERIALCOM_H__
#define __SERIALCOM_H__

#include <avr/io.h>

#include "../IO/Metter.h"

#include "../Peripheral/USART.h"
#include "../Peripheral/DMA.h"
#include "../Peripheral/RTC.hpp"

#define RECEIVE_BUFFER_SIZE 10
#define TRANSMIT_BUFFER_SIZE 600

class SerialCom {

private:
	USART usart;

	char receiveBuffer[RECEIVE_BUFFER_SIZE];
	uint16_t receiveBufferIndex;
	bool dataWaiting;

	DMAC transmitDMA;
	char transmitBuffer[sizeof(uint8_t) * TRANSMIT_BUFFER_SIZE];

public:
	SerialCom() : usart(&USARTC1, &PORTC, PIN7_bm), receiveBufferIndex(0), transmitDMA(&DMA.CH2) {}
	void init();

	bool processReceivedData(uint8_t data);
	char* getReceivedData();

	void sendMessage(const char* message);
	void sendHelp();
	void sendData(char names[6][5], Measurements& measurements, Clock& clock, uint32_t ampsConsumed, uint8_t temp);
}; //SerialCom

#endif //__SERIALCOM_H__
