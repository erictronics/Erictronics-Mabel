/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM TAKE A DELAY IN MILLISECONDS
   FROM THE USER AND USE IT TO CONTROL THE SPEED OF THE 
   RING'S LIGHTING.
*/
#include <Mabel.h>
unsigned long speed = 1000; //Default is 1s

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("RING");
  for (int i = 0; i < mabel.nRING; i++) {
    pinMode(mabel.RING[i], OUTPUT);
    digitalWrite(mabel.RING[i], HIGH);
    delay(500);
    digitalWrite(mabel.RING[i], LOW);
  }  
}

void loop() {
  if(Serial.available()){
    speed  = Serial.parseInt();
    Serial.read();
    Serial.println("Speed: " +String(speed));    
  }
  for(int i = 0; i < mabel.nRING; i++){
    digitalWrite(mabel.RING[i], HIGH);
    delay(speed);
    digitalWrite(mabel.RING[i], LOW);
  }
}
