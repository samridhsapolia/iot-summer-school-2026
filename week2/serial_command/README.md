# Serial Command Interface

## Project Description
This project demonstrates serial communication between the Arduino UNO and a computer using the Serial Monitor. Users can control the built-in LED by sending text commands.

## Hardware Required
- Arduino UNO
- USB Cable
- Built-in LED (Pin 13)

## Supported Commands

| Command | Function |
|---------|----------|
| LED_ON | Turns the built-in LED ON |
| LED_OFF | Turns the built-in LED OFF |
| BLINK_X | Blinks the LED X times (1–9) |
| STATUS | Displays LED state and blink counter |
| RESET | Resets the blink counter |

## Features
- Serial command processing
- Input validation
- Blink counter
- Error handling for invalid commands

## Expected Output
The Arduino receives commands from the Serial Monitor and performs the requested action while displaying status messages.


