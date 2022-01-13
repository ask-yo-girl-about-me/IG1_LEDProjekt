#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

// file object
File dataFile;

// chip select for SD card
const int SD_CS_PIN = 4;  

// DBMeter ////////////////////////////////////////////////////
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time

// Temperatur
float temperature = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
    
  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }

  // init SPI
  SPI.begin();
  
  // init SD card
  if(!SD.begin(SD_CS_PIN)) {
    Serial.println("Failed to initialize SD card!");
    while (1);
  }
  
  // init the logfile for Temperature Values
  dataFile = SD.open("logDB-0000.csv", FILE_WRITE);
  delay(1000);
  // init the CSV file with headers
  dataFile.println("dB,");
  // close the file
  dataFile.close();
  delay(100);

  // init the logfile for Temperature Values
  dataFile = SD.open("logTemp-0000.csv", FILE_WRITE);
  delay(1000);
  // init the CSV file with headers
  dataFile.println("temperature,");
  // close the file
  dataFile.close();
  delay(100);
  
}

void loop() {
      // init the logfile
      dataFile = SD.open("logTEMP-0000.csv", FILE_WRITE);
      delay(1000);
      // print each of the sensor values
      dataFile.print(temperature);
      dataFile.print(",");
      // close the file
      dataFile.close();

     float temperature = ENV.readTemperature();

       // print each of the sensor values
        
       Serial.print("Temperature = ");
       Serial.print(temperature);
  }
