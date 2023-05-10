#include "arduino_percent.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char data[] = "{<foo>'bar'}";
    char result[percent::encodeLength(data)];

    percent::encode(data, result);

    Serial.println(result);
}

void loop(){}