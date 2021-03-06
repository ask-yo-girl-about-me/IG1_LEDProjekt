#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

const int SD_CS_PIN = 4;      //SD Card
const int button = 8;
float ENDE = 0;     //
int db_value = A0;
int buttonState = 0;
File dataFile;       // file object

void setup() {
pinMode(0, OUTPUT);     //  LED Gruen 01
pinMode(1, OUTPUT);     //  LED Gruen 02
pinMode(2, OUTPUT);     //  LED Gelb 01
pinMode(3, OUTPUT);     //  LED Gelb 02
pinMode(4, OUTPUT);     //  LED Rot 01
pinMode(5, OUTPUT);     //  LED Rot 02
pinMode(6, OUTPUT);     //  LED Blau 01
pinMode(button, INPUT_PULLUP);      //  Button
Serial.begin(9600);     // startet den Serial Monitor, mehr dazu später

  // init the ENV Shield
  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
  
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
  dataFile.println("db_value,ENDE");

  // close the file
  dataFile.close();
  delay(100);

}

void loop() {
    if (digitalWrite(8) == LOW) // Abfrage ob der Taster gedrückt ist
    {
      // init the logfile 
      dataFile = SD.open("log-0000.csv", FILE_WRITE);
      delay(10);
    
      // read the sensors values
      long db_value = 0;
        for(int i=0; i<32; i++)
        {
            db_value += analogRead(A0);
        }
        db_value >>= 5;
        Serial.println(db_value);
        delay(10);
         if (db_value>200) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
         if (db_value>250) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
         if (db_value>300) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
         if (db_value>350) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
         if (db_value>400) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
         if (db_value>500) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
         if (db_value>600) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
     
      // print each of the sensor values
      dataFile.print(db_value);
      dataFile.print(",");
      dataFile.print(ENDE);
      dataFile.print(",");
    
    
      // close the file
      dataFile.close();
      
      // wait 1 second to print again
      delay(10);
    } 
else {
 digitalWrite (6, HIGH)
}
}
