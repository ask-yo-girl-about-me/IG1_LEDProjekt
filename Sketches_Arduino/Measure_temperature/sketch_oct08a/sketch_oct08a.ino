#include "NeoPixelBus.h"

#define ANZAHL_LEDS 60
#define LED_PIN 6


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
 strip.setPixelColor(11, 255, 0, 255);

}
