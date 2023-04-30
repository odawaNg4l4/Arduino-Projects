const int RLED = 9;
const int GLED = 10;
const int BLED = 11; 
const int BUTTON = 4;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup() 
{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

boolean debounce (boolean last)
{
  boolean current = digitalRead(BUTTON);
  if(last != current)
    {
      delay(5);
      current = digitalRead(BUTTON);
    }
    return current;
}
void setMode(int mode)
{
  if (mode == 1)
  //RED
    {
      digitalWrite(RLED, HIGH);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, LOW);
    }
  //GREEN
  else if (mode == 2)
    {
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, HIGH);
      digitalWrite(BLED, LOW);
    }
  //BLUE
  else if (mode == 3)
    {
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, HIGH);
    }
  //PURPLE
  else if (mode == 4)
    {
      analogWrite(RLED,127);
      analogWrite(GLED, 0);
      analogWrite(BLED, 127);
    }
  //TEAL
  else if(mode == 5)
    {
      analogWrite(BLED, 0);
      analogWrite(GLED, 127);
      analogWrite(BLED, 127);
    }
  //ORANGE
  else if (mode == 7)
    {
      analogWrite(RLED, 85);
      analogWrite(GLED, 85);
      analogWrite(BLED, 85);
    }
  //OFF
  else
    {
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, LOW);
    }

}
void loop() 
{
  currentButton = debounce(lastButton);

  if(lastButton == LOW && currentButton == HIGH)
    {
      ledMode++;
    }
    lastButton = currentButton;
    if(ledMode == 8) ledMode =0;
}
