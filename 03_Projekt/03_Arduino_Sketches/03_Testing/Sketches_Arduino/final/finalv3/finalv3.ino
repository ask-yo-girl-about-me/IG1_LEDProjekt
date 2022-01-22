#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

// button pin
const int button = 8;     

// chip select for SD card
const int SD_CS_PIN = 4;  

// variables
float temperature = 0;
int ledblink = 1;

// CountButton  //
int buttonState = 0;         
int count_value = 0;
int prestate = 0;

// DBMeter //
int adc;
//the variable that will hold the value read from the microphone each time
int dB, PdB; 

// file object
File dataFile_temp;
File dataFile_dB;

void setup() {
    // initialize the pushbutton pin as an input:
    pinMode(button, INPUT_PULLUP);      
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(A1, OUTPUT);
  
    Serial.begin(9600);
    while (!Serial);
    
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
  dataFile_temp = SD.open("log-0001.csv", FILE_WRITE);
  delay(1000);
  dataFile_dB = SD.open("log-0002.csv", FILE_WRITE);

  // init the CSV file with headers
  dataFile_temp.println("temperature");
  dataFile_dB.println("dB");

  // close the file
  dataFile_temp.close();
  delay(100);
  dataFile_dB.close();
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
    }else if(buttonState == HIGH){
        prestate = 0;
    }

    // Temperatur Meter
    if (count_value == 1){
        if (ledblink == 1){
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            ledblink = 2;
        }

        /////Temp//////
        float temperature = ENV.readTemperature();

        // print each of the sensor values
        Serial.print("Temp Meter = ");
        Serial.print(temperature);
       
        Serial.println();
        if (temperature<19.99)  {digitalWrite(A1, HIGH);} else {digitalWrite(A1, LOW);}
        if (temperature>20.00)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
        if (temperature>25.00)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
        if (temperature>27.00)  {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
        if (temperature>29.00) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
        if (temperature>31.00) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
        if (temperature>35.00) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
        buttonState;
    }

    // Log Temperatur
    if (count_value == 2){
        if (ledblink == 2){
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            ledblink = 3;
        }
      // init the logfile
      dataFile_temp = SD.open("log-0001.csv", FILE_WRITE);
      delay(1000);
      
      // read the sensors values
      float temperature = ENV.readTemperature();
      
        // print each of the sensor values
        Serial.print("Temp Log = ");
        Serial.println(temperature);
      
      // print each of the sensor values
      dataFile_temp.print(temperature);
      // close the file
      dataFile_temp.close();
      // wait 1 second to print again
      delay(1000);
      buttonState;
    }

    // Dezibel Meter
    if (count_value == 3){
        if (ledblink == 3){
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            ledblink = 4;
        }   

        /////DB/////
        adc= analogRead(MIC); //Read the ADC value from amplifer
        dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values
        Serial.print("dB Meter = ");
        Serial.print(dB);//Print ADC for initial calculation 

        Serial.println();
        if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
        if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
        if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
        if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
        if (dB>90) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
        if (dB>100) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
        buttonState;
    }
  
    // Log Dezibel
    if (count_value == 4){
        if (ledblink == 4){
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            digitalWrite(A1, HIGH);
            delay(1000);
            digitalWrite(A1, LOW);
            delay(1000);
            ledblink = 5;
        }
        // init the logfile
        dataFile_dB = SD.open("log-0002.csv", FILE_WRITE);
        delay(1000);
        
        adc= analogRead(MIC); //Read the ADC value from amplifer
        dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values
        Serial.print("dB Log = ");
        Serial.println(dB);//Print ADC for initial calculation

        // print each of the sensor values
        dataFile_dB.print(dB);
        // close the file
        dataFile_dB.close();
        // wait 1 second to print again
        delay(1000);
        
        buttonState;
    }
  
    if (count_value == 5){
        count_value =0;
        buttonState;
    }
}
