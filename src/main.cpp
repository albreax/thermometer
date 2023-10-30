#include "config.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define ONE_WIRE_BUS D2

OneWire oneWire(4); // use GPIO number for pin D2
DallasTemperature sensors(&oneWire);

// read ssid, password from config.h
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* dnsName = DNS_NAME;

ESP8266WebServer server(80); //Server on port 80

void setupWebServer() {
  server.on("/", HTTP_GET, []() {
    sensors.requestTemperatures();
    float temp = sensors.getTempCByIndex(0);
    String tempStr = String(temp);
    server.send(200, "text/plain", tempStr);
  });

  server.begin();
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  // start mDNS-Responder
  if (MDNS.begin(dnsName)) {
      Serial.println("MDNS responder started");
  }

  sensors.begin();
  setupWebServer();
}

void loop() {
  server.handleClient();
  MDNS.update();  // Important for mDNS-Responder
}

