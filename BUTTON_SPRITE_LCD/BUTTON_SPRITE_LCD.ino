#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 2, 3, 4, 5); 

const int lcd_width= 16;

const int left_btn= 8; 
const int right_btn= 9;

int left_btn_state= HIGH; 
int left_btn_prev= HIGH; 

int right_btn_state= HIGH; 
int right_btn_p= HIGH; 

const int debounce_delay= 50; 

unsigned long left_last_debounce_time = 0;
unsigned long right_last_debounce_time = 0;

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

int position =0; 

void setup() { 
  
  pinMode(left_btn, INPUT_PULLUP);
  pinMode(right_btn, INPUT_PULLUP);
  
  lcd.begin(16, 2); 
  lcd.clear(); 
  
  lcd.createChar(0, armsDown); 
  
} 

void loop() { 
  
  int left_btn_read = digitalRead(left_btn);
  int right_btn_read = digitalRead(right_btn);
  
  if(left_btn_read != left_btn_prev) { 
    left_last_debounce_time = millis(); 
  } 
  
  if( millis() > ( left_last_debounce_time + debounce_delay) ) { 
    if (left_btn_read != left_btn_state) { 
      left_btn_state = left_btn_read; 
      if( left_btn_state == LOW ) { 
        position--; 
        if (position < 0){ 
          position = 0; 
        } 
      } 
    } 
  } 
  left_btn_prev = left_btn_read;
  
  
  
 
  
  if(right_btn_read != right_btn_read) { 
    right_last_debounce_time = millis(); 
  } 
  
  if( millis() > ( right_last_debounce_time + debounce_delay) ) { 
    if (right_btn_read != right_btn_state) { 
      right_btn_state = right_btn_read; 
      if( right_btn_state == LOW ) { 
        position++; 
        if (position > lcd_width){ 
          position = lcd_width; 
        } 
      } 
    } 
  } 
  right_btn_read = right_btn_read;
  
  lcd.clear(); 
  lcd.setCursor(position, 1); 
  lcd.write(byte(0)); 
  
  delay(20); 
  
} 





