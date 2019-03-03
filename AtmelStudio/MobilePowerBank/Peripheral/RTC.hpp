/*
 * RTC.h
 *
 * Created: 2018-10-04 12:57:17
 *  Author: Rodos
 */ 


#ifndef RTC_H_
#define RTC_H_

class Clock {

public:

	uint8_t days;
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;

	void init();
	void start();

	void countSecond();
	void reset();
};

#endif /* RTC_H_ */