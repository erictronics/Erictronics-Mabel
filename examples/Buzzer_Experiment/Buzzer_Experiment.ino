/**
 * NAME: BUZZER EXPERIMENT
 * AUTHOR: ERIC OBENG (PROFESIR)
 * COMPANY: ERICTRONICS
 * DESCRIPTION: THIS CODE PLAYS A MELODY USING THE BUZZER
 * ON MABEL. IT IS A REPLICA OF ARDUINO TONEMELODY EXAMPLE.
 */
#include <Mabel.h>
#include "pitches.h" //Can be located in this example's folder

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // Adjust to your preference
  Serial.begin(9600);  
  mabel.experiment("BUZ");
  pinMode(mabel.BUZ, OUTPUT);
}

void loop() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(mabel.BUZ, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(mabel.BUZ);
  }
  delay(300); // Wait for 0.5 s
}
