/**
 * NAME: CHECK EXPERIMENT BY NAME
 * AUTHOR: ERIC OBENG (PROFESIR)
 * COMPANY: ERICTRONICS
 * DESCRIPTION: THIS PROGRAM IS USED CHECK THE PIN
 * MAPPINGS OF A GIVEN EXPERIMENT ON THE MABEL BOARD.
 * IT TAKES INPUT AND DISPLAYS RESULTS USING THE SERIAL
 * MONITOR. WHEN A GIVEN EXPERIMENT NAME AS IT APPEARS
 * ON THE MABEL BOARD IS INPUT, THE PROGRAM RETURNS
 * A BRIEF INFORMATION ON THE PIN MAPPINGS OF THE EXPERIMENT.
 * IF IT IS A SENSOR-BASED EXPERIMENT, IT GIVES INFORMATION 
 * ABOUT THE TYPE OF SENSORS TOO. DG -> DIGITAL OUTPUT SENSOR
 * AN -> ANALOG OUTPUT SENSOR
 */
#include <Mabel.h>
String expmt;

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  Serial.println(F("ENTER NAME OF EXPERIMENT ON MABEL: "));
}

void loop() {
  if(Serial.available()){
    expmt = Serial.readString();
    Serial.read(); // Added to clear newline
    expmt.trim();
    mabel.experiment(expmt);
  }
}
