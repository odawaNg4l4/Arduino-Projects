const int Speaker_pin = 9;

void setup() {
  pinMode(Speaker_pin, OUTPUT);
}

void loop() {
  tone(Speaker_pin, 440, 500);
  delay(1000);

}
