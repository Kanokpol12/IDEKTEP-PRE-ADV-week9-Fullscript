#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


#define DHTPIN 23
#define DHTTYPE DHT22

long t,h;

DHT dht(DHTPIN, DHTTYPE);

void DHTZInit()
{
    dht.begin();
}

long DHTZReadTemp()
{
    t = dht.readTemperature();
    Serial.print("Temp :");
    Serial.println(t);

    if (isnan(t)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return 0;
    }
    return t;
}

long DHTZReadHumid()
{
    h = dht.readHumidity();
    Serial.print("Humi :");
    Serial.println(h);

    if (isnan(h)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return 0;
    }
    return h;
}


void DHTZAlarmCheck(int temp)
{
    
}
