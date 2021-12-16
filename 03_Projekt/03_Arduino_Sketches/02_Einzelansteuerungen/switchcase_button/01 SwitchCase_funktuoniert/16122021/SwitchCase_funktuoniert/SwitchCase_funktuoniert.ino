const int button = 10;
int selector = 1;
boolean isPressed = false;
 
void setup(){
//here is an input for sound sensor
pinMode(A0, INPUT);
//here we are setting up all pins as an outputs for LEDs
for(int z = 0; z < 6; z++){
pinMode(z, OUTPUT);
}
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
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
  case 1:
    //here we are storing the volume value
    int volume = analogRead(A0);
    //max value for analog read is 1023 but it must be very very loud to reach this value
    //so I lower it down in map function to 700
    //mapping volume value to make it easier to turn LEDs on
    volume = map(volume, 0, 4000, 0, 10);
    //for loop to turn on or off all LEDs
    //thanks to this loop code for this project is very short
    //we are going through all pins where we have LEDs and checking if the volume is
    //bigger then pin number (that's why we are maping the volume)
    for(int a = 0; a < 6; a++){ 
     if(volume >= a){
     //if it is bigger we can turn on the LED
     digitalWrite(a, HIGH);
     }else{
     //if it is smaller we can turn the LED off
     digitalWrite(a, LOW);
     }
    }
  break;
  case 2:
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
  }
}
 
