#pragma once

#include "stdint.h"
#include "string.h"

/**
* Convert between URL-unsafe string and percent encoded string.
* @see https://github.com/dojyorin/arduino_percent
*/
namespace percent{
    /**
    * Convert URL-unsafe string to percent encoded string.
    * @example
    * ```c++
    * const char input[] = "{<foo>'bar'}";
    * char output[percent::encodeLength(input)];
    * percent::encode(input, output);
    * ```
    */
    void encode(const char* input, char* output);

    /**
    * Calculate number of output characters.
    * @example
    * ```c++
    * const char input[] = "{<foo>'bar'}";
    * char output[percent::encodeLength(input)];
    * percent::encode(input, output);
    * ```
    */
    size_t encodeLength(const char* input);

    /**
    * Convert percent encoded string to URL-unsafe string.
    * @example
    * ```c++
    * const char input[] = "%7B%3Cfoo%3E%27bar%27%7D";
    * char output[percent::decodeLength(input)];
    * percent::decode(input, output);
    * ```
    */
    void decode(const char* input, char* output);

    /**
    * Calculate number of output characters.
    * @example
    * ```c++
    * const char input[] = "%7B%3Cfoo%3E%27bar%27%7D";
    * char output[percent::decodeLength(input)];
    * percent::decode(input, output);
    * ```
    */
    size_t decodeLength(const char* input);
}