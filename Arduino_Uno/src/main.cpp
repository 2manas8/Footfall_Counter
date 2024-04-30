#include <Arduino.h>
#include <TFT.h>  
#include <SPI.h>

int count = 0;

const int cs = 10;
const int dc = 9;
const int rst = 8;
TFT lcd = TFT(cs, dc, rst);
bool reset = 0;

const int buzzer = 2;
const int led = 3;
const int ldr = 4;
const int esp = 5;
const int updating = 6;
const int wifiConnection = 7;

unsigned long previousMillis = 0;
const int interval = 5000;

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
  lcd.fillScreen(0xFFFF);
  reset = 1;
  lcd.text("Welcome", 42, 40);
  lcd.text("dear", 60, 60);
  lcd.text("customer!", 30, 80);
}

void wifiCheck() {
  lcd.fillScreen(0xFFFF);
  reset = 0;
  lcd.text("Connecting", 23, 50);
  int temp = 68;
  while(digitalRead(wifiConnection) == LOW) {
    if(temp > 82) {
      lcd.fillRect(0, 70, 160, 20, 0xFFFF);
      temp = 68;
    }
    lcd.text(".", temp, 70);
    temp += 7;
    delay(1000);
  }
}

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  pinMode(ldr, INPUT);
  pinMode(esp, OUTPUT);
  digitalWrite(esp, LOW);
  pinMode(updating, INPUT);
  pinMode(wifiConnection, INPUT);
  lcd.begin();
  lcd.stroke(0, 0, 0);
  lcd.setTextSize(2);
  if(digitalRead(wifiConnection) == LOW) {
    wifiCheck();
  }
  greet();
}

void loop() {
  if(digitalRead(wifiConnection) == LOW) {
    wifiCheck();
  }
  unsigned long currentMillis = millis();
  // if(digitalRead(ldr) == HIGH) {
  //   previousMillis = currentMillis;
  //   reset = 0;
  //   count++;
  //   lcd.fillScreen(0xFFFF);
  //   lcd.setTextSize(1);
  //   lcd.text("Current Footfall:", 35, 52);
  //   lcd.setTextSize(2);
  //   lcd.text(String(count).c_str(), xAxis(), 68);
  //   digitalWrite(buzzer, HIGH);
  //   delay(100);
  //   digitalWrite(buzzer, LOW);
  //   digitalWrite(esp, HIGH);
  //   delay(100);
  //   digitalWrite(esp, LOW);
  //   while(digitalRead(updating) == HIGH) {
  //     if(currentMillis - previousMillis >= interval) {
  //       previousMillis = currentMillis;
  //       greet();
  //     }
  //   }
  // }
  if((currentMillis - previousMillis >= interval) && (!reset)) {
    previousMillis = currentMillis;
    reset = 1;
    greet();
  }
}