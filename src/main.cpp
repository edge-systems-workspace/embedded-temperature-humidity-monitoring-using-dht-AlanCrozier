/**
* @file DHT22_Read.ino
 * @brief Reads temperature and humidity data from a DHT22 sensor and prints it to Serial Monitor.
 *
 * This program initializes a DHT22 sensor connected to a digital pin
 * and continuously reads temperature and humidity values.
 * The values are displayed through the serial monitor every 2 seconds.
 *
 * @author Alan Crozier
 * @date 2026-02-20
 */

#include <Arduino.h>
#include <DHT.h>

/** @brief Digital pin connected to the DHT sensor */
#define DHTPIN 2

/** @brief Type of DHT sensor used (DHT22 / AM2302) */
#define DHTTYPE DHT22

/**
 * @brief Create DHT sensor object.
 *
 * Initializes the DHT sensor with the specified pin and sensor type.
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup function.
 *
 * Initializes serial communication and starts the DHT sensor.
 * This function runs once when the board is powered on or reset.
 */
void setup() {
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT22 init");
}

/**
 * @brief Arduino main loop function.
 *
 * Reads temperature and humidity from the DHT22 sensor.
 * If the sensor reading fails, an error message is printed.
 * Otherwise, temperature and humidity values are printed to the Serial Monitor.
 *
 * The loop runs continuously with a delay of 2 seconds between readings.
 */
void loop() {
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