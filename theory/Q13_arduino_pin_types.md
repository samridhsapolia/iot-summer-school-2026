# Q13. Arduino Pin Types

## 1. Digital Input

Digital input pins read HIGH or LOW signals from external devices.

**Example:** Push Button

**IoT Use Case:** Detecting door open/close status in a smart home.

---

## 2. Digital Output

Digital output pins send HIGH or LOW signals to control devices.

**Example:** LED

**IoT Use Case:** Turning a relay ON/OFF to control home appliances.

---

## 3. Analog Input

Analog input pins measure varying voltage levels (0–5V).

**Example:** LDR (Light Sensor)

**IoT Use Case:** Measuring ambient light for automatic street lights.

---

## 4. PWM Output

PWM (Pulse Width Modulation) pins simulate analog output by varying duty cycle.

**Example:** Servo Motor or LED Brightness Control

**IoT Use Case:** Controlling motor speed or LED brightness.

---

## 5. I2C / SPI Pins

### I2C Pins

- SDA → A4
- SCL → A5

**Example Device:** LCD, BMP280 Sensor

**IoT Use Case:** Connecting multiple sensors using only two wires.

### SPI Pins

- MOSI → D11
- MISO → D12
- SCK → D13
- SS → D10

**Example Device:** SD Card Module

**IoT Use Case:** High-speed communication with memory cards and displays.
