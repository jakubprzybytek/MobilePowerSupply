/*
 * Switch.hpp
 *
 * Created: 2017-06-28 22:01:06
 *  Author: Rodos
 */ 


#ifndef SWITCH_H_
#define SWITCH_H_

class InterruptSwitch {

private:
	PORT_t* port;
	uint8_t pin;
	register8_t* portCtrl;

public:
	InterruptSwitch (PORT_t* port, uint8_t pin, register8_t* portCtrl) : port(port), pin(pin), portCtrl(portCtrl) {}

	void init();

	void enableInterrupt();
	void disableInterrupt();

	bool isUp();

};

#endif /* SWITCH_H_ */