int i;

void setup() {
  Serial.begin(9600);

}

void loop() {
  for(i = 30; i >= 0; i--)
  {
    Serial.println(i);

    delay(1000);
  }

}
