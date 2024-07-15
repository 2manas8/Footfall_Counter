#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Galaxy F23";
const char* password = "some_random@23";

const char* serverAddress = "https://securitycounterdata.onrender.com/fetchData?MACAddress=1";

const int led = D4;
const int countIncrease = D8;
const int wifi = D7;
const int uno = D6;

ESP8266WebServer server(80);

void callAPI(String url) {
  std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
  client->setInsecure();
  HTTPClient https;
  https.begin(*client, url);
  https.GET();
  https.end();
  return;
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
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(countIncrease, INPUT);
  pinMode(wifi, OUTPUT);
  pinMode(uno, OUTPUT);
  digitalWrite(uno, LOW);
  WiFi.begin(ssid, password);
 }

void loop() {
  connectionCheck();
  if(digitalRead(countIncrease) == HIGH) {
    digitalWrite(uno, HIGH);
    callAPI(serverAddress);
    digitalWrite(uno, LOW);
  }
}