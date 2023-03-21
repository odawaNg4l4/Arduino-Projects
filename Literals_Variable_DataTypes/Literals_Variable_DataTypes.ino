//Literals, variables, data types
int a = 32;
char b = 'R';
void setup()
{
    Serial.begin(9600);
}
void loop()
{
  Serial.print(a);
  Serial.println(b);

  delay (1000);
}
