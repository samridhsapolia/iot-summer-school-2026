# Vending Machine State Machine

## Project Description
This project simulates a vending machine using a finite state machine (FSM). Three push buttons are used to insert a coin, select an item, and cancel the operation. LEDs indicate the current state, and all state transitions are displayed on the Serial Monitor.

## Hardware Required
- Arduino UNO
- Breadboard
- 3 LEDs
- 3 × 220Ω Resistors
- 3 Push Buttons
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Red LED (IDLE) | D8 |
| Yellow LED (COIN_INSERTED) | D9 |
| Green LED (ITEM_SELECTED) | D10 |
| Insert Coin Button | D2 |
| Select Item Button | D3 |
| Cancel Button | D4 |

## State Diagram

IDLE → COIN_INSERTED → ITEM_SELECTED → DISPENSING → IDLE

The Cancel button returns the machine to the IDLE state from COIN_INSERTED or ITEM_SELECTED.

## Features
- Finite State Machine implementation
- LED indication for each state
- Serial Monitor state transition logging
- Cancel operation

## Expected Output
The vending machine transitions between states based on button presses. LEDs indicate the current state, and the Serial Monitor logs each transition.
