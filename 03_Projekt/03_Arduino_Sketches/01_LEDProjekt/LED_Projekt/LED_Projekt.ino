#define PIN 5
#define PIN 6
#define PIN 7
#define PIN 8
#define PIN 9
#define PIN 10
#define PIN 11
#define PIN 12
#define PIN 13

int pushButton = 10;

void setup() 
{
}

void loop() 
{
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
    // Programm Temp Messung
      break;
    
    case 3:
    // Programm DB Meter
      break;
  }
}
