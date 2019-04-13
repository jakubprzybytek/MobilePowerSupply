/*
 * DMA.cpp
 *
 * Created: 2019-01-09 19:34:14
 *  Author: Rodos
 */
#include <avr/io.h>

#include "DMA.h"

void DMAC::enable() {
	DMA.CTRL = DMA_ENABLE_bm;
}

void DMAC::init(void* sourceAddress, void* targetAddress, uint8_t TRIGSRC, uint8_t burstLen, uint8_t burstLenBm, uint16_t blockSize) {
	this->burstLen = burstLen;

	channel->CTRLA = DMA_CH_SINGLE_bm | burstLenBm; // Single transaction triggered by DMAC::start()
	channel->TRFCNT = burstLen * blockSize;
	channel->TRIGSRC = TRIGSRC;
	channel->SRCADDR0 = (register8_t)(uintptr_t)sourceAddress;
	channel->SRCADDR1 = (register8_t)((uintptr_t)sourceAddress >> 8);
	channel->SRCADDR2 = 0x00;
	channel->DESTADDR0 = (register8_t)(uintptr_t)targetAddress;
	channel->DESTADDR1 = (register8_t)((uintptr_t)targetAddress >> 8);
	channel->DESTADDR2 = 0x00;

	channel->CTRLB = DMA_CH_TRNINTLVL1_bm; // medium interrupt
}
// TODO: make it better
void DMAC::initSourceReloadOnBurstDestReloadOnTransaction() {
	channel->ADDRCTRL = DMA_CH_SRCRELOAD1_bm | DMA_CH_SRCDIR0_bm | DMA_CH_DESTRELOAD1_bm | DMA_CH_DESTRELOAD0_bm | DMA_CH_DESTDIR0_bm;
}

void DMAC::initSourceReloadOnTransactionDestReloadOnBurst() {
	channel->ADDRCTRL = DMA_CH_SRCRELOAD1_bm | DMA_CH_SRCRELOAD0_bm | DMA_CH_SRCDIR0_bm | DMA_CH_DESTRELOAD1_bm | DMA_CH_DESTDIR0_bm;
}

void DMAC::start() {
	channel->CTRLA |= DMA_CH_ENABLE_bm;
}

void DMAC::start(uint16_t blockSize) {
	channel->TRFCNT = burstLen * blockSize;
	start();
}
