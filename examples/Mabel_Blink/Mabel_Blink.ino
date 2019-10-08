/*
 * FILENAME: MABEL_BLINK
 * AUTHOR: MR. ERIC OBENG (PROFESIR)
 * LICENCE: ALL RIGHTS RESERVED
 * COMPANY: ERICTRONICS
 * THIS SKETCH DISPLAYS THE BASIC INFORMATION 
 * AND ALL KNOWN ERRORS ABOUT MABEL
 */

#include <Mabel.h>  //Import the Mabel Class
Mabel mabel;  //Create an instance of the Mabel

void setup() {
  //BLNK is connected to Arduino Pin 13
  pinMode(mabel.BLINK, OUTPUT);
}

void loop() {
  digitalWrite(mabel.BLINK, HIGH);
  delay(1000);
  digitalWrite(mabel.BLINK, LOW);
  delay(1000);
}
