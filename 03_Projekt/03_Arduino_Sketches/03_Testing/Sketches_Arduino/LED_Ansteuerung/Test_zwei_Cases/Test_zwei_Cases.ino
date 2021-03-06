const int button = 10;
int selector = 0;
boolean isPressed = false;
 
void setup(){
    //for switch case with button Pullup
    pinMode(button, INPUT_PULLUP);
    
    //here is an input for sound sensor
    pinMode(A0, INPUT);
    
    //here we are setting up all pins as an outputs for LEDs
    for(int z = 0; z < 9; z++){
    pinMode(z, OUTPUT);
    }   
}

void loop() {
  if (digitalRead(button) == LOW && isPressed == false ) { 
      isPressed = true;
      doSwitchStatement();

      selector++; 
      if (selector > 3) {
        selector = 0;
      }
  } else if (digitalRead(button) == HIGH){
    isPressed = false;
    }
}

void doSwitchStatement() {
  switch(selector) {
  case 0:
    //here we are storing the volume value
    int volume = analogRead(A0);
    //max value for analog read is 1023 but it must be very very loud to reach this value
    //so I lower it down in map function to 700
    //mapping volume value to make it easier to turn LEDs on
    volume = map(volume, 0, 1200, 0, 10);
    //for loop to turn on or off all LEDs
    //thanks to this loop code for this project is very short
    //we are going through all pins where we have LEDs and checking if the volume is
    //bigger then pin number (that's why we are maping the volume)
    for(int a = 0; a < 9; a++){ 
     if(volume >= a){
      //if it is bigger we can turn on the LED
      digitalWrite(a, HIGH);
      }
      else{
      //if it is smaller we can turn the LED off
      digitalWrite(a, LOW);
      }
    }
  break;
  case 1:
   pinMode(0, OUTPUT);
    digitalWrite(0, HIGH);
    delay (1000);
    digitalWrite (0, LOW);
    pinMode(1, OUTPUT);
    digitalWrite(1, HIGH);
    delay (1000);
    digitalWrite (1, LOW);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH); 
    delay (1000); 
    digitalWrite (2, LOW);
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);  
    delay (1000);
    digitalWrite (3, LOW);
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);  
    delay (1000);
    digitalWrite (4, LOW);
    pinMode(5, OUTPUT);
    digitalWrite(5, HIGH); 
    delay (1000);
    digitalWrite (5, LOW); 
    pinMode(6, OUTPUT);
    digitalWrite(6, HIGH);  
    delay (1000);
    digitalWrite (6, LOW);
    pinMode(7, OUTPUT);
    digitalWrite(7, HIGH);  
    delay (1000);
    digitalWrite (7, LOW);
    pinMode(8, OUTPUT);
    digitalWrite(8, HIGH);  
    delay (1000);
    digitalWrite (8, LOW);
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);
    delay (1000);  
    digitalWrite (9, LOW);  
  }
}
 
