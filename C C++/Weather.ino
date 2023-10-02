#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2  // Pin where the DHT22 sensor is connected (you can change this)
#define DHTTYPE DHT22  // DHT22 (AM2302) sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Wait for 2 seconds between measurements

  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity(); // Read humidity

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature and humidity values on the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // You can add more sensors and display more data here if needed

  delay(5000);  // Wait for 5 seconds before the next reading
}
