const int POT =0;
int val =0; // Variable that holds analog reading from POT

void setup()
{
 Serial.begin(9600);

}

void loop() {
    val = analogRead(POT);
    Serial.println(val);
    delay(500);
   }
