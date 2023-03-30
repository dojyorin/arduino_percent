#include "arduino_percent.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char data[] = "{<foo>'bar'}";
    char result[PERCENT::encodeLength(data)];

    PERCENT::encode(data, result);

    Serial.println(result);
}

void loop(){}