/*
 * DMA.cpp
 *
 * Created: 2019-01-09 19:34:14
 *  Author: Rodos
 */
#include <avr/io.h>
#include <stdlib.h>

#include "DMA.h"

void DMAC::enable() {
	DMA.CTRL = DMA_ENABLE_bm;
}

void DMAC::init(register16_t* adcResAddress, uint16_t avgLen) {
	this->avgLen = avgLen;
	this->readsBuffer = (uint16_t*)malloc(sizeof(uint16_t) * CHANNELS * avgLen);

	channel->CTRLA = DMA_CH_SINGLE_bm | DMA_CH_BURSTLEN1_bm; // Single read, burst mode 2B
	channel->TRFCNT = sizeof(uint16_t) * CHANNELS * avgLen; // 16 bytes in block
	channel->ADDRCTRL = DMA_CH_SRCRELOAD1_bm | DMA_CH_SRCDIR0_bm | DMA_CH_DESTRELOAD1_bm | DMA_CH_DESTRELOAD0_bm | DMA_CH_DESTDIR0_bm; // Reload source address on burst end, reload destination address on transaction end
	channel->TRIGSRC = 0x11; // ADCA.CH0-3
	channel->SRCADDR0 = (register8_t)(uintptr_t)adcResAddress;
	channel->SRCADDR1 = (register8_t)((uintptr_t)adcResAddress >> 8);
	channel->SRCADDR2 = 0x00;
	channel->DESTADDR0 = (register8_t)(uintptr_t)readsBuffer;
	channel->DESTADDR1 = (register8_t)((uintptr_t)readsBuffer >> 8);
	channel->DESTADDR2 = 0x00;

	channel->CTRLB = DMA_CH_TRNINTLVL1_bm; // medium interrupt
}

void DMAC::start() {
	channel->CTRLA |= DMA_CH_ENABLE_bm;
}

void DMAC::readBlockByChannels(uint16_t* first, uint16_t* second) {
	uint32_t firstTemp = 0;
	uint32_t secondTemp = 0;

	for (uint16_t i = 0; i < this->avgLen * CHANNELS;) {
		firstTemp += this->readsBuffer[i++];
		secondTemp += this->readsBuffer[i++];
	}

	*first = firstTemp / this->avgLen;
	*second = secondTemp / this->avgLen;
}
