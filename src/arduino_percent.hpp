#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between URL-unsafe string and Percent encoded string.
* @see https://github.com/dojyorin/arduino_percent
*/
namespace percent{
    /**
    * Convert URL-unsafe string to Percent encoded string.
    * @param input URL-unsafe string.
    * @param output Percent encoded string.
    */
    void encode(const char* input, char* output);

    /**
    * Calculate the number of output characters.
    * @param input URL-unsafe string.
    * @return Number of output characters.
    */
    size_t encodeLength(const char* input);

    /**
    * Convert Percent encoded string to URL-unsafe string.
    * @param input Percent encoded string.
    * @param output URL-unsafe string.
    */
    void decode(const char* input, char* output);

    /**
    * Calculate the number of output characters.
    * @param input Percent encoded string.
    * @return Number of output characters.
    */
    size_t decodeLength(const char* input);
}