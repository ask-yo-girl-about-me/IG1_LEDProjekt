#include "FastLED.h"
#define NUM_LEDS 10

CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL,  13>(leds, NUM_LEDS); }
void loop() {
  leds[0-10] = CRGB::Red;
  FastLED.show();
  delay(1000);
}
