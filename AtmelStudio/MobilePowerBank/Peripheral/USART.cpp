/* 
* USART.cpp
*
* Created: 2019-04-12 19:06:07
* Author: Chipotle
*/

#include "USART.h"

void USART::init() {
	port->DIRSET = txdPinBm;

	usart->BAUDCTRLB = 0; // BSCALE = 0
	usart->BAUDCTRLA = 12; // BSEL = 12 for 9600
	usart->CTRLC = USART_CHSIZE_8BIT_gc;
	usart->CTRLB = USART_TXEN_bm | USART_RXEN_bm;
	usart->CTRLA = USART_RXCINTLVL_LO_gc;
}
