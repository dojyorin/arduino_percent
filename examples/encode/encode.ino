#include "arduino_percent.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char input[] = "{<foo>'bar'}";
    char output[percent::encodeLength(input)];
    percent::encode(input, output);

    Serial.println(output);
}

void loop(){}