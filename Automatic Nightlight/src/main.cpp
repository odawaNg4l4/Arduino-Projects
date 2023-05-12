#include <Arduino.h>
 const int RLED = 9;
 const int LIGHT = 0;
 const int Max_Light = 200;
 const int Min_Light = 900;

  int val = 0;

void setup() {
  pinMode(RLED, OUTPUT);
}

void loop() {
  val = analogRead(LIGHT);
  val = map(val, Max_Light, Min_Light, 255, 0);
  val = constrain(val, 0, 255);

  analogWrite(LIGHT, val);
}