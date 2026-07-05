# Q19. Difference Between analogWrite() and analogRead()

## analogRead()

- Reads an analog voltage from an analog input pin.
- Returns a value between **0 and 1023**.
- Used with sensors such as LDR, potentiometer, and soil moisture sensor.

**IoT Example:** Reading the light intensity from an LDR sensor for an automatic street light.

---

## analogWrite()

- Generates a **PWM (Pulse Width Modulation)** signal on PWM-enabled digital pins.
- Accepts values from **0 to 255**.
- Used to control LED brightness or motor speed.

**IoT Example:** Controlling the speed of a DC motor in a smart irrigation system.

---

## What is PWM?

PWM (Pulse Width Modulation) is a technique that simulates analog output by rapidly switching a digital signal ON and OFF with different duty cycles.

## Why is PWM Used?

- LED brightness control
- DC motor speed control
- Servo and actuator control
- Power-efficient output control

## Difference

| analogRead() | analogWrite() |
|---------------|---------------|
| Reads analog voltage | Generates PWM output |
| Input Function | Output Function |
| Value: 0–1023 | Value: 0–255 |
| Used with sensors | Used with LEDs and motors |
