#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  
  lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(0,0);
  for(int thisChar = 0; thisChar < 10; thisChar++){
    lcd.print(thisChar);
    delay(500);
  }
  lcd.setCursor(16,1);
  lcd.autoscroll();
    for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.print(thisChar);
    delay(500);
}
lcd.noAutoscroll();
lcd.clear();
}
