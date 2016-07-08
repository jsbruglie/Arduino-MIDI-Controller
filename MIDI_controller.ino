#include "MIDI_controller.h"

#define POTS 2
#define LEDS 1

Pot pot[POTS] = {
	{1, MIDI_PITCH_BEND} , {2, MIDI_CC_CMD, MIDI_CC_MODULATION}
};

Led led[LEDS] = {
	{3}
};

void setup(){
   /* Initialize a Serial connection */
   Serial.begin(115200);
}

void loop(){

	int i;
	int value;
	/* Check each potentiometer */
	for (i = 0; i < POTS; i++){
		pot[i].update();
	}
  delay(30);
}
