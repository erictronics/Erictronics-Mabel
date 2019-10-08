/*
	Mabel.h - Library for Mabel  Learning Kit
	Author: Eric Obeng (Profesir) @ Erictronics
	Date: October 4, 2018
	Desc: This library exposes the pin mapping of Mabel Learning Kit
	Institution: Erictronics
	Released into the public domain.
	Website: www.erictronics.com, www.learnaskillgh.com
	Email: info@erictronics.com, info@learnaskillgh
	Tel: +233553988118, +233501373417
*/


#ifndef Mabel_h
#define  Mabel_h

#include "Arduino.h"

class Mabel{
	private:	
	public:
		const byte PIR = A1, POT = A3, LDR = A2, LM35 = A4, BTN1 = A5, BTN2 = 2;
		const byte BUZ = 3, BLNK = 13, RLY = 13, IR_LED = 5, IR_RECV = 6;
		const byte RGB[3] = {9,10,11};
		const byte BAR[9] = {2,3,4,5,6,7,8,9,10};
		const byte TLIG[9] = {8,9,10,5,6,7,2,3,4};
		const byte RING[12] = {9,10,11,12,2,3,4,5,6,7,8,13};
		const byte MSB[7] = {2,3,4,5,6,7,8};
		const byte LSB[7] = {9,10,11,12,13,14,15};
		const byte nRGB = 3, nBAR = 9, nTLIG = 9, nRING = 12, nMSB= 7, nLSB = 7;
		
		//Constructor
		Mabel();
		void conflicts();
		void version();
		void errors();
		void info();
};


#endif
