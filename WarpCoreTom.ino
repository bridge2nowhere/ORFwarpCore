#include <Adafruit_NeoPixel.h>

#ifdef __AVR__

#include <avr/power.h>

#endif

//pins:

#define MAIN_PIN 6

#define MID_PIN 5

//# of LEDs

#define LC 100

// color channels:

int r;

int g;

int b;

 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LC, MAIN_PIN, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel strip_mid = Adafruit_NeoPixel(LC, MID_PIN, NEO_GRB + NEO_KHZ800);

int d;

void setup() {

  r = 50;

  b = 255;

  g = 50;

 

  // put your setup code here, to run once:

#if defined (__AVR_ATtiny85__)

  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);

#endif

  // End of trinket special code

  d = 500;

  strip.begin();

  strip.setBrightness(255);

  strip.show();

  strip_mid.begin();

  strip_mid.setBrightness(255);

  strip_mid.show();

 

  for (int led = 0; led < 100; led++) {

    strip_mid.setPixelColor(led, strip_mid.Color(255, 0, 0));

  }

  strip_mid.show();

 

}

 

void loop() {//

  //1

  on(0, 5);

  on(94, 100);

  off(39, 60);

  upd();

  //2

  on(6, 16);

  on(83, 93);

  off(0, 5);

  off(94, 100);

  upd();

  //3

  on(17, 27);

  on(72, 82);

  off(6, 16);

  off(83, 93);

  upd();

  //4

  on(28, 38);

  on(61, 71);

  off(17, 27);

  off(72, 82);

  upd();

  //5

  on(39, 60);

  off(28, 38);

  off(61, 71);

  upd();

 

}

void on(int start, int e) {

  for (int led = start; led <= e; led++)

    strip.setPixelColor(led, strip.Color(g, r, b));

}

void off(int start, int e) {

  for (int led = start; led <= e; led++)

    strip.setPixelColor(led, strip.Color(0, 0, 0));

}

void upd() {

  delay(d);

  strip.show();

}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
