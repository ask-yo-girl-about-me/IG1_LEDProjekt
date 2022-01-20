#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

const int button = 8;     // button pin
const int SD_CS_PIN = 4;  // chip select for SD card
float temperature = 0;

// CountButton  //////////////////////////////////////////////////
int buttonState = 0;         
int count_value = 0;
int prestate = 0;

// DBMeter ////////////////////////////////////////////////////
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time

// file object
File dataFile1;
//File dataFile2;

void setup() {
  pinMode(button, INPUT_PULLUP);      // initialize the pushbutton pin as an input:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  Serial.begin(9600);
  while (!Serial);
    
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
  
  // init the logfile for Temperature Values
  dataFile1 = SD.open("log1-0000.csv", FILE_WRITE);
  delay(1000);
  // close the file
  dataFile1.close();
  delay(100);

  // init the logfile for Temperature Values
//dataFile2 = SD.open("log2-0000.csv", FILE_WRITE);
//  delay(1000);
  // close the file
//  dataFile2.close();
//  delay(100);
  
}

void loop() {
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(button);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState == LOW && prestate == 0) {
    count_value++;
    Serial.println(count_value);
    delay(100);
    prestate = 1;
  } else if(buttonState == HIGH) {
    prestate = 0;
  }

  if (count_value == 1){
    
      // init the logfile
      dataFile1 = SD.open("log1-0000.csv", FILE_WRITE);  

     float temperature = ENV.readTemperature();
     
      // print each of the sensor values
      dataFile1.print("Temperature:");
      dataFile1.print(",");
      dataFile1.print(temperature);
      dataFile1.print(",");
      
      // close the file
      dataFile1.close();
           
       if (temperature<19.99)  {digitalWrite(7, HIGH);} else {digitalWrite(6, LOW);}
       if (temperature>20.00)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
       if (temperature>25.00)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
       if (temperature>27.00)  {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
       if (temperature>29.00) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
       if (temperature>31.00) {digitalWrite(5, HIGH);} else {digitalWrite(4, LOW);}
       if (temperature>35.00) {digitalWrite(6, HIGH);} else {digitalWrite(5, LOW);}



 //      Serial.print("Temperature = ");
  //     Serial.print(temperature);
      
  buttonState;
  }
  if (count_value == 2){

      // init the logfile
 //     dataFile2 = SD.open("log2-0000.csv", FILE_WRITE);
    
     adc= analogRead(MIC); //Read the ADC value from amplifer 
     Serial.println (adc);//Print ADC for initial calculation 
     dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values

     if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (dB>90) {digitalWrite(5, HIGH);} else {digitalWrite(4, LOW);}
     if (dB>100) {digitalWrite(6, HIGH);} else {digitalWrite(5, LOW);}

//      dataFile2.print("Dezibel:");
//      dataFile2.print(",");
//      dataFile2.print(dB);
//      dataFile2.print(",");
      
      // close the file
//      dataFile2.close();
      
  buttonState;
  }
  if (count_value == 3){
    count_value =0;
  buttonState;
  }
}
