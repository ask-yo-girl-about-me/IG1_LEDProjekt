#include <Arduino_MKRENV.h>
#include <SPI.h>
#include <SD.h>
#define MIC A0

const int button = 8;     // button pin

// chip select for SD card
const int SD_CS_PIN = 4;  

// variables
float temperature = 0;
float humidity = 0;
float pressure = 0;
float UVA = 0;
float UVB = 0;
float UVIndex = 0;
int ledblink = 1;

// CountButton  //////////////////////////////////////////////////
int buttonState = 0;         
int count_value = 0;
int prestate = 0;

// DBMeter ////////////////////////////////////////////////////
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time

// file object
File dataFile;

void setup() {
  pinMode(button, INPUT_PULLUP);      // initialize the pushbutton pin as an input:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT); // Ausgeklammert wegen SD Karte welche auch auf PIN 4 ist
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
  dataFile = SD.open("log-0000.csv", FILE_WRITE);
  delay(1000);

  // init the CSV file with headers
  dataFile.println("temperature,humidity,pressure,UVA,UVB,UVindex");

  // close the file
  dataFile.close();
  delay(100);
  
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

    if (ledblink == 1){
      digitalWrite(A1, HIGH);
      delay(1000);
      digitalWrite(A1, LOW);
      ledblink = 2;
    }

/////Temp//////
     float temperature = ENV.readTemperature();

       // print each of the sensor values
       Serial.print("Temperature = ");
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
  
  if (count_value == 2){
    
        if (ledblink == 2){
      digitalWrite(A1, HIGH);
      delay(1000);
      digitalWrite(A1, LOW);
      delay(1000);
      digitalWrite(A1, HIGH);
      delay(1000);
      digitalWrite(A1, LOW);
      delay(1000);
      ledblink = 3;
    }

      /////DB/////
     adc= analogRead(MIC); //Read the ADC value from amplifer 
     Serial.println (adc);//Print ADC for initial calculation 
     dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values

     if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (dB>90) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
     if (dB>100) {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
       
  buttonState;
  }
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
      ledblink = 1;
    }
      float temperature = 0;
      float humidity = 0;
      float pressure = 0;
      float UVA = 0;
      float UVB = 0;
      float UVIndex = 0;
    // init the logfile
      dataFile = SD.open("log-0000.csv", FILE_WRITE);
      delay(1000);

  // read the sensors values
  temperature = ENV.readTemperature();
  humidity = ENV.readHumidity();
  pressure = ENV.readPressure();
  UVA = ENV.readUVA();
  UVB = ENV.readUVB();
  UVIndex = ENV.readUVIndex();

  // print each of the sensor values
  dataFile.print(temperature);
  dataFile.print(",");
  dataFile.print(humidity);
  dataFile.print(",");
  dataFile.print(pressure);
  dataFile.print(",");
  dataFile.print(UVA);
  dataFile.print(",");
  dataFile.print(UVB);
  dataFile.print(",");
  dataFile.println(UVIndex);

  // close the file
  dataFile.close();

  // wait 1 second to print again
  delay(1000);
  buttonState;
  }
  if (count_value == 4){
    count_value =0;
  buttonState;
  }
}
