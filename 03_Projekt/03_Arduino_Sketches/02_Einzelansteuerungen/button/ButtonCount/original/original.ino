#include <Arduino_MKRENV.h>
#define MIC A0

const int button = 8;     // button pin

// CountButton  //////////////////////////////////////////////////
int buttonState = 0;         
int count_value = 0;
int prestate = 0;

// DBMeter ////////////////////////////////////////////////////
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time

void setup() {
  pinMode(button, INPUT_PULLUP);      // initialize the pushbutton pin as an input:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT); // Ausgeklammert wegen SD Karte welche auch auf PIN 4 ist
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  Serial.begin(9600);
  
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
    
     float temperature = ENV.readTemperature();

       // print each of the sensor values
        
       Serial.print("Temperature = ");
       Serial.print(temperature);
      
       if (temperature<19.99)  {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
       if (temperature>20.00)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
       if (temperature>25.00)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
       if (temperature>27.00)  {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
       if (temperature>29.00) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
       if (temperature>31.00) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
       if (temperature>35.00) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
   
  buttonState;
  }
  if (count_value == 2){
    
     adc= analogRead(MIC); //Read the ADC value from amplifer 
     Serial.println (adc);//Print ADC for initial calculation 
     dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values

     if (dB>50) {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
     if (dB>60) {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
     if (dB>70) {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
     if (dB>80) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
     if (dB>90) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
     if (dB>100) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}

  buttonState;
  }
  if (count_value == 3){
    count_value =0;
  buttonState;
  }
}
