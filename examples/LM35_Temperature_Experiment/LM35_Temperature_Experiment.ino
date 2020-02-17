/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM READS THE DISPLAYS THE AMBIENT
   TEMPERATURE READING FROM THE LM35 SENSOR
*/
#include <Mabel.h>

int reading = 0;
float temp = 0;

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("LM35");
  Serial.println("Temperature of Your environment");
}

void loop() {
  reading = analogRead(mabel.LM35);
  temp = ((reading/1023.0)*500.0);
  Serial.println("Temp: " + String(temp)+ String(char(223))+"C");
  delay(1000);
}
