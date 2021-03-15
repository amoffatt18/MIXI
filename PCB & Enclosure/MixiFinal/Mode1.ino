boolean drumB [] = {false, false, false, false, false, false};
boolean isDrumLit = false;

int state1Pots[] = {0, 0, 0, 0};
int state1PotsTol = 5;

void drumFunc() {

  if (!isDrumLit) { //Light up Drums
    isLit();
    isDrumLit = true;
  }

  for (int i = 0; i < 8; i++) {
    if (buttonStates [i] == 1 && i != 0 && i != 1) {
      drumB[i] = !drumB[i];
      int commandNumber = i;
      if (drumB[i]) {
        usbMIDI.sendControlChange(i, 127, 1);
        Serial.println (commandNumber);
      } else {
        usbMIDI.sendControlChange(i, 0, 1);
        Serial.println (commandNumber);
      }

    }
      if (buttonStates[i] == 1 && i == 0) {
        switchVal = 2;
        isDrumLit = false;
      }
      if (buttonStates[i] == 1 && i == 1) {
        switchVal = 3;
        isDrumLit = false;
      }

    }
  

  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    int commandNumber = i + 8;
    if (abs(thisPot - state1Pots[i]) > state1PotsTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      Serial.println (commandNumber);
      state1Pots[i] = thisPot;
    }
  }
}

void isLit() {
  for (int i = 2; i < strip.numPixels(); i++) {
    strip.setPixelColor (i, 255, 0, 255);
    strip.setPixelColor (0, 0, 0, 255);
    strip.setPixelColor (1, 255, 0, 0);
  }
  strip.show();
}
