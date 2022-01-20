/*
  02 Sensors to SD v0001
  Read information from the all of the sensors
  on the MKR ENV Shield and store it on a
  CSV file inside an SD card. Connect the SD
  card to the slot on the ENV Shield
  (c) 2019 D. Cuartielles for Arduino
  This code is Free Software licensed under GPLv3
*/

#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>

// chip select for SD card
const int SD_CS_PIN = 4;

// variables
float temperature = 0;
float humidity = 0;

// file object
//File dataFiledb;
File dataFiletemp;

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

  // init SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("Failed to initialize SD card!");
    while (1);
  }

  // init the logfile
  dataFiletemp = SD.open("logTemp-0000.csv", FILE_WRITE);
  delay(1000);
  // init the CSV file with headers
  dataFiletemp.println("temperature");
  // close the file
  dataFiletemp.close();
  delay(100);

  // init the logfile
 // dataFiledb = SD.open("logDB-0000.csv", FILE_WRITE);
 // delay(1000);
  // init the CSV file with headers
//  dataFile.println("humidity");
  // close the file
 // dataFile.close();
 // delay(100);
}

void loop() {
  // init the logfile
  dataFiletemp = SD.open("logTemp-0000.csv", FILE_WRITE);
  delay(1000);
  // init the logfile
//  dataFiledb = SD.open("logDB-0000.csv", FILE_WRITE);
//  delay(1000);

  // read the sensors values
  temperature = ENV.readTemperature();
//  humidity = ENV.readHumidity();

  // print each of the sensor values
  dataFiletemp.print(temperature);
  dataFiletemp.print(",");
//  dataFile.print(humidity);
 // dataFile.print(",");


  // close the file
  dataFiletemp.close();

  // wait 1 second to print again
  delay(1000);
}
