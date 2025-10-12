#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  if (Serial.available()) {
    
    lcd.write(Serial.read());
  }
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}