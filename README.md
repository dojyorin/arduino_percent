# **Arduino PERCENT Codec**
Simple PERCENT Codec for Arduino.

# Example
## Encode
```c++
const char* raw = "{<foo>'bar'}";

char encoded[PERCENT::encodeLength(raw)];
PERCENT::encode(raw, encoded);

Serial.println(encoded);
```

## Decode
```c++
const char* encoded = "%7B%3Cfoo%3E%27bar%27%7D";

char raw[PERCENT::decodeLength(encoded)];
PERCENT::decode(encoded, raw);

Serial.println(raw);
```

# API
## void PERCENT::encode(const char* input, char* output)
**Arguments**
- `input`: Raw string.
- `output`: PERCENT encoded string.

**Return**
- Nothing.

## size_t PERCENT::encodeLength(const char* input)
**Arguments**
- `input`: Raw string.

**Return**
- Number of characters after percent encoding.

## void PERCENT::decode(const char* input, char* output)
**Arguments**
- `input`: PERCENT encoded string.
- `output`: Raw string.

**Return**
- Nothing.

## size_t PERCENT::decodeLength(const char* input)
**Arguments**
- `input`: PERCENT encoded string.

**Return**
- Number of characters after percent decoding.

# Disclaimer
According to MIT License.