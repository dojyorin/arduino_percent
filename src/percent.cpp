#include "./arduino_percent.hpp"

namespace{
    constexpr char symbols[] = "0123456789ABCDEF";
    constexpr char unreserved[] = "-._~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    uint8_t indexOf(char search){
        if('`' < search){
            search -= ' ';
        }

        for(uint8_t i = 0; i < 16; i++){
            if(symbols[i] == search){
                return i;
            }
        }

        return 0xFF;
    }

    bool isUnreserved(char search){
        for(const auto &v: unreserved){
            if(v == search){
                return true;
            }
        }

        return false;
    }
}

void percent::encode(const char* input, char* output){
    while(*input != '\0'){
        if(isUnreserved(*input)){
            *output++ = *input;
        }
        else{
            *output++ = '%';
            *output++ = symbols[*input >> 0x04];
            *output++ = symbols[*input & 0x0F];
        }

        input++;
    }

    *output = '\0';
}

size_t percent::encodeLength(const char* input){
    size_t length = 0;

    while(*input != '\0'){
        length += isUnreserved(*input++) ? 1 : 3;
    }

    return length + 1;
}

void percent::decode(const char* input, char* output){
    while(*input != '\0'){
        if(*input == '%'){
            *output++ = (indexOf(*++input) << 4) + indexOf(*++input);
        }
        else{
            *output++ = *input;
        }

        input++;
    }

    *output = '\0';
}

size_t percent::decodeLength(const char* input){
    size_t length = 0;

    while(*input != '\0'){
        input += *input == '%' ? 3 : 1;
        length++;
    }

    return length + 1;
}