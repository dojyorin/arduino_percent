#include "Percent.h"

namespace{
    const char headerTable[16] = {
        0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66
    };

    const bool safeTable[128] = {
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false,
        true, true, true, true, true, true, true, true, true, true, false, false, false, false, false, false,
        false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false,
        false, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true,
        true, true, true, true, true, true, true, true, true, true, true, false, false, false, false, false
    };

    const uint8_t alphaTable[128] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
    };
}

void PERCENT::encode(const char* input, char* output){
    while(*input != '\0'){
        if(safeTable[*input]){
            *output++ = *input;
        }
        else{
            *output++ = '%';
            *output++ = headerTable[*input >> 0x04];
            *output++ = headerTable[*input & 0x0F];
        }
        input++;
    }
    *output = '\0';
}

size_t PERCENT::encodeLength(const char* input){
    size_t length = 0;

    while(*input != '\0'){
        length += safeTable[*input++] ? 1 : 3;
    }

    return length + 1;
}

void PERCENT::decode(const char* input, char* output){
    while(*input != '\0'){
        if(*input == '%'){
            *output++ = (alphaTable[*++input] << 4) + alphaTable[*++input];
        }
        else{
            *output++ = *input;
        }
        input++;
    }
    *output = '\0';
}

size_t PERCENT::decodeLength(const char* input){
    size_t length = 0;

    while(*input != '\0'){
        input += (*input == '%') ? 3 : 1;
        length++;
    }

    return length + 1;
}