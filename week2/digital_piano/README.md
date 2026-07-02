# Digital Piano using Arduino

## Project Description
A 4-key digital piano built using Arduino UNO and a piezo buzzer. Each button plays a musical note. Pressing two buttons together plays the Sol note (392 Hz). A fifth button switches between Major and Minor scales.

## Hardware Required
- Arduino UNO
- Breadboard
- Piezo Buzzer
- 5 Push Buttons
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Do Button | D2 |
| Re Button | D3 |
| Mi Button | D4 |
| Fa Button | D5 |
| Mode Button | D6 |
| Piezo Buzzer | D8 |

## Features
- Four musical notes (Do, Re, Mi, Fa)
- Sol note when two buttons are pressed
- Major/Minor scale toggle
- Sound stops when buttons are released

## Expected Output
Each button plays its assigned musical note. Pressing two buttons plays Sol (392 Hz). Pressing the mode button toggles between Major and Minor scales.
