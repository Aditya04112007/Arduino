#include <Servo.h>   // Include servo library

Servo servoMotor;    // Create servo object

const int joyX = A0; // Joystick VRx pin
const int servoPin = 9;

void setup() {
  servoMotor.attach(servoPin); // Attach servo to pin 9
}

void loop() {
  int xValue = analogRead(joyX);          // Read joystick X-axis (0–1023)
  int servoAngle = map(xValue, 0, 1023, 0, 180); // Map to 0–180 degrees

  servoMotor.write(servoAngle);           // Move servo
  delay(15);                              // Smooth movement
}
