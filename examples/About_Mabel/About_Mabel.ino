/*
 * AUTHOR: MR. ERIC OBENG (PROFESIR)
 * LICENCE: ALL RIGHTS RESERVED
 * COMPANY: ERICTRONICS
 * THIS SKETCH DISPLAYS THE BASIC INFORMATION 
 * AND ALL KNOWN ERRORS ABOUT MABEL
 */

#include <Mabel.h>  //Import the Mabel Class
Mabel mabel;  //Create an instance of the Mabel

void setup() {
  Serial.begin(115200);
  mabel.version();
  mabel.info();
  mabel.errors();
  mabel.conflicts();
}

void loop() {
  // put your main code here, to run repeatedly:

}
