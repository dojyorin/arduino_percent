#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between URL-unsafe string and URL-safe string.
* @see https://github.com/dojyorin/arduino_percent
*/
namespace PERCENT{
    /**
    * Convert URL-unsafe string to URL-safe string.
    * @param input URL-unsafe string.
    * @param output URL-safe string.
    */
    void encode(const char* input, char* output);

    /**
    * Calculate the number of output characters.
    * @param input URL-unsafe string.
    * @return Number of output characters.
    */
    size_t encodeLength(const char* input);

    /**
    * Convert URL-safe string to URL-unsafe string.
    * @param input URL-safe string.
    * @param output URL-unsafe string.
    */
    void decode(const char* input, char* output);

    /**
    * Calculate the number of output characters.
    * @param input URL-safe string.
    * @return Number of output characters.
    */
    size_t decodeLength(const char* input);
}