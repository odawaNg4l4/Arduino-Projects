#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11 ,5, 4, 3, 2);
const int buttonLeftPin = 6;
const int buttonRightPin = 7;

int position = 0;

const int maxPosition = 16;

void setup()
{
  lcd.begin(16, 2);


    pinMode(buttonLeftPin, INPUT_PULLUP);
    pinMode(buttonRightPin, INPUT_PULLUP);

updatePosition();
}
void loop()
{
  if(digitalRead(buttonLeftPin)==LOW)
  {
    if(position > 0)
    {
      position -- ;
      updatePosition();
    }
  }
  delay(200);
}

void updatePosition() {
  lcd.clear();
  lcd.setCursor(position, 1);
  lcd.write('X');
}




