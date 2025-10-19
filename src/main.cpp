


#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7); //16x2 display 
const int clearPin = 6;
int curX = 0; int curY = 0; //cursor is set at top-left (0,0)
char serialInput;
// put function declarations here:
// int myFunction(int, int);


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(clearPin, INPUT);
}

void loop() {
  //TODO if cursor is max length move down, when at bottom right CLEAR and continue
  if (curX == 15 && curY == 1){
    curX = 0; curY--;
    lcd.clear();
  } else if (curX == 15){
    curX = 0; curY++;
    lcd.setCursor(curX,curY);
  }


  if (Serial.available()) {
    serialInput = Serial.read();
    lcd.write(serialInput);
    Serial.println("Character(s) written to LCD");
    curX += 1;
  } else if (digitalRead(clearPin)==HIGH) {
    Serial.println("Display Reset!");
    lcd.clear();
  }
}

// put function definitions here:
/*int myFunction(int x, int y) {
  return x + y;
}*/