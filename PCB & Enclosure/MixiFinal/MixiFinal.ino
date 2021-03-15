#include <Bounce2.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 4, NEO_RGB + NEO_KHZ800);

int switchVal = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  initializeButtons();
  delay(2000);
  Serial.println("Ready!");
}

void loop() {
  updateButtons();
  updatePots();

  switch (switchVal) {

    case 0: startUp(); break;
    case 1: drumFunc(); break;
    case 2: synFunc(); break;
    case 3: miscFunc(); break;
  }
}
