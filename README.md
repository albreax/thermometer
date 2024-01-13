# ESP8266 Temperature Sensor MQTT Client

## Overview

This C++ program is tailored for the ESP8266 microcontroller, enabling it to read temperature data from a Dallas Temperature sensor and publish it to an MQTT topic. This functionality is especially useful in IoT applications for remote temperature monitoring.

## Hardware Requirements

- **ESP8266 WiFi Module:** A microcontroller module with WiFi capabilities.
- **Dallas Temperature Sensor:** For example, the DS18B20 sensor.

## Software Libraries

- **OneWire.h:** For Dallas Temperature sensor communication.

- **DallasTemperature.h:** For interfacing with the Dallas Temperature sensors.
- **ESP8266WiFi.h:** For handling WiFi functionalities of ESP8266.
- **PubSubClient.h:** For MQTT communication.

## Configuration

The configuration details are stored in a separate file `config.h`, which needs to contain the following information:

- `WIFI_SSID`: Your WiFi network's SSID.
- `WIFI_PASSWORD`: Your WiFi network's password.
- `MQTT_HOST`: The MQTT broker's hostname or IP address.
- `MQTT_PORT`: The port number for the MQTT broker (commonly 1883).
- `MQTT_ID`: A unique identifier for the MQTT client connection.
- `MQTT_TOPIC`: The MQTT topic where the temperature data will be published.

## Usage

1. Configure `config.h` with appropriate WiFi and MQTT settings.
2. Compile and upload the code to an ESP8266 module.
3. The module will connect to the WiFi network and MQTT broker, then start sending temperature data to the specified MQTT topic.

## Reading Values from the MQTT Broker

To read the temperature values published by the ESP8266, you'll need an MQTT client that subscribes to the same topic. The MQTT client can be a separate microcontroller, or a computer running an MQTT client program.

## Reading Values from the MQTT Broker

To read the temperature values published by the ESP8266, a simple cURL command can be used to request data from the MQTT broker. This method assumes the MQTT broker has an HTTP interface available.

### Example: cURL Command

```bash
curl http://[MQTT_BROKER_HTTP_INTERFACE]/[MQTT_TOPIC]

