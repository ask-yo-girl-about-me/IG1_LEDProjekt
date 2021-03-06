const int button = 10;
int selector = 0;
boolean isPressed = false;
//here we are storing the volume value
int volume = analogRead(A0);
 
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
    }else{
    //if it is smaller we can turn the LED off
    digitalWrite(a, LOW);
      }
    }
  break;
  }
}
 
