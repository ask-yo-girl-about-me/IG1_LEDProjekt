#include <SPI.h>
#include <SD.h>

int SELECTED_CHIP = 4;
int count = 0;

void setup() {
 Serial.begin(9600);
 if (SD.begin(SELECTED_CHIP)) {
   Serial.println("SD-Card initialized.");  
 } else {
   Serial.println("SD-Card failed or is missing");    
 }
}

void loop() {
 String line = String("Hallo Welt #") + String(count);
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
