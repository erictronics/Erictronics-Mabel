/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM RUNS A SIMPLE TRAFFIC LIGHT
   SIMULATION ON THE MABEL MOTHERBOARD 
*/
#include <Mabel.h>

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("TLIG");
  for (int i = 0; i < mabel.nTLIG; i++) {
    pinMode(mabel.TLIG[i], OUTPUT);
    digitalWrite(mabel.TLIG[i], HIGH);
    delay(500);
    digitalWrite(mabel.TLIG[i], LOW);
  }  
}

void loop() {
  // Turn on direction 1
  switcher(2,3,6);
  delay(2000);
  //Turn on amber
  switcher(1,3,6);
  delay(700);
  
  // Turn on direction 2
  switcher(0,5,6);
  delay(2000);
  //Turn on amber
  switcher(0,4,6);
  delay(700);

  // Turn on direction 3
  switcher(0,3,8);
  delay(2000);
  //Turn on amber
  switcher(0,3,7);
  delay(700);

  //Turn all off
  // Turn on direction 2
  switcher(0,3,6);
  delay(1000);
}

void switcher(int d1, int d2, int d3){
  for(int i = 0; i < mabel.nTLIG; i++){
    digitalWrite(mabel.TLIG[i], ((i == d1 || i == d2 || i == d3)? HIGH:LOW));
  }
}
