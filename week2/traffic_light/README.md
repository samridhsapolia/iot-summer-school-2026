# Traffic Light Controller

## Project Description
This project simulates a traffic light system using Arduino UNO. It controls Red, Yellow, and Green LEDs and includes a pedestrian push button. When the button is pressed, the traffic light immediately switches to Red for 8 seconds before resuming the normal sequence.

## Hardware Required
- Arduino UNO
- Breadboard
- Red LED
- Yellow LED
- Green LED
- 3 × 220Ω Resistors
- Push Button
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Red LED | D13 |
| Yellow LED | D12 |
| Green LED | D11 |
| Push Button | D7 |
| GND | Push Button (using INPUT_PULLUP) |

## Working
- Red LED ON for 5 seconds
- Yellow LED ON for 2 seconds
- Green LED ON for 4 seconds
- Pressing the push button immediately switches to Red for 8 seconds.
- The current light state and timestamp are displayed on the Serial Monitor.

## Expected Output
The traffic lights cycle automatically. When the pedestrian button is pressed, Red turns ON immediately for 8 seconds before the normal sequence continues.

## Folder Structure

```
week2/
└── traffic_light/
    ├── traffic_light.ino
    └── README.md
```
