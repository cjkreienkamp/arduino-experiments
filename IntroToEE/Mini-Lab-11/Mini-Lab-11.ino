/*
  Chris Kreienkamp - 901965168
  EE20222: Introduction to Electrical Engineering
  20 Apr 2020
  Mini-Lab 11 - Analog Inputs
*/
int midx;
int aval;
int mval;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(5,INPUT);
  Serial.begin(115200);
  midx = analogRead(5);
}



// the loop function runs over and over again forever
void loop() {
  aval = analogRead(5);
  if (aval < midx) {
    mval = map(aval,midx,0,0,255); }
  else {
    mval = map(aval,midx,1023,0,255); }
  Serial.print("midx: ");
  Serial.print(midx);
  Serial.print("   aval: ");
  Serial.print(aval);
  Serial.print("   Mapped value: ");
  Serial.println(mval);
}
