const int button = 10;
int selector = 0;
boolean isPressed = false;
 
void setup(){
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
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);  
  delay (1000);
  digitalWrite (13, LOW);
  pinMode(14, OUTPUT);
  digitalWrite(14, HIGH);  
  delay (1000);
  digitalWrite (14, LOW);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);  
  delay (1000);
  digitalWrite (8, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  delay (1000);  
  digitalWrite (9, LOW);
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
  case 0:
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
  break;
  case 1:
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
  break;
  case 2:
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);  
    delay (1000);
    digitalWrite (13, LOW);
    pinMode(14, OUTPUT);
    digitalWrite(14, HIGH);  
    delay (1000);
    digitalWrite (14, LOW);
  break;
  case 3:
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
 
