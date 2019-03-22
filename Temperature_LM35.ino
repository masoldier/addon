/* Arduino code for displaying LM35 
Temprature sensor reading on an 16x2 LCD display */

//Connect out pin of LM35 to A0 pin of Arduino

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 8, 7, 4, 2);

int Temp;
void setup() {
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  
}

void loop() {
  Temp = analogRead(A0);
  lcd.clear();
  lcd.setCursor(0, 0);
  
float mv = ( Temp/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
lcd.print("TEMPERATURE");
lcd.setCursor(0,1);
lcd.print(cel);
lcd.print("*c");
lcd.setCursor(9,1);
lcd.print(farh);
lcd.print("*F");
lcd.setCursor(0,0);
Serial.println();
delay(1000);


}