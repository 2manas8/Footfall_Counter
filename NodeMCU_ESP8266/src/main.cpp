#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Firebase.h>

#define FIREBASE_HOST "https://footfalldata-d6dde-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "f09662b55385ff50da29ab3edf5cb3d6267f8c79"

const char* ssid = "NSUT_WIFI";
const char* password = "";

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

void sendDataToFirebase() {
  
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
  connectionCheck();
  // config.api_key = FIREBASE_AUTH;
  // config.database_url = FIREBASE_HOST;
  // if(Firebase.signUp(&config, &auth, "", "")) {
  //   Serial.print("Sign Up OK");
  // } else {
  //   Serial.print("Sign Up Failed");
  // }
 }

void loop() {
  connectionCheck();
  // if(digitalRead(countIncrease) == HIGH) {
  //   digitalWrite(uno, HIGH);
  //   sendSignalToServer();
  //   digitalWrite(uno, LOW);
  // }
}