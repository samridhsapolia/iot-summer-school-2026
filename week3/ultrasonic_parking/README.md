# Ultrasonic Parking Sensor

## Project Description
This project implements an ultrasonic parking assistance system using the HC-SR04 sensor. The system measures the distance to an object and provides visual and audio alerts based on how close the object is.

## Hardware Required
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Piezo Buzzer
- Red LED
- Yellow LED
- 2 × 220Ω Resistors
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Yellow LED | D6 |
| Red LED | D7 |
| Piezo Buzzer | D8 |

## Distance Calculation

distance = (duration × 0.034) / 2

## Working

- Distance > 50 cm:
  - SAFE message displayed
  - No LED or buzzer

- Distance 20–50 cm:
  - Yellow LED ON
  - Buzzer beeps every 500 ms

- Distance 10–20 cm:
  - Red LED ON
  - Buzzer beeps every 200 ms

- Distance < 10 cm:
  - Red and Yellow LEDs flash rapidly
  - Continuous buzzer

## Features
- Distance measurement using HC-SR04
- LED warning system
- Buzzer alert system
- Serial Monitor output
- Non-blocking timing using millis()
