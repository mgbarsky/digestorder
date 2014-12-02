#ifndef BITPREFIX_H
#define BITPREFIX_H

#include "Utils.h"

class BitPrefix //
{

public:
    static uint32 masks_array32[32];
    static unsigned char masks_array8 [8];
    static void setCharacterAtPos (char c, int pos, uint32 *bitArray);
    static void setSuffixLength (int length, uint32 *bitArray);
    static void setPrefix (unsigned char *seq, int suffixLength, unsigned char *prefix);
    static void printBitPrefix (unsigned char *prefix);

private:
    const static uint32 MAX_UINT = ~0;
    
    const static uint32 REMOVE_SUFFIX_LENGTH_MASK = (uint32) (MAX_UINT << 24);
    static short getBitInChar (unsigned char *bitSeq, int pos);
} ;


#endif
