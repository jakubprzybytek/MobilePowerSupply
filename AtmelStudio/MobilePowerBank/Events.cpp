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

	uint8_t pullFromIndex = 0;
	for (uint8_t i = 0; i < this->eventsListIndex; i++) {
		if (this->eventsList[i] == ADC_DMA_A_FINISHED || this->eventsList[i] == ADC_DMA_B_FINISHED) {
			pullFromIndex = i;
		}
	}

	Event toReturn = this->eventsList[pullFromIndex];
	for (uint8_t j = pullFromIndex + 1; j < this->eventsListIndex; j++) {
		this->eventsList[j - 1] = this->eventsList[j];
	}
	this->eventsListIndex--;
	return toReturn;
}
