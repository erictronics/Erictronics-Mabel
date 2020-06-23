/**
   NAME: BAR EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM IS A SIMULATION OF THE INTERNATION
   MORSE CODE. IT USES THE BUZZER, BLNK EXPERIMENTS ON THE MABEL
   BOARD ALONG WITH THE SERIAL MONITOR.
*/

/**
   International Morse Code
  1. The length of a dot is one unit.
  2. A dash is three units.
  3. The space between parts of the same letter is one unit.
  4. The space between letters is three units.
  5. The space between words is seven units.
*/

#include <Mabel.h>

void beep(int); // This function makes the creates the sound and light
const int UNIT_LENGTH = 100;  // Pulse length of a CODE

// Morse codes for Alphanumeric characters
String CODES[] = {
  "-----",  ".----",  "..---",  "...--",  "...._",  ".....",
  "-....",  "--...",  "---..",  "----.", ".-",
  "-...",  "-.-.",  "-..",  ".",  "..-.",  "--.",  "....",
  "..",  ".---",  "-.-",  ".-..",  "--",  "-.",  "---",
  ".--.",  "--.-",  ".-.",  "...",  "-",  "..-",  "...-",
  ".--",  "-..-",  "-.-",  "--."
};

void setup() {
  Serial.begin(9600);
  
  // This program uses the BUZ and BLNK experiments
  pinMode(mabel.BUZ, OUTPUT);
  pinMode(mabel.BLNK, OUTPUT);
  
  Serial.println("Enter Message: ");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readString();
    data.toUpperCase();
    Serial.read();
    
    transmit(data);

    //Send another
    Serial.println("Enter Message: ");
  }
}

void transmit(String sentence) {
  Serial.println("Message: " + sentence);
  for (int i = 0; i < sentence.length(); i++) {
    char character = sentence[i]; // Extract the ith character in the sentence
    Serial.println("Character: " + String((character == ' ') ? "SPACE" : String(sentence[i])));
    
    // if the ith character is a space create 7 units of silence as the morse code
    // protocol demands and continue
    if (character == ' ') {
      space();
      continue;
    }

    // Check whether the character is a number or alphabet and extract its morse code
    String charMorseCode = ((character - '0' <= 9) ? CODES[character - '0'] : CODES[(character - 'A') + 10]);
    Serial.println("Morse Code: " + charMorseCode);

    // transmit the code
    for (int x = 0; x < charMorseCode.length(); x++) {
      beep(charMorseCode[x]);
      delay(UNIT_LENGTH);
    }
    delay(3 * UNIT_LENGTH);
  }
}

void beep(char code) {
  //Check whether its a dot or dash and get the pulse length
  int duration = (code == '.') ? UNIT_LENGTH : 3 * UNIT_LENGTH;
  digitalWrite(mabel.BUZ, HIGH);
  digitalWrite(mabel.BLNK, HIGH);
  delay(duration);

  digitalWrite(mabel.BUZ, LOW);
  digitalWrite(mabel.BLNK, LOW);
  delay(duration);
}

void space() {
  // Function to call when character is a space
  digitalWrite(mabel.BUZ, LOW);
  digitalWrite(mabel.BLNK, LOW);
  delay(7 * UNIT_LENGTH);
}
