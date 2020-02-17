/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM TAKES A SINGLE DIGIT FROM THE SERIAL
   MONITOR AND PRINTS IT TO THE MSB SEGMENT DISPLSY
*/
#include <Mabel.h>
int digit = 0;

const int row = 10, col = 7;
const byte IMAGES[row][col] = {
  {1, 1, 1, 0, 1, 1, 1},
  {0, 0, 1, 0, 0, 0, 1},
  {0, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 0, 0, 1},
  {1, 1, 0, 1, 0, 1, 1},
  {1, 1, 0, 1, 1, 1, 1},
  {0, 1, 1, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("LSB");
  for (int i = 0; i < mabel.nLSB; i++) {
    pinMode(mabel.LSB[i], OUTPUT);
    digitalWrite(mabel.LSB[i], HIGH);
    delay(200);
    digitalWrite(mabel.LSB[i], LOW);
  }
}

void loop() {
  for (int i = 0; i < mabel.nLSB; i++) {
    digitalWrite(mabel.LSB[i], IMAGES[digit][i]);
  }  
  digit++;
  digit %= 10;
  delay(500);
}
