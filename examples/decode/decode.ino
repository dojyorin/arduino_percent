#include "arduino_percent.hpp"

void setup(){
    Serial.begin(115200);
    while(!Serial);

    const char input[] = "%7B%3Cfoo%3E%27bar%27%7D";
    char output[percent::decodeLength(input)];
    percent::decode(input, output);

    Serial.println(output);
}

void loop(){}