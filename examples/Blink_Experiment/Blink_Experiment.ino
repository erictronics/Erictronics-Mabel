/**
 * NAME: BLINK EXPERIMENT
 * AUTHOR: ERIC OBENG (PROFESIR)
 * COMPANY: ERICTRONICS
 * DESCRIPTION: THIS PROGRAM IS THE TRADITIONAL BLINK
 * ON MABEL BOARD. IT IS SIMILAR TO PERFORMING BLINK ON
 * ARDUINO UNO BOARD USING PIN 13 AKA LED_BUILTIN. HOWEVER
 * THIS PROGRAM USES SERIAL MONITOR TO ENTER THE BLINK
 * DELAY IN MILISECONDS.
 */
#include <Mabel.h>
unsigned long blink_delay = 1000; // default blink delay

void setup() {
  // Adjust to your preference
  Serial.begin(9600);  
  mabel.experiment("BLNK");
  Serial.println(F("Enter blink delay: "));
  pinMode(mabel.BLNK, OUTPUT); // Set as output pin
}

void loop() {
  if(Serial.available()){
    // Read input and save to variable
    blink_delay = Serial.parseInt();
    Serial.read(); // Added to clear newline  
    Serial.print("Delay: ");  
    Serial.println(blink_delay);
  }

  // You can use 13 or LED_BUILTIN in place of mabel.blnk
  digitalWrite(mabel.BLNK, HIGH); //Turn on 
  delay(blink_delay); //wait for blink_delay number of milliseconds
  digitalWrite(mabel.BLNK, LOW);  //Turn off
  delay(blink_delay);  // wait for blink_delay number of milliseconds
}
