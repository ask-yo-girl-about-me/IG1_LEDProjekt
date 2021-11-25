#include <Arduino_MKRENV.h>
#include <SPI.h>

// variables
float temperature = 0;
float Tempbereich_G = 24;


void setup() {
  Serial.begin(9600);

  // init the ENV Shield
  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }

  // init SPI
  SPI.begin();
  delay(100);
}

void loop() {

  Serial.print("Temperature = ");
  Serial.print(temperature);
  
  // read the sensors values
  temperature = ENV.readTemperature();
  

if (temperature == Tempbereich_G); {
    pinMode(0, OUTPUT);
    digitalWrite(0, HIGH);
    delay (1000);
}

}
