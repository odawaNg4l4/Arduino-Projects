#include <DHT.h>

int dhtpin = 4;
int DHTTYPE  = DHT11;

const float temperatureThreshold = 25.0;
const float humidityThreshold = 60.0;

int Gas_sensor = 3;

int RED = 7;
int BLUE = 8;
int GREEN = 9;
int red = 13;

DHT dht(dhtpin, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();

  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(Gas_sensor, INPUT);
  pinMode(red, OUTPUT);
  
}

void loop()
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  float sensor_value = analogRead(Gas_sensor);
  float ppm = map(sensor_value, 0, 1023, 0, 100);

  Serial.print(humidity);
  Serial.print(',');
  Serial.print(temperature);
  Serial.print(',');
  Serial.println(ppm);
  
  if (ppm > 60 && temperature > temperatureThreshold || humidity > humidityThreshold) {
    digitalWrite(red, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  } 
  else if (ppm > 40 && ppm < 60) {
    digitalWrite(BLUE, HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
  } 
  else {
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
delay(1000);
}