#include "./arduino_percent.hpp"

namespace
{

constexpr char hex[] = "0123456789ABCDEF";
constexpr char unreserved[] = "-._~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

uint8_t hexOf(char search){
    if('`' < search){
        search -= ' ';
    }

    for(uint8_t i = 0; i < 16; i++){
        if(hex[i] == search){
            return i;
        }
    }

    return 255;
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

void PERCENT::encode(const char* input, char* output){
    while(*input != '\0'){
        if(isUnreserved(*input)){
            *output++ = *input;
        }
        else{
            *output++ = '%';
            *output++ = hex[*input >> 0x04];
            *output++ = hex[*input & 0x0F];
        }

        input++;
    }

    *output = '\0';
}

size_t PERCENT::encodeLength(const char* input){
    size_t length = 0;

    while(*input != '\0'){
        length += isUnreserved(*input++) ? 1 : 3;
    }

    return length + 1;
}

void PERCENT::decode(const char* input, char* output){
    while(*input != '\0'){
        if(*input == '%'){
            *output++ = (hexOf(*++input) << 4) + hexOf(*++input);
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
        input += *input == '%' ? 3 : 1;
        length++;
    }

    return length + 1;
}