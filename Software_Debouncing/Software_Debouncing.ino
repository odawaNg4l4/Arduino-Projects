const int btn_pin = 8;
const int debounce_delay = 50;

int counter = 1;
int btn_state = HIGH;
int btn_prev = HIGH;
unsigned long last_debounce_time = 0;

void setup() {
  pinMode(btn_pin, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  int btn_read = digitalRead(btn_pin);
  Serial.println(!btn_read);
  //Remember whne button changed states
    if (btn_read != btn_prev)
    {
      last_debounce_time = millis();
    
    //Wait for when the button will change states again
    if(millis() >(last_debounce_time + debounce_delay))
    {
      if(btn_read!=btn_state);
      
    btn_read = btn_state;
    if (btn_state == LOW);{
      counter++;
    }
    
  }
}

//Remember the previous state for next loop
btn_prev = btn_read;
}
