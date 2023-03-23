int a;
void setup() {
  Serial.begin(9600);
}
 
void loop() {
   a = a + 1;
  if ( (a % 3) == 0 ) {
    Serial.println("Fizz");
  } else {
    Serial.println(a);
  }
  
 
  delay(1000);
}
