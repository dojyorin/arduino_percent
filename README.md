# Arduino Percent Codec
Simple Percent Codec for Arduino.


# API
## `void PERCENT::encode(const char* input, char* output)`
**Arguments**
- `input`: Raw string.
- `output`: Percent encoded string.

**Return**
- Nothing.


## `size_t PERCENT::encodeLength(const char* input)`
**Arguments**
- `input`: Raw string.

**Return**
- Number of characters after percent encoding.


## `void PERCENT::decode(const char* input, char* output)`
**Arguments**
- `input`: Percent encoded string.
- `output`: Raw string.

**Return**
- Nothing.


## `size_t PERCENT::decodeLength(const char* input)`
**Arguments**
- `input`: Percent encoded string.

**Return**
- Number of characters after percent decoding.


# Disclaimer
According to MIT License.