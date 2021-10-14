#include <FastLED.h>
#define PIN 2 // Hier wird angegeben, an welchem digitalen Pin die WS2812B LEDs bzw. NeoPixel angeschlossen sind
#define NUM_LEDS 20 // Hier wird die Anzahl der angeschlossenen WS2812B LEDs bzw. LED angegeben

int pushButton = 10;
int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
  FastLED.addLeds<NEOPIXEL,  13>(leds, NUM_LEDS); // Initialisierung der NeoPixel (WS2812B)
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
