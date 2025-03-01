/*
  Chris Kreienkamp - 901965168
  EE20222: Introduction to Electrical Engineering
  22 Apr 2020
  Mini-Lab 12 - Analog Inputs and Outputs
*/
int midx;
int aval;
int mval;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(A5,INPUT);
  pinMode(5, OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(115200);
  midx = analogRead(A5);
}



// the loop function runs over and over again forever
void loop() {
  aval = analogRead(A5);
  if (aval >= midx) {
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    mval = map(aval,midx,1023,0,255); }
  else {
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    mval = map(aval,midx,0,0,255); }
  Serial.print("midx: ");
  Serial.print(midx);
  Serial.print("   aval: ");
  Serial.print(aval);
  Serial.print("   Mapped value: ");
  Serial.print(mval);
  Serial.print("   pin 8: ");
  Serial.print(digitalRead(8));
  Serial.print("   pin 9: ");
  Serial.println(digitalRead(9));
  analogWrite(5,mval);
}
