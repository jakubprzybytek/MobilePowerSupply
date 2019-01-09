/*
 * DMA.h
 *
 * Created: 2019-01-09 19:33:43
 *  Author: Rodos
 */ 


#ifndef DMA_H_
#define DMA_H_

class DMAC {

private:
	uint8_t avgLen;
	uint16_t* bufferA;

public:
	DMAC(uint8_t avgLen) : avgLen(avgLen) {};
	void init();

	void start();

	void readBlockByChannels(uint16_t* first, uint16_t* second);
};

#endif /* DMA_H_ */