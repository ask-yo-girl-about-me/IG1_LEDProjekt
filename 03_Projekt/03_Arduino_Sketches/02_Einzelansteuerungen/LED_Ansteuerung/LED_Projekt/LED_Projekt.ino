#include "FastLED.h"
#define NUM_LEDS 40

CRGB leds[NUM_LEDS];
void setup() { FastLED.addLeds<NEOPIXEL,  13>(leds, NUM_LEDS); }
void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[1] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  leds[2] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[3] = CRGB::Yellow;
  FastLED.show();
  delay(1000);
  leds[40] = CRGB::Black;
  FastLED.show();
  delay(1000);
}
