const int button = 8;     // the number of the pushbutton pin


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int count_value =0;
int prestate =0;


void setup() {
  pinMode(button, INPUT_PULLUP);      // initialize the pushbutton pin as an input:
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
    buttonState;
  }
  if (count_value == 2){
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
    buttonState;
  }
  if (count_value == 3){
    count_value =0;
    buttonState;
  }
}
