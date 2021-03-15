int buttonPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
int buttonStates[] = {0, 0, 0, 0, 0, 0, 0, 0};
Bounce * buttons = new Bounce[8];

int potPins[] = {A0, A1, A2, A3};
int potStates[] = {0, 0, 0, 0};

void initializeButtons() {
  for (int i = 0; i < 8; i++) {
    buttons[i].attach(buttonPins[i] , INPUT_PULLUP  );
    buttons[i].interval(25);
  }
}

void updateButtons() {
  for (int i = 0; i < 8; i++) {
    buttons[i].update();
    if (buttons[i].rose()) {
      buttonStates[i] = 1;
    }
    else {
      buttonStates[i] = 0;
    }
  }
}


void updatePots() {
  for (int i = 0; i < 4; i++) {
    int thisPot = analogRead(potPins[i]);
    int mapPot = map(thisPot, 0, 1023, 0, 127);
    potStates[i] = mapPot;
  }
}
