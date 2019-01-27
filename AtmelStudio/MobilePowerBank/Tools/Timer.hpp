/*
 * Switch.hpp
 *
 * Created: 2017-06-28 22:01:06
 *  Author: Rodos
 */ 


#ifndef TIMER_H_
#define TIMER_H_

class Timer {

private:
	TC0_t* timer;
	uint16_t per;

public:
	Timer (TC0_t* timer, uint16_t per) : timer(timer), per(per) {}

	void Init(uint8_t intLevel);

	void Enable();
	void Disable();

};

#endif /* TIMER_H_ */