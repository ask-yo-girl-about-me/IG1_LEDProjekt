const int btn = 22;
const int led = 3;
int selector = 0;
boolean isPressed = false; 

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop ()
{
  if (digitalRead(btn) == LOW && isPressed == false ) //button is pressed AND this is the first digitalRead() that the button is pressed
  {
    isPressed = true;  //set to true, so this code will not run again until button released
    doSwitchStatement(); // a call to a separate function that performs the switch statement and subsequent evoked code

    selector++; // this is done after the doSwitchStatement(), so case 0 will be executed on the first button press 
    if (selector > 3) {
      selector = 0;
    }
    // selector = (selector+1) % 4;  // does the same, without if-statement
  } else if (digitalRead(btn) == HIGH)
  {
    isPressed = false; //button is released, variable reset
  }
}

void doSwitchStatement() {
  switch(selector) {
  case 0:
    digitalWrite(led, HIGH);
    Serial.println("Case 0");
    // add a call to doExtraStuff() if you like
    break;
  case 1:
    digitalWrite(13, HIGH);
    Serial.println("Case 1");
    break;
  case 2:
    digitalWrite(4, HIGH);
    Serial.println("Case 2");
    break;
  case 3:
    digitalWrite(5, HIGH);
    Serial.println("You've reached the last selection.");
    Serial.println("Case 3");
  }
}
