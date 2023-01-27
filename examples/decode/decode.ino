#include "Arduino.h"
#include "mod.percent.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char data[] = "%7B%3Cfoo%3E%27bar%27%7D";
    char result[PERCENT::decodeLength(data)];

    PERCENT::decode(data, result);

    Serial.println(result);
}

void loop(){}