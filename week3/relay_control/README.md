# Relay-Controlled AC Device Simulation

## Project Description

This project simulates an AC appliance using a relay module and an LED. A DHT22 sensor (used as a substitute for DHT11 in Wokwi) monitors the temperature. The relay turns ON when the temperature rises above 32°C and turns OFF when the temperature falls below 28°C (hysteresis). A push button is used for manual override. Relay state changes and temperature readings are displayed on the Serial Monitor.

---

## Hardware Required

- Arduino UNO
- DHT22 Sensor
- Relay Module
- LED
- 220Ω Resistor
- Push Button
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT22 DATA | D2 |
| Relay IN | D8 |
| Push Button | D3 |
| DHT22 VCC | 5V |
| DHT22 GND | GND |
| Relay VCC | 5V |
| Relay GND | GND |

### Relay Contact Wiring

| Relay Terminal | Connection |
|---------------|------------|
| COM | 5V |
| NO | LED Anode (+) |
| LED Cathode | 220Ω Resistor → GND |

---

## Working

- Relay turns ON when temperature is greater than **32°C**.
- Relay turns OFF when temperature is below **28°C**.
- Hysteresis prevents rapid switching.
- Manual override is available through a push button.
- Temperature and relay status are displayed on the Serial Monitor.

---

## Expected Output

Temperature: 35°C

```
Temperature: 35.0 C | Relay ON
```

Temperature: 26°C

```
Temperature: 26.0 C | Relay OFF
```

Manual Override

```
Manual Override: ON
```

or

```
Manual Override: OFF
```

---

## Note

Wokwi uses a DHT22 sensor instead of DHT11. The DHT22 was used as an equivalent sensor for simulation.
