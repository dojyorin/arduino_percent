#include "../deps.h"
#include "./percent.hpp"

namespace{
    constexpr char numerics[] = "0123456789ABCDEF";
    constexpr char safes[] = "-._~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    uint8_t numericOf(char search){
        if('`' < search){
            search -= ' ';
        }

        for(uint8_t i = 0; i < 16; i++){
            if(numerics[i] == search){
                return i;
            }
        }

        return 255;
    }

    uint8_t isOk(char search){
        for(const auto &v: safes){
            if(v == search){
                return true;
            }
        }

        return false;
    }
}

namespace PERCENT{
    void encode(const char* input, char* output){
        while(*input != '\0'){
            if(isOk(*input)){
                *output++ = *input;
            }
            else{
                *output++ = '%';
                *output++ = numerics[*input >> 0x04];
                *output++ = numerics[*input & 0x0F];
            }

            input++;
        }

        *output = '\0';
    }

    size_t encodeLength(const char* input){
        size_t length = 0;

        while(*input != '\0'){
            length += isOk(*input++) ? 1 : 3;
        }

        return length + 1;
    }

    void decode(const char* input, char* output){
        while(*input != '\0'){
            if(*input == '%'){
                *output++ = (numericOf(*++input) << 4) + numericOf(*++input);
            }
            else{
                *output++ = *input;
            }

            input++;
        }

        *output = '\0';
    }

    size_t decodeLength(const char* input){
        size_t length = 0;

        while(*input != '\0'){
            input += *input == '%' ? 3 : 1;
            length++;
        }

        return length + 1;
    }
}