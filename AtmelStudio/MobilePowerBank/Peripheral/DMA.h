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
	DMA_CH_t* channel;
	uint8_t burstLen;

public:
	DMAC(DMA_CH_t* channel) : channel(channel) {};
	
	static void enable();

	void init(void* sourceAddress, void* targetAddress, uint8_t TRIGSRC, uint8_t burstLen, uint8_t burstLenBm, uint16_t blockSize);
	void initSourceReloadOnBurstDestReloadOnTransaction();
	void initSourceReloadOnTransactionDestReloadOnBurst();

	void start();
	void start(uint16_t blockSize);
};

#endif /* DMA_H_ */