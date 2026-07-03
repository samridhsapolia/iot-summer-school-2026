# Smart Street Light Controller

## Project Description

This project implements an intelligent street light controller using an Arduino UNO, Photoresistor (LDR), and PIR Motion Sensor. The system automatically turns the street light OFF during daylight, detects motion at night, and adjusts LED brightness using PWM.

---

## Hardware Required

- Arduino UNO
- Photoresistor (LDR)
- PIR Motion Sensor
- Red LED
- 220Ω Resistor
- 10kΩ Resistor
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| LDR | A0 |
| PIR Sensor | D2 |
| LED | D9 |

---

## Working

- During daylight, the LED remains OFF.
- At night, motion detection is enabled.
- If motion is detected, the LED turns ON at full brightness.
- If no motion is detected for 30 seconds, the LED dims to approximately 20% brightness using PWM.
- Events are displayed on the Serial Monitor with timestamps.

---

## Features

- Automatic day/night detection
- Motion-based street light control
- PWM dimming
- Event logging
- 30-second timer using millis()
