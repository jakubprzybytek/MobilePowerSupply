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

public:
	DMAC(DMA_CH_t* channel) : channel(channel) {};
	
	static void enable();

	void init(register16_t* sourceAddress, void* targetAddress, uint8_t TRIGSRC, uint8_t burstLen, uint8_t burstLenBm, uint16_t blockSize);
	void initSourceReloadOnBurstDestReloadOnTransaction();
	void initSourceReloadOnTransactionDestReloadOnBurst();

	void start();
};

#endif /* DMA_H_ */