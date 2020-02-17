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
#include "String.h"

class Mabel{
	private:	
	public:
		// SENSORS OR SENSORS
		const byte PIR = A1;
		const byte POT = A3;
		const byte LDR = A2;
		const byte LM35 = A4;
		const byte BTNS[2] = {A5, 2};
		// OUTPUTS
		const byte BUZ = 3;		
		const byte RGB[3] = {9,10,11};
		const byte BAR[9] = {2,3,4,5,6,7,8,9,10};
		const byte TLIG[9] = {8,9,10,5,6,7,2,3,4};
		const byte BLNK = 13;
		const byte RING[12] = {9,10,11,12,2,3,4,5,6,7,8,13};
		const byte MSB[7] = {2,3,4,5,6,7,8};
		const byte LSB[7] = {9,10,11,12,13,14,15};
		const byte IR[2] = {5, 6};
		const byte RLY = 13;	
		// ARRAY SIZE CONSTANTS	
		const byte nBTNS = 2;	
		const byte nRGB = 3;
		const byte nBAR = 9;
		const byte nTLIG = 9;
		const byte nRING = 12;
		const byte nMSB= 7;
		const byte nLSB = 7;
		
		//Constructor
		Mabel();
		// Display all experiment conflicts
		void conflicts();
		// Display the version of mabel
		void version();
		// Display all known errors on board
		void errors();
		// Display basic info about mabel
		void info();
		// Display informatation about experiment
		void experiment(String expmt);
	};

extern Mabel mabel;
#endif
