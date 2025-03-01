/*
  Chris Kreienkamp - 901965168
  EE20222: Introduction to Electrical Engineering
  13 Apr 2020
  Mini-Lab 8 - Digital Output and LED
*/

#include <Bounce2.h>
#define downButton 2
#define upButton 3
#define LED 5

Bounce downDebouncer = Bounce(); // Instantiate a Bounce object
Bounce upDebouncer = Bounce(); // Instantiate a Bounce object

int count = 0;



// the setup function runs once when you press reset or power the board
void setup() {
  downDebouncer.attach(downButton,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  upDebouncer.attach(upButton,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  downDebouncer.interval(10); // Use a debounce interval of 10 milliseconds
  upDebouncer.interval(10); // Use a debounce interval of 10 milliseconds
  pinMode(downButton,INPUT); // Setup the button as an input
  pinMode(upButton,INPUT); // Setup the button as an input
  pinMode(LED, OUTPUT); //Setup LED as an output
  digitalWrite(LED, count);
}



// the loop function runs over and over again forever
void loop() {
   downDebouncer.update(); // Update the Bounce instance
   if ( downDebouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
        if (count<1) {count++;} }
   upDebouncer.update(); // Update the Bounce instance
   if ( upDebouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
        if (count>0) {count--;} }
   digitalWrite(LED, count);
}
