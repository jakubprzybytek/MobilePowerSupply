/* 
* Events.cpp
*
* Created: 2019-04-12 19:30:10
* Author: Chipotle
*/
#include <avr/io.h>

#include "Events.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b))

void Events::submit(Event event) {
	if (this->eventsListIndex == MAX_EVENTS) {
		return;
	}

	this->eventsList[this->eventsListIndex++] = event;
	this->maxEventsListIndex = MAX(this->maxEventsListIndex, this->eventsListIndex);
}

Event Events::get() {
	if (this->eventsListIndex == 0) {
		return NOP;
	}

	return this->eventsList[--this->eventsListIndex];
}
