#pragma once

void PERCENT::encode(const char* input, char* output);
size_t PERCENT::encodeLength(const char* input);
void PERCENT::decode(const char* input, char* output);
size_t PERCENT::decodeLength(const char* input);