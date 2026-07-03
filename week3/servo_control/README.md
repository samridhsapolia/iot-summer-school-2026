# Servo Motor Sweep

## Project Description

This project controls a Micro Servo (SG90 equivalent in Tinkercad) using a potentiometer. The potentiometer position is mapped from 0–1023 to a servo angle of 0°–180°. A push button performs one complete automatic sweep from 0° to 180° and back to 0°. The current servo angle is displayed on the Serial Monitor.

---

## Hardware Required

- Arduino UNO
- Micro Servo (SG90 equivalent)
- 10kΩ Potentiometer
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | D9 |
| Servo VCC | 5V |
| Servo GND | GND |
| Potentiometer Middle Pin | A0 |
| Potentiometer Left Pin | GND |
| Potentiometer Right Pin | 5V |
| Push Button | D2 (INPUT_PULLUP) |

---

## Working

- Rotating the potentiometer controls the servo angle between 0° and 180°.
- The current angle is displayed on the Serial Monitor.
- Pressing the push button performs one complete sweep:
  - 0° → 180°
  - 180° → 0°

---

## Expected Output

- Servo follows the potentiometer position.
- Serial Monitor displays the servo angle.
- Button press triggers one complete automatic sweep.

---

## Code Location

week3/servo_control/servo_control.ino
