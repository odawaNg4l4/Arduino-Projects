int a;
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  
  if ( (a % 3) == 0 ) {
    Serial.println("Fizz");
  } else {
    Serial.println(a);
  }
  
 
  a = a + 1;
  delay(1000);
}
