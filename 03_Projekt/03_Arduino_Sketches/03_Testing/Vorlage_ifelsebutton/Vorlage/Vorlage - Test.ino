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
  int buttonState = digitalRead (pushButton);
  Serial.println(buttonState);
  delay(1);
  
  //Wenn knopf = 0 dann if sonst else
  if (buttonState > 0 ) 
  {
    //Effektive Code für LED
  } 
  else
  {
    //Effektive Code für LED
  }
}
