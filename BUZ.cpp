#include <Arduino.h>

#define BUZPin 18

void BUZInit(){
    pinMode(BUZPin, OUTPUT);
}
void BUZ_ON(int d){
    digitalWrite(BUZPin, HIGH);
    delay(d);
}
void BUZ_OFF(int d){
    digitalWrite(BUZPin, LOW);
    delay(d);
}
