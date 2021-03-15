boolean synB [] = {false, false, false, false, false, false};
boolean isSynLit = false;

int state2Pots[] = {0,0,0,0};
int state2PotsTol = 5;


void synFunc() {
  if (!isSynLit) { //Light up Synthesizers
    isLit2();
    isSynLit = true;
  }


  for (int i = 0; i < 8; i++) {
    if (buttonStates [i] == 1 && i != 0 && i != 1) {
      synB[i] = !synB[i];
      int commandNumber = (i + 20);
      if (synB [i]) {

        usbMIDI.sendControlChange(i + 20, 127, 1);
        Serial.println (commandNumber);
      } else {
        usbMIDI.sendControlChange(i + 20, 0, 1);
        Serial.println (commandNumber);
      }
    }

    if (buttonStates[i] == 1 && i == 0) {
      switchVal = 1;
      isSynLit = false;
    }
    if (buttonStates[i] == 1 && i == 1) {
      switchVal = 3;
      isSynLit = false;
    }

  }
  for (int i = 0; i < 4; i++) {
    int thisPot = potStates[i];
    int commandNumber = i + 8;
    if (abs(thisPot - state2Pots[i]) > state2PotsTol) {
      usbMIDI.sendControlChange(i + 8, thisPot, 1);
      Serial.println (commandNumber);
      state2Pots[i] = thisPot;
    }
  }
}
void isLit2() {
  for (int i = 2; i < strip.numPixels(); i++) {
    strip.setPixelColor (i, 0, 0, 255);
    strip.setPixelColor (0, 255, 0, 255);
    strip.setPixelColor (1, 255, 0, 0);
  }
  strip.show();
}
