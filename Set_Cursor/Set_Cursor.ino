#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int numRows = 2;
const int numCols = 16;
void setup() {
  lcd.begin(numCols, numRows);
}

void loop() {
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
    for (int  thisRow = 0; thisRow < numRows; thisRow++) {
      for (int thisCol = 0; thisCol < numCols; thisCol++) {
        lcd.setCursor(thisCol, thisRow);
        lcd.write(thisLetter);
        delay(200);
      }
    }
  }
}
