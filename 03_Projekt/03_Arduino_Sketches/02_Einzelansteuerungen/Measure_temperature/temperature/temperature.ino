/*
 MKR ENV Shield - Temperature Read Sensor
 */

#include <Arduino_MKRENV.h>

void setup() {
   Serial.begin(9600);
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
}

void loop() {
  
  // read all the sensor values
  
    float temperature = ENV.readTemperature();
  
  // print each of the sensor values
  
    Serial.print("Temperature = ");
    Serial.print(temperature);
  
   // print an empty line

    Serial.println();

  // wait 1 second to print again

    delay(1000);
}
