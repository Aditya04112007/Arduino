#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// ONLY CARD UID IS VALID
byte validCardUID[4] = {0x13, 0xB2, 0x08, 0x35};

void setup() {
  Serial.begin(9600);

  SPI.begin();
  rfid.PCD_Init();

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Scan Card...");
}

void loop() {

  // Wait until a NEW card is present
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  bool valid = true;
  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != validCardUID[i]) {
      valid = false;
      break;
    }
  }

  lcd.clear();
  if (valid) {
    lcd.print("VALID CARD");
    lcd.setCursor(0, 1);
    lcd.print("Access Granted");
  } else {
    lcd.print("INVALID TAG");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
  }

  // Stop RFID communication
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(2000);  // show message

  // Wait until card is removed
  while (rfid.PICC_IsNewCardPresent()) {
    delay(50);
  }

  lcd.clear();
  lcd.print("Scan Card...");
} // <-- THIS IS THE FINAL closing brace of loop()
