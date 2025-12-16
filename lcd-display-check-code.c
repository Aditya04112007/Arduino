#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Initialize 16x2 LCD
  lcd.begin(16, 2);

  // First line
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");

  // Second line
  lcd.setCursor(0, 1);
  lcd.print("LCD + Pot OK");
}

void loop() {
  // Nothing needed
}
