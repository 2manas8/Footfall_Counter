#include <Arduino.h>
#include <TFT.h>  
#include <SPI.h>

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
const int resetButton = 12;
const int rightButton = 1;
const int leftButton = 0;

unsigned long previousMillis = 0;
const int interval = 5000;

String days[7] = {"MON", "TUES", "WED", "THURS", "FRI", "SAT", "SUN"};
int daysCount[7] = {0};
bool prev[7] = {0};
int daysIndex = 0;

bool pass = 0;
bool buttonPress = 0;
bool right = 0;
bool left = 0;

uint16_t daysColor() {
  switch(daysIndex) {
    case 0:
    return 0xCAFB;
    case 1:
    return 0xEE90;
    case 2:
    return 0xADE6;
    case 3:
    return 0xBFE0;
    case 4:
    return 0x80FA;
    case 5:
    return 0x40B9;
    case 6:
    return 0x90C1;
    default:
    return 0xFFFF;
  }
}

void leftClick() {
  previousMillis = millis();
  daysIndex--;
  if(daysIndex < 0) {
    daysIndex = 6;
  }
  lcd.fillRect(0, 0, 160, 40, daysColor());
  lcd.setTextSize(2);
  lcd.text(("Day: " + days[daysIndex]).c_str(), 10, 13);
  return;
}

void rightClick() {
  previousMillis = millis();
  daysIndex++;
  if(daysIndex > 6) {
    daysIndex = 0;
  }
  lcd.fillRect(0, 0, 160, 40, daysColor());
  lcd.setTextSize(2);
  lcd.text(("Day: " + days[daysIndex]).c_str(), 10, 13);
  return;
}

int xAxis() {
  if((daysCount[daysIndex] >= 0) && (daysCount[daysIndex] <= 9)) {
    return 77;
  } else if((daysCount[daysIndex] >= 10) && (daysCount[daysIndex] <= 99)) {
    return 70;
  } else if((daysCount[daysIndex] >= 100) && (daysCount[daysIndex] <= 999)) {
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

void countScreen() {
  previousMillis = millis();
  lcd.fillScreen(0xFFFF);
  lcd.fillRect(0, 0, 160, 40, daysColor());
  lcd.setTextSize(2);
  lcd.text(("Day: " + days[daysIndex]).c_str(), 10, 13);
  lcd.setTextSize(1);
  lcd.text("Current Footfall:", 35, 72);
  lcd.setTextSize(2);
  lcd.text(String(daysCount[daysIndex]).c_str(), xAxis(), 88);
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
  pinMode(rightButton, INPUT);
  pinMode(leftButton, INPUT);
  pinMode(resetButton, INPUT);
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
  // if(digitalRead(resetButton == HIGH)) {
  //   daysCount[daysIndex] = 0;
  // }
  // if(digitalRead(rightButton) == HIGH) {
  //   rightClick();
  // } else if(digitalRead(leftButton) == HIGH) {
  //   leftClick();
  // }
  unsigned long currentMillis = millis();
  if((digitalRead(ldr) == LOW) && (!pass)) {
    previousMillis = millis();
    reset = 0;
    pass = 1;
    daysCount[daysIndex]++;
    countScreen();
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    digitalWrite(esp, HIGH);
    delay(100);
    digitalWrite(esp, LOW);
    while(digitalRead(updating) == HIGH) {
      if(currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        greet();
      }
    }
  }
  if(digitalRead(ldr) == HIGH) {
    pass = 0;
  }
  if((currentMillis - previousMillis >= interval) && (!reset)) {
    previousMillis = currentMillis;
    reset = 1;
    greet();
  }
}