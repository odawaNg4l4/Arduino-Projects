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
  }
  // Serial.println("ODAWA");
  delay(1000);
}
//FOR LOOP
int a;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    for(a > 0; a <= 10; a++)
Serial.println(a);

delay(1000);
}

//COMPUTE SUM OF 10 NATURAL NUMBERS
int a;
int result=0;

void setup()
{
Serial.begin(9600);
 for(a = 1;a <= 10;a++)
  {
    result = result + a;
    Serial.println(a);
  }
  Serial.println(result);
  delay(1000);
}

void loop()
{

}