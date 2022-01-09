#include <Arduino_MKRENV.h>
#define MIC A0

const int button = 8;     // button pin

// CountButton  //////////////////////////////////////////////////
int buttonState = 0;         
int count_value =0;
int prestate =0;
// DBMeter ////////////////////////////////////////////////////
int sig = A0;

void setup() {
  pinMode(button, INPUT_PULLUP);      // initialize the pushbutton pin as an input:
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
    while (!Serial);
    if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
    }
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
      
       // print an empty line
      
       Serial.println();
       if (temperature<19.99)  {digitalWrite(6, HIGH);} else {digitalWrite(6, LOW);}
       if (temperature>20.00)  {digitalWrite(0, HIGH);} else {digitalWrite(0, LOW);}
       if (temperature>25.00)  {digitalWrite(1, HIGH);} else {digitalWrite(1, LOW);}
       if (temperature>27.00)  {digitalWrite(2, HIGH);} else {digitalWrite(2, LOW);}
       if (temperature>29.00) {digitalWrite(3, HIGH);} else {digitalWrite(3, LOW);}
       if (temperature>31.00) {digitalWrite(4, HIGH);} else {digitalWrite(4, LOW);}
       if (temperature>35.00) {digitalWrite(5, HIGH);} else {digitalWrite(5, LOW);}
  }
  if (count_value == 2){
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
    buttonState;
  }
  if (count_value == 3){
    count_value =0;
    buttonState;
  }
}
