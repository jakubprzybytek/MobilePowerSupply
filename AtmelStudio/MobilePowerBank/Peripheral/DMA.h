/*
 * DMA.h
 *
 * Created: 2019-01-09 19:33:43
 *  Author: Rodos
 */ 

#ifndef DMA_H_
#define DMA_H_

#define CHANNELS 2

class DMAC {

private:
	DMA_CH_t* channel;
	uint16_t avgLen;

	uint16_t* readsBuffer;

public:
	DMAC(DMA_CH_t* channel) : channel(channel) {};
	
	static void enable();

	void init(register16_t* adcResAddress, uint16_t avgLen);

	void start();

	void readBlockByChannels(uint16_t* first, uint16_t* second);
};

#endif /* DMA_H_ */