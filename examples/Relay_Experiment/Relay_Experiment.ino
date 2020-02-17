/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM DETECT MOTION USING A PIR 
   SENSOR AND DISPLAYS A TEXT ON THE SERIAL MONITOR.
   PIR IS BY DEFAULT LOW SO A DETECTION WILL TRIGGER 
   A HIGH.
*/
#include <Mabel.h>

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("RLY");
  pinMode(mabel.RLY, OUTPUT);
}

void loop() {
  // Flicker
  digitalWrite(mabel.RLY, HIGH);
  delay(1000);
  digitalWrite(mabel.RLY, LOW);
  delay(1000);
}
