#include <SPI.h>
#include <SD.h>

const int SD_CS_PIN = 4;

float db_value = 0;
int db_value = A0;

// file object
File dataFile;

void setup() {
  Serial.begin(9600);
  
  // init SPI
  SPI.begin();
  delay(100);

  // init SD card
  if(!SD.begin(SD_CS_PIN)) {
    Serial.println("Failed to initialize SD card!");
    while (1);
  }

  // init the logfile
  dataFile = SD.open("log-0000.csv", FILE_WRITE);
  delay(1000);

  // init the CSV file with headers
  dataFile.println("db_value");

  // close the file
  dataFile.close();
  delay(100);
}


void loop() {
  // init the logfile
  dataFile = SD.open("log-0000.csv", FILE_WRITE);
  delay(1000);

  // read the sensors values
  db_value = analogRead(MIC)*50;

  // print each of the sensor values
  dataFile.print(db_value);

  // close the file
  dataFile.close();

  // wait 1 second to print again
  delay(1000);
}
