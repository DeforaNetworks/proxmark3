// Merlok, 2011, 2017
// people from mifare@nethemba.com, 2010
//
// This code is licensed to you under the terms of the GNU GPL, version 2 or,
// at your option, any later version. See the LICENSE.txt file for the text of
// the license.
//-----------------------------------------------------------------------------
// High frequency ISO14443A commands
//-----------------------------------------------------------------------------

#ifndef MIFAREHOST_H
#define MIFAREHOST_H

#include <stdint.h>
#include <stdbool.h>
#include "data.h"

// defaults
// timeout in units. (ms * 106)/10 or us*0.0106
// 5 == 500us
#define MF_CHKKEYS_DEFTIMEOUT		5

// mfCSetBlock work flags
#define CSETBLOCK_UID 				0x01
#define CSETBLOCK_WUPC				0x02
#define CSETBLOCK_HALT				0x04
#define CSETBLOCK_INIT_FIELD			0x08
#define CSETBLOCK_RESET_FIELD			0x10
#define CSETBLOCK_SINGLE_OPER			0x1F
#define CSETBLOCK_MAGIC_1B 			0x40

typedef struct {
	uint64_t Key[2];
	int foundKey[2];
} sector_t;

char logHexFileName[FILE_PATH_SIZE];

int mfDarkside(uint64_t *key);
int mfnested(uint8_t blockNo, uint8_t keyType, uint8_t *key, uint8_t trgBlockNo, uint8_t trgKeyType, uint8_t *ResultKeys, bool calibrate);
int mfCheckKeys (uint8_t blockNo, uint8_t keyType, bool clear_trace, uint8_t keycnt, uint8_t *keyBlock, uint64_t *key);
int mfCheckKeysSec(uint8_t sectorCnt, uint8_t keyType, uint8_t timeout14a, bool clear_trace, uint8_t keycnt, uint8_t * keyBlock, sector_t * e_sector);

int mfEmlGetMem(uint8_t *data, int blockNum, int blocksCount);
int mfEmlSetMem(uint8_t *data, int blockNum, int blocksCount);

int mfCWipe(uint32_t numSectors, bool gen1b, bool wantWipe, bool wantFill);
int mfCSetUID(uint8_t *uid, uint8_t *atqa, uint8_t *sak, uint8_t *oldUID);
int mfCSetBlock(uint8_t blockNo, uint8_t *data, uint8_t *uid, bool wantWipe, uint8_t params);
int mfCGetBlock(uint8_t blockNo, uint8_t *data, uint8_t params);

int mfTraceInit(uint8_t *tuid, uint8_t *atqa, uint8_t sak, bool wantSaveToEmlFile);
int mfTraceDecode(uint8_t *data_src, int len, bool wantSaveToEmlFile);

int isTraceCardEmpty(void);
int isBlockEmpty(int blockN);
int isBlockTrailer(int blockN);
int loadTraceCard(uint8_t *tuid);
int saveTraceCard(void);
int tryDecryptWord(uint32_t nt, uint32_t ar_enc, uint32_t at_enc, uint8_t *data, int len);

int mfCIdentify();
int DetectClassicPrng(void);

#endif
