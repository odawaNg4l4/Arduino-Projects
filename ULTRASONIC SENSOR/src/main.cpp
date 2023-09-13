#include <Arduino.h>

const int trigPin = 3;
const int echoPin = 2;
const int LED_PIN = 6;
const int DISTANCE_THRESHOLD = 50; 

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if(distance < DISTANCE_THRESHOLD)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
    
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.println(duration);
  delay(1000);
}

