/**
   NAME: BUZZER EXPERIMENT
   AUTHOR: ERIC OBENG (PROFESIR)
   COMPANY: ERICTRONICS
   DESCRIPTION: THIS PROGRAM TAKES A HEX COLOR CODE AND TRY
   TO DISPLAY IT ON THE RGB LED.
*/
#include <Mabel.h>

String hexCode;

void setup() {
  // Adjust to your preference
  Serial.begin(9600);
  mabel.experiment("RGB");
  Serial.println("Enter hex (E.g. #fffff) code: ");
  for (int i = 0; i < mabel.nRGB; i++) {
    //RED -> RGB[0], GREEN - > RGB[1], BLUE -> RGB[2]
    pinMode(mabel.RGB[i], OUTPUT);
    digitalWrite(mabel.RGB[i], HIGH);
    delay(500);
    digitalWrite(mabel.RGB[i], LOW);
  }
}

void loop() {
  if (Serial.available()) {
    hexCode = Serial.readString();
    Serial.read(); // Clear any newline in buffer
    hexCode.trim();
    if (hexCode.indexOf('#') == -1) {
      Serial.println("start with #");
    } else if (hexCode.length() != 7) {
      Serial.println("Invalid Hex String");
    } else {
      hexDecoder();
    }
  }
}

void hexDecoder() {
  String red = hexCode.substring(1, 3);
  String green = hexCode.substring(3, 5);
  String blue = hexCode.substring(5);
  int r = getDecValue(red);
  int g = getDecValue(green);
  int b = getDecValue(blue);
  Serial.println("RED: " + String(r) + ", GREEN: " + String(g) + ", BLUE: " + String(b));
  showColor(r, g, b);
}

int getDecValue(String val) {
  int decVal = 0;
  char c;
  for (int i = 0; i < 2; i++) {
    c = val[i];
    if (c >= 'A' && c <= 'Z') {
      decVal += ((10 + int(c - 'A')) * ((i == 0) ? 16 : 1));
    } else if (c >= 'a' && c <= 'z') {
      decVal += ((10 + int(c - 'a')) * ((i == 0) ? 16 : 1));
    } else if (c >= '0' && c <= '9') {
      decVal += ((int(c - '0')) * ((i == 0) ? 16 : 1));
    }
  }
  return decVal;
}

void showColor(int r, int g, int b) {
  // The intensities of the colors are not adjusted in the
  // hardware, so software corrections are employed to get
  // Approximate values R=1, G=0.606, B=0.555
  analogWrite(mabel.RGB[0], r);
  analogWrite(mabel.RGB[1], g * 0.606);
  analogWrite(mabel.RGB[2], b * 0.588);
}
