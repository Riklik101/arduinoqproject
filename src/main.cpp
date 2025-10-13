#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);
const int clearPin = 6;
char serialInput;
// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(clearPin, INPUT);
}

void loop() {
  if (Serial.available()) {
    serialInput = Serial.read();
    lcd.write(serialInput);
    Serial.println("Character(s) written to LCD");
  } else if (digitalRead(clearPin)==HIGH) {
    lcd.clear();
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}