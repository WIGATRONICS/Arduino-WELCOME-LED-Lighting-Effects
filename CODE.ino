// Pins for W E L C O M E
int letters[] = {2, 3, 4, 5, 6, 7, 8};
int numLetters = 7;

void setup() {
  for (int i = 0; i < numLetters; i++) {
    pinMode(letters[i], OUTPUT);
  }
}


// Effect 1: All ON
void allOn() {
  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], HIGH);
  }
}

// Effect 2: All OFF
void allOff() {
  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], LOW);
  }
}

// Effect 3: Running light (left to right)
void runningForward() {
  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], HIGH);
    delay(150);
    digitalWrite(letters[i], LOW);
  }
}

// Effect 4: Running light (right to left)
void runningBackward() {
  for (int i = numLetters - 1; i >= 0; i--) {
    digitalWrite(letters[i], HIGH);
    delay(150);
    digitalWrite(letters[i], LOW);
  }
}

// Effect 5: Blink all
void blinkAll(int times) {
  for (int i = 0; i < times; i++) {
    allOn();
    delay(300);
    allOff();
    delay(300);
  }
}

// Effect 6: Alternate pattern
void alternate() {
  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], (i % 2 == 0) ? HIGH : LOW);
  }
  delay(400);

  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], (i % 2 == 0) ? LOW : HIGH);
  }
  delay(400);
}

// Effect 7: Build-up (WELCOME appears gradually)
void buildUp() {
  allOff();
  for (int i = 0; i < numLetters; i++) {
    digitalWrite(letters[i], HIGH);
    delay(250);
  }
}

// ---------------- MAIN LOOP ----------------

void loop() {

  buildUp();
  delay(800);

  blinkAll(3);

  runningForward();
  runningBackward();

  for (int i = 0; i < 5; i++) {
    alternate();
  }

  allOn();
  delay(1000);

  allOff();
  delay(500);
}
