# Q30. I2C Protocol

## What is I2C?

I2C (Inter-Integrated Circuit) is a two-wire serial communication protocol used for communication between a microcontroller and multiple sensors or peripheral devices.

---

## SDA Line

SDA (Serial Data Line) is used to transfer data between the master and slave devices.

**Arduino UNO Pin:** A4

---

## SCL Line

SCL (Serial Clock Line) provides the clock signal that synchronizes communication between devices.

**Arduino UNO Pin:** A5

---

## I2C Addressing

Each I2C device has a unique address.

The master device (Arduino) sends the address of the required slave device before data communication begins. Only the addressed device responds, allowing multiple devices to share the same SDA and SCL lines.

---

## Common IoT Sensors Using I2C

1. BMP280 (Temperature and Pressure Sensor)
2. MPU6050 (Accelerometer and Gyroscope)
3. BH1750 (Light Intensity Sensor)

---

## Advantages of I2C

- Requires only two communication wires (SDA and SCL).
- Supports multiple devices on the same bus.
- Simple and efficient communication.
- Reduces wiring complexity in IoT systems.
