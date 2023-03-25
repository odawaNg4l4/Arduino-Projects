int i = 3;
int j = 0;

void setup() {
  Serial.begin(9600);
}
void loop(){
  if (i < 3){
       while(j < 5){
    
       Serial.println("ODAWA");
       j++;
  }
  }
  // Serial.println("ODAWA");
  delay(1000);
}
