/*
	Mabel.cpp - Library for Mabel  Learning Kit
	Author: Eric Obeng (Profesir) @ Erictronics
	Date: October 4, 2018
	Desc: This library exposes the pin mapping of Mabel Learning Kit
	Institution: Erictronics
	Released into the public domain.
	Website: www.erictronics.com, www.learnaskillgh.com
	Email: info@erictronics.com, info@learnaskillgh
	Tel: +233553988118, +233501373417
*/
#include "Arduino.h"
#include "Mabel.h"


Mabel::Mabel(){}

void Mabel::conflicts(){}

void Mabel::version(){
	Serial.println(F("MABEL (ELECTRON)"));
	Serial.println(F("VERSION 1"));	
	Serial.println(F("DESIGNED BY: ERIC OBENG (PROFESIR))"));
	Serial.println(F("@ERICTRONICS"));
	Serial.println();
}

void Mabel::info(){
	Serial.println(F("VERY IMPORTANT INFO"));
	Serial.println(F("Maximum Voltage: 9 VDC"));
	Serial.println(F("Number of Inputs: 5"));
	Serial.println(F("Number of Outputs: 10"));
	Serial.println();
}

void Mabel::errors(){
	Serial.println(F("THE FOLLOWING ARE KNOWN MISTAKES ON THE V1 BOARD:"));
	Serial.println(F("1. Certain experiments turn on the indicators of other experiments"));
	Serial.println(F("2. MSB is labeled LSB"));
	Serial.println();
}
