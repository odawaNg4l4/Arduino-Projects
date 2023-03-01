#include<Adafruit_NeoPixel.h>

const int data_pin = 6;
const int num_pixels = 5;

Adafruit_NeoPixel pixels(num_pixels,data_pin, NEO_GRB + NEO_KHZ800);
void setup()
{
  pixels.begin();
  
  pixels.setPixelColor(0, pixels.Color(255,0,0));
  pixels.setPixelColor(1, pixels.Color(255,127,0));
  pixels.setPixelColor(2, pixels.Color(0,255,0));
  pixels.setPixelColor(3, pixels.Color(0,0,255));
  pixels.setPixelColor(4, pixels.Color(127,0,255));
  
  pixels.show();
  
}
void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
