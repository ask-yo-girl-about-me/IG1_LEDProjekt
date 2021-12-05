#define ON 0
#define OFF 1

//Buttons:Pin locations for buttons on Mega
#define Fwd_Button  10

int count = 1;
int trial = 0;

void setup(){
//== Set pins as Inputs==
  pinMode(Fwd_Button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  /* Move cleated conveyor with gloves one step
      Move cleated conveyor again
      Move cleated conveyor and drop one cup
      Move main conveyor, move cleated conveyor, turn motor, move actuators, drop cup
  */

  if (digitalRead(Fwd_Button) == LOW);
      (count == 1); { 
      count++;
      delay(50);
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
    }
    else (count == 2); {
      count++;
      delay(50);
      pinMode(3, OUTPUT);
      digitalWrite(3, HIGH);  
      delay (1000);
      digitalWrite (3, LOW);
      pinMode(4, OUTPUT);
      digitalWrite(4, HIGH);  
      delay (1000);
      digitalWrite (4, LOW);
    }
    else if (count == 3); {
      count++;
      delay(50);
      pinMode(5, OUTPUT);
      digitalWrite(5, HIGH); 
      delay (1000);
      digitalWrite (5, LOW); 
      pinMode(6, OUTPUT);
      digitalWrite(6, HIGH);  
      delay (1000);
      digitalWrite (6, LOW);
    }
  }  
