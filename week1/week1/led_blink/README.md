# LED Blink Project

## Project Title
LED Blink using Arduino UNO

## Hardware Required
- Arduino UNO
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires
- USB Cable

## Circuit Diagram Description
The LED anode (long leg) is connected to Arduino digital pin 13 through a 220Ω resistor.
The LED cathode (short leg) is connected to GND.
The Arduino is powered through the USB cable.

## How to Upload Code
1. Connect Arduino UNO to the computer.
2. Open Arduino IDE.
3. Select **Arduino UNO** from Tools → Board.
4. Select the correct COM Port.
5. Open `led_blink.ino`.
6. Click Verify.
7. Click Upload.
8. Wait for "Done Uploading".

## Expected Output
The LED connected to pin 13 blinks every 500 milliseconds.

## Troubleshooting Tips
- Check the COM Port.
- Verify LED polarity.
- Select the correct board.
- Check wiring connections.
- Re-upload the sketch if upload fails.
