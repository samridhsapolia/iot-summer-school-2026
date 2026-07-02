# PWM Fading Night Light

## Project Description
This project implements an automatic night light using Arduino UNO. The LED brightness is controlled using PWM to create a breathing effect. A push button switches between three lighting modes: Slow Breathing, Fast Pulse, and SOS Pattern. The current mode is displayed on the Serial Monitor.

## Hardware Required
- Arduino UNO
- LED
- 220Ω Resistor
- Push Button
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| LED | D9 (PWM) |
| Push Button | D2 |
| LED Cathode | GND |
| Button Other Terminal | GND |

## Working
- Mode 1: LED fades in and out slowly.
- Mode 2: LED blinks rapidly.
- Mode 3: LED flashes SOS (... --- ...) pattern.
- Each press of the push button changes to the next mode.
- The current mode is displayed on the Serial Monitor.

## Expected Output
The LED starts in Slow Breathing mode. Pressing the button cycles through Fast Pulse mode and SOS mode before returning to Slow Breathing mode.

## Files
- pwm_night_light.ino
- README.md
