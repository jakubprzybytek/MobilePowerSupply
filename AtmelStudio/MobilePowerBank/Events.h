/* 
* Events.h
*
* Created: 2019-04-12 19:30:10
* Author: Chipotle
*/


#ifndef __EVENTS_H__
#define __EVENTS_H__

enum Event { NOP, USART_MESSAGE_RECEIVED };

class Events {

private:
	Event event;

public:
	Event getEvent();
	void setEvent(Event event);

}; //Events

#endif //__EVENTS_H__
