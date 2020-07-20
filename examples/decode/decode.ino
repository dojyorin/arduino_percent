#include "Arduino.h"
#include "Percent.h"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* encoded = "%7B%3Cfoo%3E%27bar%27%7D";

    uint8_t raw[PERCENT::decodeLength(encoded)];
    PERCENT::decode(encoded, raw);

    Serial.println(raw);
}

void loop(){}