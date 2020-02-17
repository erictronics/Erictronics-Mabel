/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM TAKES A NUMBER FROM 0 TO 9
   AND DISPLAY IT ON THE BAR GRAPH. 
*/
#include <Mabel.h>

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("BAR");
  for (int i = 0; i < mabel.nBAR; i++) {
    //RED -> RGB[0], GREEN - > RGB[1], BLUE -> RGB[2]
    pinMode(mabel.BAR[i], OUTPUT);
    digitalWrite(mabel.BAR[i], HIGH);
    delay(500);
    digitalWrite(mabel.BAR[i], LOW);
  }  
  Serial.println("Enter number (0-9): ");
}

void loop() {
  if (Serial.available()) {
    int number;
    number = Serial.parseInt();
    Serial.read(); // Clear any newline in buffer
    Serial.println("Number: " + String(number));
    for(int i = 0; i < mabel.nBAR; i++){
      digitalWrite(mabel.BAR[i], ((i<number)? HIGH:LOW));
    }
  }
}
