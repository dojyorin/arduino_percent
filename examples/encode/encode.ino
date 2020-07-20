#include "Arduino.h"
#include "Percent.h"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char* raw = "{<foo>'bar'}";

    char encoded[PERCENT::encodeLength(raw)];
    PERCENT::encode(raw, encoded);

    Serial.println(encoded);
}

void loop(){}