#include "Arduino.h"
#include "MIDI_controller.h"

Pot::Pot(int pin, int function){

	pinMode(pin, INPUT);
	_pin = pin;
	_function = function;
  _command = 0;
	_value = analogRead(_pin);
  _broadcast_value = 0;
}

Pot::Pot(int pin, int function, int command){

  pinMode(pin, INPUT);
  _pin = pin;
  _function = function;
  _command = command; 
  _value = analogRead(_pin);
  _broadcast_value = 0;
}

int Pot::update(){
	_value = analogRead(_pin);
	broadcast_MIDI();
	return _value;
}

void Pot::broadcast_MIDI(){
  
  int value = 0;
  int max_value;
  
  if (_function == MIDI_PITCH_BEND){
    max_value = 127;
  } 
  else if(_function == MIDI_CC_CMD){
    max_value = 127;
  }  
  else{
    return;
  } 
  
  value = map(_value, 1023, 0, 0, max_value);
  if (value == _broadcast_value){ 
      return;
  }
  _broadcast_value = value;
  
	MIDI_message(_function, _command, value);
}


Led::Led(int pin){

	pinMode(pin, OUTPUT);
	_pin = pin;
	_state = 0;
	digitalWrite(_pin, 0);
}

void Led::update(int value){
	if (_state != value){
		_state = value;
		digitalWrite(_pin, value);
	}
}

void MIDI_message(int MIDI_function, int MIDI_command, int MIDI_value) {
  
  Serial.write(MIDI_function);
  Serial.write(MIDI_command);
  Serial.write(MIDI_value);
  
}
