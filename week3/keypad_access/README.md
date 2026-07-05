# Keypad + LCD Password Protected Access System

## Project Description

This project implements a password-protected access system using a 4×4 keypad and a 16×2 I2C LCD. The LCD prompts the user to enter a 4-digit PIN. If the entered PIN is correct, access is granted, the green LED turns on, and the buzzer beeps. If the PIN is incorrect, access is denied, the red LED turns on, and the buzzer sounds. After three incorrect attempts, the system locks for 10 seconds.

---

## Hardware Required

- Arduino UNO
- 4×4 Keypad
- 16×2 I2C LCD
- Green LED
- Red LED
- Passive Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| LCD SDA | A4 |
| LCD SCL | A5 |
| Keypad Rows | D9, D8, D7, D6 |
| Keypad Columns | D5, D4, D3, D2 |
| Green LED | D10 |
| Red LED | D11 |
| Passive Buzzer | D12 |

---

## Working

- LCD displays **ENTER PIN:**
- User enters a 4-digit password using the keypad.
- Correct PIN displays **ACCESS GRANTED**, turns ON the green LED, and activates the buzzer.
- Wrong PIN displays **ACCESS DENIED**, turns ON the red LED, and activates the buzzer.
- After three incorrect attempts, the system locks for 10 seconds before accepting another PIN.

---

## Features

- Password authentication
- Green LED for successful access
- Red LED for failed access
- Passive buzzer indication
- 10-second security lock after three failed attempts

---

## Expected Output

### Correct PIN
```
ACCESS
GRANTED
```

### Wrong PIN
```
ACCESS
DENIED
```

### Three Wrong Attempts
```
LOCKED
10 Seconds
```
