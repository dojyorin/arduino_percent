# **Arduino PERCENT Codec**
Simple PERCENT Codec for Arduino.

# Example
## Encode
```c++
const char data[] = "{<foo>'bar'}";
char result[PERCENT::encodeLength(data)];

PERCENT::encode(data, result);
```

## Decode
```c++
const char data[] = "%7B%3Cfoo%3E%27bar%27%7D";
char result[PERCENT::decodeLength(data)];

PERCENT::decode(data, result);
```

# API
## `PERCENT::encode()`
- Arguments
    - `input` : `const char*` ... URL unsafe string.
    - `output` : `char*` ...  URL safe PERCENT encoded string.
- Result
    - `void`

## `PERCENT::encodeLength()`
- Arguments
    - `input` : `const char*` ... URL unsafe string.
- Result
    - `size_t` ... Number of characters after percent encoding.

## `PERCENT::decode()`
- Arguments
    - `input` : `const char*` ...  URL safe PERCENT encoded string.
    - `output` : `char*` ... URL unsafe string.
- Result
    - `void`

## `PERCENT::decodeLength()`
- Arguments
    - `input` : `const char*` ... URL safe PERCENT encoded string.
- Result
    - `size_t` ... Number of characters after percent decoding.

# Disclaimer
According to MIT License.