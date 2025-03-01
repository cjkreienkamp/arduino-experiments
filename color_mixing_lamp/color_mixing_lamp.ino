const int redLEDPin = 10;
const int blueLEDPin = 11;
const int greenLEDPin = 9;

const int redSensorPin = A0;
const int blueSensorPin = A1;
const int greenSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup() {
  Serial.begin(9600);   // set the baud rate to 9600 bits/sec

  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  Serial.print("Raw Sensor Values /t Red:");
  Serial.print(redSensorValue);
  Serial.print("/t Blue:");
  Serial.print(blueSensorValue);
  Serial.print("/t Green:");
  Serial.println(greenSensorValue);

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  Serial.print("Mapped Sensor Values /t Red:");
  Serial.print(redValue);
  Serial.print("/t Blue:");
  Serial.print(blueValue);
  Serial.print("/t Green:");
  Serial.println(greenValue);

  analogWrite(redLEDPin, redValue);
  analogWrite(blueLEDPin, blueValue);
  analogWrite(greenLEDPin, greenValue);
}
