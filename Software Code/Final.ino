
float sensor1 = 0;
float sensor2 = 0;
float sensor3 = 0;
boolean WarningOutput = false;
boolean WarningLED = false;
boolean HeaterLED = false;
float sensor2voltage = 0;
float sensor1voltage = 0;
float thermalRef = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop() {
  sensor1 = analogRead(A0);
  sensor1voltage = sensor1 * (5.0 / 1023.0);
  Serial.print(sensor1voltage);
  sensor2 = analogRead(A1);
  sensor2voltage = sensor2 * (5.0 / 1023.0);
  Serial.print(sensor2voltage);
  if ((sensor2voltage > 1.2 * sensor1voltage) || (sensor2voltage < 0.8 * sensor1voltage))
  {
    digitalWrite(2, HIGH);
    //  WarningLED = HIGH;
    WarningOutput = LOW;
  }
  else {
    digitalWrite(2, LOW);
    // WarningLED = LOW;
    WarningOutput = HIGH;
  }
  sensor3 = analogRead(A2);
  thermalRef = sensor3 * (5.0 / 1023.0);
   Serial.print(thermalRef);
  if ((sensor1voltage + sensor2voltage) / 2 < thermalRef)
  {
    digitalWrite(3, HIGH);
    HeaterLED = HIGH;
  }
  else {
    digitalWrite(3, LOW);
    HeaterLED = LOW;
  }

  if ((WarningOutput == HIGH) and (HeaterLED == HIGH))
  {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
}
