#include <FastLED.h>

#define NUM_LEDS 480 //96 leds per meter, 5 meters. 480 leds in total. 12V
#define LED_PIN 2 //D2 is Data Pin 2

CRGB leds[NUM_LEDS];

uint8_t paletteIndex = 0;

DEFINE_GRADIENT_PALETTE (pink_gp) {
  0, 255, 36, 131, //peach pink
  100, 255, 56, 209, //lightish pink
  180, 130, 5, 255, //purple
  255, 56, 255, 252 //light blue cyan
};

CRGBPalette16 myPal = pink_gp;



void setup () {
  FastLED.addLeds<WS2811, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(30);
}


void loop() {
  fill_palette(leds, NUM_LEDS, paletteIndex, 1, myPal, 230, LINEARBLEND);
  EVERY_N_MILLISECONDS(10) {
  paletteIndex++;
}

  FastLED.show();
}

