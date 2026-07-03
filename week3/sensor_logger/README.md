# Multi-Sensor Data Logger

## Project Description

This project reads data from three sensors simultaneously and displays the information on the Serial Monitor every 5 seconds in a structured format.

## Hardware Required

- Arduino UNO
- DHT22 Sensor (used as Wokwi simulation for DHT11)
- HC-SR04 Ultrasonic Sensor
- LDR Sensor Module
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 DATA | D2 |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| LDR AO | A0 |

## Output Format

```
=== SENSOR LOG ===
Time      : xxxx ms
Temp      : xx.x C | Humidity: xx%
Light     : xx% (Bright/Normal/Dark)
Distance  : xx cm
==================
```

## Features

- Temperature measurement
- Humidity measurement
- Light intensity measurement
- Distance measurement
- Structured Serial Monitor logging every 5 seconds

## Note

A DHT22 sensor is used in Wokwi as a simulation substitute for the DHT11 sensor mentioned in the assignment.
