#ifndef percent_hpp
#define percent_hpp

#include "inttypes.h"
#include "string.h"

namespace PERCENT{
    void encode(const char* input, char* output);
    size_t encodeLength(const char* input);
    void decode(const char* input, char* output);
    size_t decodeLength(const char* input);
}

#endif