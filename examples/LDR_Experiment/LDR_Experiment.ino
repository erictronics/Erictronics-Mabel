/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGAM DISPLAYS THE ANALOG READING AS 
   YOU CAST SHADOW UNTO THE LDR
*/
#include <Mabel.h>
void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("LDR");
  Serial.println("Cast shadown unto the Light sensor");
}

void loop() {
  Serial.println(analogRead(mabel.LDR));
  delay(1000);
}
