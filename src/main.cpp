#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22 (AM2302)


DHT dht(DHTPIN, DHTTYPE);
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT22 init");
}

void loop() {
    // write your code here
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    if (isnan(temp) || isnan(hum)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.print(" °C ");
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.println(" %");
    delay(2000);
}