#include <ESP8266WebServer.h>//ketab khane web server
#include <ESP8266WiFi.h>
#include <WiFiClient.h>//hlat client ezafe kardan

const char *ssid = "asdfghl";
const char *password = "1234567890";
ESP8266WebServer server(80);

void handleRoot(){
  server.send(200,"text/html","<h1>You are connected</h1>");
}

void setup() {
  // put your setup code here, to run once:

delay(1000);
Serial.begin(9600);
Serial.println("configuration access point ....");
WiFi.softAP(ssid,password);
IPAddress myIp = WiFi.softAPIP();
Serial.print("AP Ip address :");
Serial.print(myIp);
server.on("/",handleRoot);
server.begin();
Serial.println("HTTP server started");

}

void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}
