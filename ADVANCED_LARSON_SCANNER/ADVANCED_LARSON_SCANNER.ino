const int led1pin = 3;
const int led2pin = 5;
const int led3pin = 6;
const int led4pin = 9;
const int led5pin = 10;
const int led6pin = 11;



void setup()
{
    pinMode(led1pin, OUTPUT);
    pinMode(led2pin, OUTPUT);
    pinMode(led3pin, OUTPUT);
    pinMode(led4pin, OUTPUT);
    pinMode(led5pin, OUTPUT);
    pinMode(led6pin, OUTPUT);
}

void loop()
{   
const int DUTY = 64;

 digitalWrite(led1pin,HIGH);
 delay(500);
 digitalWrite(led1pin,LOW);
  
 digitalWrite(led2pin,HIGH);
 delay(100);
 digitalWrite(led2pin,LOW);
 
 digitalWrite(led3pin,HIGH);
 delay(200);
 digitalWrite(led3pin,LOW);
 
 digitalWrite(led4pin,HIGH);
  delay(100);
 digitalWrite(led4pin,LOW);

 digitalWrite(led5pin,HIGH);
 delay(50);
 digitalWrite(led5pin,LOW);
 
 digitalWrite(led6pin,HIGH);
 delay(500);
 digitalWrite(led6pin,LOW);
  
  analogWrite( led1pin, DUTY );
  analogWrite( led2pin, DUTY );
  analogWrite( led3pin, DUTY );
  analogWrite( led4pin, DUTY );
  analogWrite( led5pin, DUTY );
  analogWrite( led6pin, DUTY );
  }
