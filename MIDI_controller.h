#ifndef cont_h
#define cont_h

#include "Arduino.h"

/*
	MIDI functions

	01h		- MOD 		- Modulation Wheel
	07h		- VOLUME	- Main Volume
	0E-13h	- GENERAL	- General Purpose Controllers (Track Faders)

*/

// Channel 1
#define MIDI_PITCH_BEND     0xE0
#define MIDI_CC_CMD         0xB0

#define MIDI_CC_MODULATION 	0x01
#define MIDI_CC_VOLUME 		  0x07
#define MIDI_CC_GENERAL1 	  0x0E
#define MIDI_CC_GENERAL2 	  0x0F
#define MIDI_CC_GENERAL3	  0x10
#define MIDI_CC_GENERAL4	  0x11
#define MIDI_CC_GENERAL5	  0x12
#define MIDI_CC_GENERAL6	  0x13

void MIDI_message(int MIDI_function, int MIDI_command, int MIDI_value);

class Pot{
	public:
		Pot(int pin, int function);
    Pot(int pin, int function, int command);
		int update();
		void broadcast_MIDI();

	private:
		int _pin;
		int _function;
    int _command;
		int _value;
		int _broadcast_value;
};

class Led{
	public:
		Led(int pin);
		void update(int value);

	private:
		int _pin;
		int _state;	
};

#endif
