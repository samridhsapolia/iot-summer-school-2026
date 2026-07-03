#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22

#define TRIG_PIN 9
#define ECHO_PIN 10

#define LDR_PIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

}

void loop() {

  // DHT22
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // LDR
  int ldrValue = analogRead(LDR_PIN);

  int lightPercent = map(ldrValue, 0, 1023, 0, 100);

  String lightStatus;

  if (lightPercent > 70)
    lightStatus = "Bright";

  else if (lightPercent > 30)
    lightStatus = "Normal";

  else
    lightStatus = "Dark";

  // Ultrasonic
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2.0;

  // Output

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightStatus);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("==================");
  Serial.println();

  delay(5000);

}
