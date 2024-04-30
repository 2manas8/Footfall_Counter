<<<<<<< HEAD
#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "Galaxy F23";
const char* password = "some_random@23";

const char* serverAddress = "YourServerIPAddress";
const int serverPort = 80;

const int led = D4;
const int countIncrease = D8;
const int wifi = D7;
const int uno = D6;

void sendSignalToServer() {
  WiFiClient client;
  if (!client.connect(serverAddress, serverPort)) {
    Serial.println("Connection failed");
    return;
  }
  client.print("GET /your-endpoint?signal=high HTTP/1.1\r\n");
  client.print("Host: ");
  client.println(serverAddress);
  client.println("Connection: close");
  client.println();
  delay(500);
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  client.stop();
}

void connectionCheck() {
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifi, LOW);
    delay(500);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
  }
  digitalWrite(led, LOW);
  digitalWrite(wifi, HIGH);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(countIncrease, INPUT);
  pinMode(wifi, OUTPUT);
  pinMode(uno, OUTPUT);
  digitalWrite(uno, LOW);
  WiFi.begin(ssid, password);
  connectionCheck();
}

void loop() {
  connectionCheck();
  // if(digitalRead(countIncrease) == HIGH) {
  //   digitalWrite(uno, HIGH);
  //   sendSignalToServer();
  //   digitalWrite(uno, LOW);
  // }
}
=======
#include <Arduino.h>
#include <ESP8266WiFi.h>

const char* ssid = "Galaxy F23";
const char* password = "some_random@23";

const char* serverAddress = "YourServerIPAddress";
const int serverPort = 80;

const int led = D4;
const int countIncrease = D8;
const int wifi = D7;
const int uno = D6;

void sendSignalToServer() {
  WiFiClient client;
  if (!client.connect(serverAddress, serverPort)) {
    Serial.println("Connection failed");
    return;
  }
  client.print("GET /your-endpoint?signal=high HTTP/1.1\r\n");
  client.print("Host: ");
  client.println(serverAddress);
  client.println("Connection: close");
  client.println();
  delay(500);
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  client.stop();
}

void connectionCheck() {
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifi, LOW);
    delay(500);
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
  }
  digitalWrite(led, LOW);
  digitalWrite(wifi, HIGH);
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(countIncrease, INPUT);
  pinMode(wifi, OUTPUT);
  pinMode(uno, OUTPUT);
  digitalWrite(uno, LOW);
  WiFi.begin(ssid, password);
  connectionCheck();
}

void loop() {
  connectionCheck();
  // if(digitalRead(countIncrease) == HIGH) {
  //   digitalWrite(uno, HIGH);
  //   sendSignalToServer();
  //   digitalWrite(uno, LOW);
  // }
}
>>>>>>> 3d039c4 (Added the Android app)
