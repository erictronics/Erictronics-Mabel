/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGAM DISPLAYS THE ANALOG READING AS 
   YOU ADJUST THE POTENTIOMETER
*/
#include <Mabel.h>
void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("POT");
  Serial.println("Adjust the POT");
}

void loop() {
  Serial.println(analogRead(mabel.POT));
  delay(1000);
}
