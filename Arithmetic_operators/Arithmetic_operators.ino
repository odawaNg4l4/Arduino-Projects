//BASIC BODMAS
int a;
int b;
int c;
int d;
int e;


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
 e = d % 7;
 Serial.print(e);

 delay(1000);
}

/*BODMAS
int a;

void setup()
{
  Serial.begin(9600);
      a = 10 /2 + (18 - 10) % 7 * 4;
   Serial.print(a);
}

void loop()
{

}*/
