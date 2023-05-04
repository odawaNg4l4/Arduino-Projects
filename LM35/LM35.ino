const int RLED = 9;
const int GLED = 10;
const int BLED = 11;
const int TEMP = 0;
int val =0;

void setup() 
{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
    val = analogRead(TEMP);
    Serial.println(val);
    float voltage;
    float temp_c;
    voltage = analogRead(TEMP) * 5000/1024;;
    temp_c = 100.0 * voltage - 50;
    Serial.print("voltage");
    Serial.print(voltage);
    Serial.print("deg C");
    Serial.print(temp_c);

    delay(1000);
}
   

  /*if ()
    {
      digitalWrite(RLED, HIGH);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, LOW);
    }
  else if(val == upper_temp)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  else if(val > lower_temp && val < upper_temp)
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
    /*val = analogRead(TEMP);
    Serial.println(val);
    delay(500);*/

