# DC Motor Speed Control

## Project Description

This project controls a DC motor using an H-Bridge motor driver (L293D used in Tinkercad as an equivalent to L298N). The motor speed is controlled using a potentiometer, one push button changes the motor direction, and another button starts or stops the motor. The Serial Monitor displays the motor direction, speed percentage, and current state.

---

## Hardware Required

- Arduino UNO
- L293D Motor Driver IC (equivalent to L298N for simulation)
- DC Motor
- 10kΩ Potentiometer
- 2 Push Buttons
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Enable (PWM) | D9 |
| IN1 | D8 |
| IN2 | D7 |
| Potentiometer | A0 |
| Direction Button | D2 |
| Start/Stop Button | D3 |

---

## Working

- Potentiometer controls the motor speed (PWM 0–255).
- Direction button toggles the motor between Forward and Reverse.
- Start/Stop button starts or stops the motor.
- Serial Monitor displays:
  - Direction
  - Speed (0–100%)
  - Motor State

---

## Note

The assignment specifies an L298N motor driver. Since Tinkercad does not provide an L298N module, an L293D H-Bridge IC was used as an equivalent motor driver for simulation.
