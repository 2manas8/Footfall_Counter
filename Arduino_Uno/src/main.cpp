#include <Arduino.h>
#include <TFT.h>  
#include <SPI.h>

#define cs 10
#define dc 9
#define rst 8

int count = 0;

TFT lcd = TFT(cs, dc, rst);
int buzzer = 2;
int led = 3;
int ldr = 4;

int xAxis() {
  if((count >= 0) && (count <= 9)) {
    return 77;
  } else if((count >= 10) && (count <= 99)) {
    return 70;
  } else if((count >= 100) && (count <= 999)) {
    return 63;
  }
  return 54;
}

void greet() {
  lcd.background(255, 255, 255);
  lcd.text("Welcome", 42, 40);
  lcd.text("dear", 60, 60);
  lcd.text("customer!", 30, 80);
}

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  pinMode(ldr, INPUT);
  lcd.begin();
  lcd.stroke(0, 0, 0);
  lcd.setTextSize(2);
  greet();
}

void loop() {
  if(digitalRead(ldr) == HIGH) {
    count++;
    lcd.background(255, 255, 255);
    lcd.setTextSize(1);
    lcd.text("Current Footfall:", 30, 52);
    lcd.setTextSize(2);
    lcd.text(String(count).c_str(), xAxis(), 68);
    delay(5000);
    greet();
  }
}