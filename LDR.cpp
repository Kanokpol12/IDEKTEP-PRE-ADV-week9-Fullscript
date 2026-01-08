#include <Arduino.h>
#define LDRPin 34
#define ALARM_LIMIT 300 // ตัวอย่าง: ถ้าค่าแสงเกิน 300 ให้แจ้งเตือน

int val, ldr_value = 0;

void LDRAlarmCheck();

void LDRInit()
{
    pinMode(LDRPin, INPUT); 
    Serial.begin(115200); 
}

long ReadLDR()
{
    val = analogRead(LDRPin);
    ldr_value = map(val, 0, 4095, 0, 400); 
    Serial.print("LDR Value: ");
    Serial.print(ldr_value);

    LDRAlarmCheck();
    
    Serial.println(); // ขึ้นบรรทัดใหม่
    delay(500); // หน่วงเวลา 0.5 วินาที
    return ldr_value;
}

void LDRAlarmCheck()
{
    if (ldr_value >= ALARM_LIMIT) 
    {
        Serial.print(" [ALARM: HIGH!]");
    }
    else 
    {
        Serial.print(" [Normal]");
    }
}
