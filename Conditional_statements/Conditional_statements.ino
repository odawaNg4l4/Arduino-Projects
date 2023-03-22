int a = 32;
int b = 14;

void setup() {
  Serial.begin(9600);
    if((a != 32) || (b == 14) ){
      Serial.print("I AM HAPPY");
    }
  else{
    Serial.println("I AM SAD");
  }
    }





void loop() {
  // put your main code here, to run repeatedly:

}
