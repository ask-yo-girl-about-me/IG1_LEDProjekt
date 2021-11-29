int Button = 10;
//int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
  pinMode(Button, INPUT); //Pin Modus definietion
  Serial.begin(9600); //Serial Port initalisierung
}

void loop() {
    int buttonValue = analogRead(Button)  / 341;  //ausgabe des Button dividiert durch 341 damit 3 mögliche Cases eintreffen

    //if (buttonValue != lastPotValue)  //prüft ob sich etwas geändert hat
    
    switch(buttonValue) {
      
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
