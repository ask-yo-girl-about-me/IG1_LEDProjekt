#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN 2 // Hier wird angegeben, an welchem digitalen Pin die WS2812 LEDs bzw. NeoPixel angeschlossen sind
#define NUMPIXELS 20 // Hier wird die Anzahl der angeschlossenen WS2812 LEDs bzw. NeoPixel angegeben
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int pushButton = 10;
int pause=100; // 100 Millisekunden Pause bis zur Ansteuerung der nächsten LED.

void setup() 
{
  pixels.begin(); // Initialisierung der NeoPixel
}

void loop()
{
	int buttonState = digitalRead (pushButton);
	Serial.println(buttonState);
	delay(1);
  
  if (buttonState > 0 ) 
  {} 
  else
  {
    pixels.setPixelColor(1, pixels.Color(0,255,0)); // Pixel1 leuchtet in der Farbe Grün
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, in dieser Zeit wird nichts verändert.
    pixels.setPixelColor(2, pixels.Color(0,150,0)); // Pixel2 leuchtet in der Farbe Grün
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, in dieser Zeit wird nichts verändert.
    pixels.setPixelColor(3, pixels.Color(0,50,0)); // Pixel3 leuchtet in der Farbe Grün
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, in dieser Zeit wird nichts verändert.
    pixels.setPixelColor(4, pixels.Color(0,10,0)); // Pixel4 leuchtet in der Farbe Grün
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, in dieser Zeit wird nichts verändert.
    pixels.setPixelColor(5, pixels.Color(0,1,0)); // Pixel5 leuchtet in der Farbe Grün
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, in dieser Zeit wird nichts verändert.

    // Zurücksetzen aller Pixelfarben auf Stufe "0" (aus)
    pixels.setPixelColor(1, pixels.Color(0,0,0)); 
    pixels.setPixelColor(2, pixels.Color(0,0,0)); 
    pixels.setPixelColor(3, pixels.Color(0,0,0)); 
    pixels.setPixelColor(4, pixels.Color(0,0,0)); 
    pixels.setPixelColor(5, pixels.Color(0,0,0)); 
    pixels.show(); // Durchführen der Pixel-Ansteuerung
    delay (pause); // Pause, die LEDs bleiben in dieser Zeit aus
  }
}