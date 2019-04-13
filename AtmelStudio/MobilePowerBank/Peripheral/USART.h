/* 
* USART.h
*
* Created: 2019-04-12 19:06:07
* Author: Chipotle
*/

#ifndef __USART_H__
#define __USART_H__

#include <avr/io.h>

class USART {

public:
	USART_t* usart;

private:
	PORT_t* port;
	uint8_t txdPinBm;

public:
	USART(USART_t* usart, PORT_t* port, uint8_t txdPinBm) : usart(usart), port(port), txdPinBm(txdPinBm) {}
	void init();

}; //USART

#endif //__USART_H__
