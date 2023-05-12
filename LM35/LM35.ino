const int RLED = 9;
const int GLED = 10;
const int BLED = 11;
const int TEMP = A0;
const int lower_bound = 29;
const int upper_bound = 80;
int val =0;

void setup() 
{
  pinMode(TEMP, INPUT);
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
    val = analogRead(TEMP);
    Serial.println(val);

    delay(1000);

  if (val == lower_bound)
    {
      digitalWrite(RLED, HIGH);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, LOW);
    }
  else if(val > lower_bound && val < upper_bound)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if(val == upper_bound)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  else
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }

}

