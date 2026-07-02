# Environmental Monitoring Station

## Project Description
This project implements a simple environmental monitoring station using an Arduino UNO and a DHT22 sensor (used in Wokwi as a simulation substitute for DHT11). The system measures temperature and humidity every 2 seconds and prints the readings in CSV format on the Serial Monitor. LEDs indicate whether environmental conditions are normal or exceed predefined thresholds.

## Hardware Required
- Arduino UNO
- DHT22 Sensor (Simulation)
- Red LED
- Green LED
- 2 × 220Ω Resistors
- Breadboard
- Jumper Wires

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 DATA | D2 |
| Red LED | D8 |
| Green LED | D9 |

## Working
- Reads temperature (°C and °F) and humidity every 2 seconds.
- Prints data in CSV format:
  timestamp,temp_C,temp_F,humidity
- Red LED turns ON if:
  - Temperature > 35°C, or
  - Humidity > 80%
- Green LED turns ON when conditions are normal.

## Library
- DHT by Adafruit

## Note
The assignment specifies DHT11. This project uses a DHT22 sensor in Wokwi because it is the supported temperature and humidity sensor. The program logic remains the same.
