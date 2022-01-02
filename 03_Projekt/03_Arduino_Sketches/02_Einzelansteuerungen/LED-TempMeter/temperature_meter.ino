#include <Arduino_MKRENV.h>
#include <SPI.h>

int 


// variables
float temperature = 0;

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
  
  if ( temperature >= 27){
    digitalWrite(ledgr, HIGH);
   }
  else if ( temperature <=27){
    digitalWrite(ledge, HIGH);
  }
  else { ( temperature <=30)
    digitalWrite(ledre, HIGH);
  }
}
