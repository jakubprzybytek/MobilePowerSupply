/* 
* SerialCom.h
*
* Created: 2019-04-12 19:11:25
* Author: Chipotle
*/


#ifndef __SERIALCOM_H__
#define __SERIALCOM_H__

#include <avr/io.h>

#include "../Peripheral/USART.h"

#define RECEIVE_BUFFER_SIZE 10

class SerialCom {

private:
	USART usart;

	char receiveBuffer[RECEIVE_BUFFER_SIZE];
	uint16_t receiveBufferIndex;
	bool dataWaiting;

public:
	SerialCom() : usart(&USARTC1, &PORTC, PIN7_bm), receiveBufferIndex(0) {}
	void init();

	bool processReceivedData(uint8_t data);
	char* getReceivedData();

}; //SerialCom

#endif //__SERIALCOM_H__
