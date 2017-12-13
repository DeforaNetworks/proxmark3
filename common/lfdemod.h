// Copyright (C) 2014
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// Low frequency demod related commands
// marshmellow
// note that many of these demods are not the slickest code and they often rely
//   on peaks and clock instead of converting to clean signal. 
//   
//-----------------------------------------------------------------------------

#ifndef LFDEMOD_H__
#define LFDEMOD_H__
#include <stdint.h>  // for uint_32+
#include <stdbool.h> // for bool

//generic
size_t   addParity(uint8_t *BitSource, uint8_t *dest, uint8_t sourceLen, uint8_t pLen, uint8_t pType);
int      askdemod(uint8_t *BinStream, size_t *size, int *clk, int *invert, int maxErr, uint8_t amp, uint8_t askType);
int      askdemod_ext(uint8_t *BinStream, size_t *size, int *clk, int *invert, int maxErr, uint8_t amp, uint8_t askType, int *startIdx);
void     askAmp(uint8_t *BitStream, size_t size);
int      BiphaseRawDecode(uint8_t * BitStream, size_t *size, int *offset, int invert);
uint32_t bytebits_to_byte(uint8_t* src, size_t numbits);
uint32_t bytebits_to_byteLSBF(uint8_t* src, size_t numbits);
uint16_t countFC(uint8_t *BitStream, size_t size, uint8_t fskAdj);
int      DetectASKClock(uint8_t dest[], size_t size, int *clock, int maxErr);
uint8_t  DetectCleanAskWave(uint8_t dest[], size_t size, uint8_t high, uint8_t low);
uint8_t  detectFSKClk(uint8_t *BitStream, size_t size, uint8_t fcHigh, uint8_t fcLow, int *firstClockEdge);
int      DetectNRZClock(uint8_t dest[], size_t size, int clock, size_t *clockStartIdx);
int      DetectPSKClock(uint8_t dest[], size_t size, int clock, size_t *firstPhaseShift, uint8_t *curPhase, uint8_t *fc);
int      DetectStrongAskClock(uint8_t dest[], size_t size, int high, int low, int *clock);
bool     DetectST(uint8_t buffer[], size_t *size, int *foundclock, size_t *ststart, size_t *stend);
int      fskdemod(uint8_t *dest, size_t size, uint8_t rfLen, uint8_t invert, uint8_t fchigh, uint8_t fclow, int *startIdx);
int      getHiLo(uint8_t *BitStream, size_t size, int *high, int *low, uint8_t fuzzHi, uint8_t fuzzLo);
uint32_t manchesterEncode2Bytes(uint16_t datain);
int      ManchesterEncode(uint8_t *BitStream, size_t size);
int      manrawdecode(uint8_t *BitStream, size_t *size, uint8_t invert, uint8_t *alignPos);
int      nrzRawDemod(uint8_t *dest, size_t *size, int *clk, int *invert, int *startIdx);
bool     parityTest(uint32_t bits, uint8_t bitLen, uint8_t pType);
uint8_t  preambleSearch(uint8_t *BitStream, uint8_t *preamble, size_t pLen, size_t *size, size_t *startIdx);
bool     preambleSearchEx(uint8_t *BitStream, uint8_t *preamble, size_t pLen, size_t *size, size_t *startIdx, bool findone);
int      pskRawDemod(uint8_t dest[], size_t *size, int *clock, int *invert);
int      pskRawDemod_ext(uint8_t dest[], size_t *size, int *clock, int *invert, int *startIdx);
void     psk2TOpsk1(uint8_t *BitStream, size_t size);
void     psk1TOpsk2(uint8_t *BitStream, size_t size);
size_t   removeParity(uint8_t *BitStream, size_t startIdx, uint8_t pLen, uint8_t pType, size_t bLen);

//tag specific
int AWIDdemodFSK(uint8_t *dest, size_t *size, int *waveStartIdx);
uint8_t Em410xDecode(uint8_t *BitStream, size_t *size, size_t *startIdx, uint32_t *hi, uint64_t *lo);
int FDXBdemodBI(uint8_t *dest, size_t *size);
int gProxII_Demod(uint8_t BitStream[], size_t *size);
int HIDdemodFSK(uint8_t *dest, size_t *size, uint32_t *hi2, uint32_t *hi, uint32_t *lo, int *waveStartIdx);
int IOdemodFSK(uint8_t *dest, size_t size, int *waveStartIdx);
int indala64decode(uint8_t *bitStream, size_t *size, uint8_t *invert);
int indala224decode(uint8_t *bitStream, size_t *size, uint8_t *invert);
int ParadoxdemodFSK(uint8_t *dest, size_t *size, uint32_t *hi2, uint32_t *hi, uint32_t *lo, int *waveStartIdx);
int PrescoDemod(uint8_t *dest, size_t *size);
int PyramiddemodFSK(uint8_t *dest, size_t *size, int *waveStartIdx);
int VikingDemod_AM(uint8_t *dest, size_t *size);
int Visa2kDemod_AM(uint8_t *dest, size_t *size);

#endif
