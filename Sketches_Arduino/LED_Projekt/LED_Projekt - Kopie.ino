#include "FastLED.h"

#define ANZAHL_LEDS 10
#define LED_PIN 11
CRGB leds[ANZAHL_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, ANZAHL_LEDS);
}

void loop() {
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Yellow;
  FastLED.show();
  delay(1000);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(1000);
}
