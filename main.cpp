#include <Arduino.h>
#define LED_PIN 2

void LDRInit();
long ReadLDR();
void LDRAlarmCheck();

void BUZInit();
void BUZ_ON(int d);
void BUZ_OFF(int d);

void LcdInit();
void LcdDisplayLDR();
void LcdDisplayDHT();

void DHTZInit();
long DHTZReadTemp();
long DHTZReadHumid();
void DHTZAlarmCheck(int temp);


void setup() {
  pinMode(LED_PIN, OUTPUT);
  LDRInit();
  BUZInit();
  LcdInit();
  DHTZInit();

}
void loop() {
  
  LcdDisplayLDR();
  delay(500);
  LcdDisplayDHT();
  delay(500);
}

