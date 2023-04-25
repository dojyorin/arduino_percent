# **Arduino PERCENT**
![actions:test](https://github.com/dojyorin/arduino_percent/actions/workflows/test.yaml/badge.svg)
![actions:release](https://github.com/dojyorin/arduino_percent/actions/workflows/release.yaml/badge.svg)

Convert between URL-unsafe string and URL-safe string.
Easily convert to URL-safe string.

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

# Details
The only export of this library will be [`arduino_percent.hpp`](./src/arduino_percent.hpp).
Other source files are for internal use and should not normally be include.

# API
## `PERCENT::encode(input, output)`
- Arguments
    - `input` : `const char*` ... URL-unsafe string.
    - `output` : `char*` ...  URL-safe string.
- Result
    - `void`

## `PERCENT::encodeLength(input)`
- Arguments
    - `input` : `const char*` ... URL-unsafe string.
- Result
    - `size_t` ... Number of output characters.

## `PERCENT::decode(input, output)`
- Arguments
    - `input` : `const char*` ...  URL-safe string.
    - `output` : `char*` ... URL-unsafe string.
- Result
    - `void`

## `PERCENT::decodeLength(input)`
- Arguments
    - `input` : `const char*` ... URL-safe string.
- Result
    - `size_t` ... Number of output characters.