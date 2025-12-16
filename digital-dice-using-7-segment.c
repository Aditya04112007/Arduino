// Segment pins: a b c d e f g
int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

int buttonPin = 9;
bool lastButtonState = HIGH;

// Segment patterns for numbers 1 to 6
byte numbers[6][7] = {
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}  // 6
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }

  pinMode(buttonPin, INPUT_PULLUP);

  // Seed random using floating analog pin
  randomSeed(analogRead(A0));
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect button press
  if (lastButtonState == HIGH && buttonState == LOW) {
    int diceNumber = random(1, 7);  // 1 to 6
    showNumber(diceNumber);
    delay(200);  // Debounce
  }

  lastButtonState = buttonState;
}

void showNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], numbers[num - 1][i]);
  }
}
