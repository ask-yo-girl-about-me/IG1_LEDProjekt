int pushButton = 10;
int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{

}

void loop() 
  {
    val1 = digitalRead(pushButton);
    if (val1 == LOW)
    {  
      //delay(50); //50mS
      val1 = digitalRead(pushButton);
      if (val1 == HIGH) 
      {
        Serial.println(++num);
      }
    }
  
    val2 = digitalRead(pushButton);
    if (val2 == LOW)
    {  
      //delay(50); //50mS
      val2 = digitalRead(pushButton);
      if (val2 == HIGH) 
      {
        Serial.println(num=0);
      }
    }
  }

switch(num)
  {
    case 1:

      break;
      
    case 2:
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
    digitalWrite (5, LOW);// Programm Temp Messung
      break;
    
    case 3:
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
    digitalWrite (9, LOW);// Programm DB Meter
      break;
  }
 }
