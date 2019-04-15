/* 
* Events.h
*
* Created: 2019-04-12 19:30:10
* Author: Chipotle
*/


#ifndef __EVENTS_H__
#define __EVENTS_H__

enum Event { NOP, 
	USART_MESSAGE_RECEIVED, 
	ADC_DMA_A_FINISHED, ADC_DMA_B_FINISHED, 
	RTC_SECOND_PASSED, 
	REFRESH_DISPLAY, 
	BUTTON_PRESSED, BUTTON_CHECK };

#define MAX_EVENTS 10

class Events {

public:
	uint16_t maxEventsListIndex;

private:
	Event eventsList[MAX_EVENTS];
	uint8_t eventsListIndex;

public:
	void submit(Event event);
	Event get();

}; //Events

#endif //__EVENTS_H__
