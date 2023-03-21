//BASIC BODMAS
int a;
int b;
int c;
int d;

void setup() 
{
    Serial.begin(9600);

}

void loop() {
 a = 10 / 2;
 Serial.println(a);
 b = a * 5;
 Serial.println(b);
 c = b + 3;
 Serial.println(c);
 d = c - 10;
 Serial.println(d);

 delay(1000);

}
