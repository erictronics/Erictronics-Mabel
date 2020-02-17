/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM USES THE TWO BUTTONS TO
   UPDATE THE VALUE OF A VARIABLE AND DISPLAY IT ON THE
   SERIAL MONITOR
*/
#include <Mabel.h>

int count = 0;

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("BTNS");
  Serial.println("Press UP or DOWN Buttons");
  pinMode(mabel.BTNS[0], INPUT);
  pinMode(mabel.BTNS[1], INPUT);
}

void loop() {
  if (digitalRead(mabel.BTNS[0]) == LOW) {
    Serial.println("Count: " + String(++count));
    delay(400);
  }
  if (digitalRead(mabel.BTNS[1]) == HIGH) {
    Serial.println("Count: " + String(--count));
    delay(400);
  }
}
