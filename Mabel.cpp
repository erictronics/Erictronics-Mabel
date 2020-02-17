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
#include "String.h"
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

// Display informatation about experiment
void Mabel::experiment(String expmt){
	expmt.toUpperCase();
	if(expmt == F("EN")){
		Serial.println(F("EN KEY: PUSH IT UP to enable sensors."));
	}else if(expmt == F("PIR")){
		Serial.println(F("MOTION SENSOR:: DG -> PIN A1."));
	}else if(expmt == F("POT")){
		Serial.println(F("POTENTIOMETER:: AN -> PIN A3"));
	}else if(expmt == F("LDR")){
		Serial.println(F("LIGHT SENSOR:: AN -> PIN A2"));
	}else if(expmt == F("LM35")){
		Serial.println(F("TEMP. SENSOR:: AN -> PIN A4"));
	}else if(expmt == F("BTNS")){
		Serial.println(F("BUTTONS:: ARRAY, nBTNS=2, DG -> YEL: PIN A5, ACT. LOW, BLUE: PIN 2, ACT. HIGH"));
	}else if(expmt == F("BUZ")){
		Serial.println(F("BUZZER:: PIN 3"));
	}else if(expmt == F("RGB")){
		Serial.println(F("RGB LED:: ARRAY, nRGB=3 RED:9, GRN:10, BLU:11"));
	}else if(expmt == F("BAR")){
		Serial.print(F("BAR DISPLAY:: ARRAY, nBAR=9, PINS: "));
		for(int i=0; i < nBAR; i++){
			Serial.print(BAR[i]);
			Serial.print(", ");
		}
		Serial.println();
	}else if(expmt == F("TLIG")){
		Serial.print(F("TRAFFIC LIGHT:: ARRAY, nTLIG=9, PINS: "));
		for(int i=0; i < nTLIG; i++){
			Serial.print(TLIG[i]);
			Serial.print(", ");
		}
		Serial.println();
	}else if(expmt == F("BLNK")){
		Serial.println(F("BLINK:: PIN 13 AKA LED_BUILTIN"));
	}else if(expmt == F("RING")){
		Serial.print(F("RING DISPLAY:: ARRAY, nRING=12, PINS: "));
		for(int i=0; i < nRING; i++){
			Serial.print(RING[i]);
			Serial.print(", ");
		}
		Serial.println();
	}else if(expmt == F("MSB")){
		Serial.print(F("8 DIGIT MSB:: ARRAY, nMSB=7, PINS: "));
		for(int i=0; i < nMSB; i++){
			Serial.print(MSB[i]);
			Serial.print(", ");
		}
		Serial.println();
	}else if(expmt == F("LSB")){
		Serial.print(F("8 DIGIT LSB:: ARRAY, nLSB=7, PINS: "));
		for(int i=0; i < nLSB; i++){
			Serial.print(LSB[i]);
			Serial.print(", ");
		}
		Serial.println();
	}else if(expmt == F("IR")){
		Serial.println(F("IR TRANSCEIVER:: ARRAY, TRANS: 5, RCV: 6"));
	}else if(expmt == F("RLY")){
		Serial.println(F("RELAY:: PIN 13"));
	}
}

Mabel mabel;
