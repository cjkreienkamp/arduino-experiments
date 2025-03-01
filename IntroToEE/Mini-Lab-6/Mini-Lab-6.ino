/*
  Chris Kreienkamp - 901965168
  EE20222: Introduction to Electrical Engineering
  26 Mar 2020
  Mini-Lab 6 - Serial Monitor
*/

int value;

// the setup function runs once when you press reset or power the board
void setup() {
  value = 0;
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Chris Kreienkamp: count: ");
  Serial.println(value);
  value++;
  if (value > 99) {
    value = 0;
  }
  delay(100);
}
