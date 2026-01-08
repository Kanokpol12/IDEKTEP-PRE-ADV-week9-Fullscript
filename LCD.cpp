#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

String LCDText0 = "IDEKTEP";
String LCDText1 = "Robot Expoler";


LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 or 0x3F

long ReadLDR();

long DHTZReadTemp();
long DHTZReadHumid();

void LcdInit()
{
    lcd.init();
    lcd.display();
    lcd.backlight();
    lcd.clear();
    lcd.noBacklight();
    lcd.backlight();
    
}

void LcdShowLight()
{
    lcd.backlight();
}

void LcdNoLight()
{
    lcd.noBacklight();
}
void LcdDisplayLDR()
{
    int L = ReadLDR();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LDR = " + String(L));
    
}

void LcdDisplay()
{
        lcd.clear();      
        lcd.setCursor(0, 0);
        lcd.print(LCDText0);
        lcd.setCursor(0, 1);
        lcd.print(LCDText1);
}

void LcdDisplayDHT()
{
    int T = DHTZReadTemp();
    int H = DHTZReadHumid();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TEMP = " + String(T) + "C");
    lcd.setCursor(0,1);
    lcd.print("HUMI = " + String(H) + "%");


}
