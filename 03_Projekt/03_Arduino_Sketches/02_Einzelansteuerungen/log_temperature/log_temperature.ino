#include <SPI.h>
#include <SD.h>
#include <Arduino_MKRENV.h>

int SELECTED_CHIP = 4;
int count = 0;

void setup() {
 Serial.begin(9600);
 if (SD.begin(SELECTED_CHIP)) {
   Serial.println("SD-Card initialized.");  
 } else {
   Serial.println("SD-Card failed or is missing");    
 }
 {
   Serial.begin(9600);
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
 }
}

void loop() 
{
  
  // read all the sensor values
    float temperature = ENV.readTemperature();
  
  // print each of the sensor values
    Serial.print("Temperature = ");
    Serial.print(temperature);
  
   // print an empty line
    Serial.println();

  // wait 1 second to print again
    delay(1000);}
{String line = String("Hallo Welt #") + String(count);
 writeToSD(line);
 count = count + 1;
 delay(1000);
}

void writeToSD(String line) {
 File dataFile = SD.open("temperature.csv", FILE_WRITE);
 if (dataFile) {
   dataFile.println(line); // Auf die SD-Karte schreiben
   dataFile.close();       // Datei schließen
   Serial.println(line);
 } else {
   Serial.println("Error opening datafile");
 }
}
