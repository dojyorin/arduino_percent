# **Arduino Percent**
![actions:test](https://github.com/dojyorin/arduino_percent/actions/workflows/test.yaml/badge.svg)
![actions:release](https://github.com/dojyorin/arduino_percent/actions/workflows/release.yaml/badge.svg)

Convert between URL-unsafe string and Percent encoded string.
Easily convert to Percent encoded string.

# Example
## Encode
```c++
const char data[] = "{<foo>'bar'}";
char result[percent::encodeLength(data)];

percent::encode(data, result);
```

## Decode
```c++
const char data[] = "%7B%3Cfoo%3E%27bar%27%7D";
char result[percent::decodeLength(data)];

percent::decode(data, result);
```

# Details
The only export of this library will be [`arduino_percent.hpp`](./src/arduino_percent.hpp).
Other source files are for internal use and should not normally be include.

# API
## `percent::encode(input, output)`
- Arguments
    - `input` : `const char*` ... URL-unsafe string.
    - `output` : `char*` ...  Percent encoded string.
- Result
    - `void`

## `percent::encodeLength(input)`
- Arguments
    - `input` : `const char*` ... URL-unsafe string.
- Result
    - `size_t` ... Number of output characters.

## `percent::decode(input, output)`
- Arguments
    - `input` : `const char*` ...  Percent encoded string.
    - `output` : `char*` ... URL-unsafe string.
- Result
    - `void`

## `percent::decodeLength(input)`
- Arguments
    - `input` : `const char*` ... Percent encoded string.
- Result
    - `size_t` ... Number of output characters.