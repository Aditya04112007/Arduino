#include <Servo.h>

Servo myServo;

const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

long duration;
int distance;
int pos = 0;       // Servo position
int step = 1;      // Servo step (1° per move)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  myServo.attach(6); // Attach servo to pin 6
}

void loop() {
  // Measure distance using ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Distance in cm

  if (distance < 20) { // Object detected within 20 cm
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    // Stop servo at current position
    myServo.write(pos);
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    // Sweep servo slowly
    pos += step;
    if (pos >= 180 || pos <= 0) {
      step = -step; // Change direction at ends
    }
    myServo.write(pos);
    delay(25); // Increase delay for slower sweep
  }

  delay(50); // Small delay for stability
}
