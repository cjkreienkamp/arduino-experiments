#include "LiquidCrystal.h"
LiquidCrystal lcd(1, 2, 3, 4, 5, 6, 7);
const int trigPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
long duration;
int inches, cm;

void setup() {
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); }

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  //lcd.print("HELLO WORLD!");
  lcd.setCursor(0,0); // Sets the location on the LCD
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(cm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(inches);
  lcd.print(" in");
  delay(100); }

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2; }
long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2; }
