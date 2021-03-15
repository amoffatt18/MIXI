boolean miscB [] = {false, false, false, false, false, false};
boolean isMiscLit = false;

int state3Pots[] = {0,0,0,0};
int state3PotsTol = 5;


void miscFunc() {
  if (!isMiscLit) { //Light up Synthesizers
    isLit3();
    isMiscLit = true;
  }


  for (int i = 0; i < 8; i++) {
    if (buttonStates [i] == 1 && i != 0 && i != 1) {
      miscB[i] = !miscB[i];
      int commandNumber = i + 30;
      if (miscB [i]) {
        usbMIDI.sendControlChange(i + 30, 127, 1);
        Serial.println(commandNumber);
      } else {
        usbMIDI.sendControlChange(i + 30, 0, 1);
        Serial.println(commandNumber);
      }
    }

    if (buttonStates[i] == 1 && i == 0) {
      switchVal = 1;
      isMiscLit = false;
    }
    if (buttonStates[i] == 1 && i == 1) {
      switchVal = 2;
      isMiscLit = false;
    }
  }
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    int commandNumber = i + 8;
    if (abs(thisPot - state3Pots[i]) > state3PotsTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      Serial.println (commandNumber);
      state3Pots[i] = thisPot;
    }
  }
}
void isLit3() {
  for (int i = 2; i < strip.numPixels(); i++) {
    strip.setPixelColor (i, 255, 0, 0);
    strip.setPixelColor (0, 255, 0, 255);
    strip.setPixelColor (1, 0, 0, 255);
  }
  strip.show();
}
