# Thermometer

## Description

Provides a Rest endpoint to read the temperature from a DS18B20 sensor.

## Hardware

- D1 Mini V3 NodeMCU ESP8266EX WLAN WIFI Module
<https://www.az-delivery.de/en/products/d1-mini-v3>
- DS18B20 Temperatursensor

## Prerequisites

- Arduino IDE with ESP8266 board package installed.
- Required libraries:
  - OneWire
  - DallasTemperature
  - ESP8266WiFi
  - ESP8266WebServer

## VSCode

The project is developed using VSCode with the Plaformio extension.

## Configuration

Rename `config.h.example` to `config.h` and adjust the settings.

## Hardware setup

Connect the DS18B20 sensor to the D1 Mini as follows:

// TODO: add shematic

## Usage

- Compile and upload the code to the D1 Mini.

You can now read the temperature from the sensor using the following endpoint:

<htto://ip-address/>

OR

<htto://DNS-NAME.local/>

> DNS_NAME is the name you configured in the config.h file.