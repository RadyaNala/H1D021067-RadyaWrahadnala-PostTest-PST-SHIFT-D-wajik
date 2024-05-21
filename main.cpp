#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

// put function declarations here:
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D4;
int SCL_pin = D5;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(D3);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
  for(int pos = 0; pos <= 90; pos += 15){
    myservo.write(pos);
    delay(10);
    if(pos == 90){
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("pintu terbuka");
    }
    
  }
  for(int pos = 90; pos >= 0; pos -= 15){
    myservo.write(pos);
    delay(10);
    if(pos == 0){
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("pintu tertutup");
    }
  }
} 

