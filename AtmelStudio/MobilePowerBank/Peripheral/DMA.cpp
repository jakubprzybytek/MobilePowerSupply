/*
 * DMA.cpp
 *
 * Created: 2019-01-09 19:34:14
 *  Author: Rodos
 */
#include <avr/io.h>
#include <stdlib.h>

#include "DMA.h"

void DMAC::init() {

	this->bufferA = (uint16_t*)malloc(sizeof(uint16_t) * 2 * avgLen);

	DMA.CTRL = DMA_ENABLE_bm;

	DMA.CH0.CTRLA = DMA_CH_SINGLE_bm | DMA_CH_BURSTLEN1_bm; // Single read, burst mode 2B
	DMA.CH0.TRFCNT = 16; // 16 bytes in block
	DMA.CH0.ADDRCTRL = DMA_CH_SRCRELOAD1_bm | DMA_CH_SRCDIR0_bm | DMA_CH_DESTRELOAD1_bm | DMA_CH_DESTRELOAD0_bm | DMA_CH_DESTDIR0_bm; // Reload source address on burst end, reload destination address on transaction end
	DMA.CH0.TRIGSRC = 0x11; // ADCA.CH0-3
	DMA.CH0.SRCADDR0 = (register8_t)(uintptr_t)&ADCA.CH0RES;
	DMA.CH0.SRCADDR1 = (register8_t)((uintptr_t)&ADCA.CH0RES >> 8);
	DMA.CH0.SRCADDR2 = 0x00;
	DMA.CH0.DESTADDR0 = (register8_t)(uintptr_t)bufferA;
	DMA.CH0.DESTADDR1 = (register8_t)((uintptr_t)bufferA >> 8);
	DMA.CH0.DESTADDR2 = 0x00;

	DMA.CH0.CTRLB = DMA_CH_TRNINTLVL1_bm; // medium interrupt
}

void DMAC::start() {
	DMA.CH0.CTRLA |= DMA_CH_ENABLE_bm;
}

void DMAC::readBlockByChannels(uint16_t* first, uint16_t* second) {
	uint32_t firstTemp = 0;
	uint32_t secondTemp = 0;

	for (uint8_t i = 0; i < this->avgLen * 2;) {
		firstTemp += this->bufferA[i++];
		secondTemp += this->bufferA[i++];
	}

	*first = firstTemp / this->avgLen;
	*second = secondTemp / this->avgLen;
}
