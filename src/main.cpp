#include "config.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// read ssid, password from config.h
const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;
const char* mqttHost = MQTT_HOST;
const int mqttPort = MQTT_PORT;
const char* mqttId = MQTT_ID;
const char* mqttTopic = MQTT_TOPIC;

WiFiClient espClient;
PubSubClient client(espClient);

void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Waiting for connection...");
  }
  Serial.println("Connected to WiFi");
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    if (client.connect(mqttId)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  sensors.begin();

  connectToWiFi();
  client.setServer(mqttHost, mqttPort);
}

void loop() {
  if (!client.connected()) {
    connectToMQTT();
  }

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  client.publish(mqttTopic, String(temp).c_str());

  delay(10000); // Publish temperature every 10 seconds
}
