/*
 * AC.h
 *
 * Created: 2019-03-02 18:11:44
 *  Author: Chipotle
 */ 


#ifndef AC_H_
#define AC_H_

#include <avr/io.h>

class AC {

private:
	AC_t* ac;

public:
	AC (AC_t* ac) : ac(ac) {}

	void init();

	void start();	
};

#endif /* AC_H_ */