#include "FastLED.h"
#define ANZAHL_LEDS 60
#define LED_PIN 6

CRGB leds[ANZAHL_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, ANZAHL_LEDS);
}

void loop() {
  for (int i = 0; i < ANZAHL_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    leds[i] = CRGB::Black;
    delay(200);
  }
}
