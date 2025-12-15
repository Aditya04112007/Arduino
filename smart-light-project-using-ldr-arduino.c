int ldrPin = A0;     // LDR connected to A0
int ledPin = 9;      // LED connected to pin 9
int ldrValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read LDR value
  Serial.println(ldrValue);

  if (ldrValue < 500) {   // Dark condition
    digitalWrite(ledPin, HIGH);
  } else {                // Bright condition
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
