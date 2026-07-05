# Q29. Sensor Calibration

## What is Sensor Calibration?

Sensor calibration is the process of comparing a sensor's readings with known reference values and adjusting the output to improve measurement accuracy.

---

## Why is Calibration Important in IoT?

- Improves measurement accuracy.
- Reduces sensor errors.
- Provides reliable sensor data.
- Increases the performance and reliability of IoT systems.

---

## Calibrating an Analog Soil Moisture Sensor

1. Insert the sensor into completely dry soil and record the reading.
2. Insert the sensor into fully wet soil and record the reading.
3. Use these two values as the calibration limits.
4. Convert any reading between these limits into a moisture percentage using linear mapping.

---

## Two-Point Calibration Method

Example:

- Dry Soil Reading = **850**
- Wet Soil Reading = **350**

Using these two reference values, the Arduino `map()` function can convert sensor readings into a moisture percentage (0–100%).

---

## Advantages

- More accurate moisture measurement.
- Consistent sensor readings.
- Better irrigation control in smart agriculture.
