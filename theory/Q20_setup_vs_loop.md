# Q20. setup() and loop() Functions in Arduino

## setup()

- The `setup()` function runs **only once** when the Arduino is powered on or reset.
- It is used to initialize pins, sensors, communication, and libraries.

**Example:**

```cpp
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
```

---

## loop()

- The `loop()` function runs continuously after `setup()`.
- It contains the main program logic.

**Example:**

```cpp
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

---

## Effect of a Long delay() in loop()

A long `delay()` blocks the processor, preventing it from reading sensors or responding to events during the delay period.

### Effect on Sensor Responsiveness

- Slow sensor updates
- Delayed response to button presses
- Reduced real-time performance
- Poor responsiveness in IoT applications

---

## Non-Blocking Alternative

The recommended alternative is the `millis()` function.

It allows tasks to run based on elapsed time without stopping the processor, enabling continuous sensor monitoring and better responsiveness.

**Example Use Case:** Reading a DHT sensor every 2 seconds while simultaneously checking button presses.
