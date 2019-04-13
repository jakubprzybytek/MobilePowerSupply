/*
 * MobilePowerBank.h
 *
 * Created: 2019-02-24 19:03:45
 *  Author: Chipotle
 */ 

#ifndef MOBILEPOWERBANK_H_
#define MOBILEPOWERBANK_H_

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define LED_INIT	PORTF.DIRSET = PIN2_bm; PORTF.OUTSET = PIN2_bm;
#define LED_SET		PORTF.OUTCLR = PIN2_bm;
#define LED_TOGGLE	PORTF.OUTTGL = PIN2_bm;

void drawStatusBar(bool firstDraw);
void resetStatus();

#endif /* MOBILEPOWERBANK_H_ */