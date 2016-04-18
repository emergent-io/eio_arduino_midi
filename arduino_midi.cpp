//
//  arduino_midi.cpp
//  
//
//  Created by connerlacy on 4/17/16.
//
//

#include "arduino_midi.h"

Midi::Midi()
{
    Serial.begin(31250);
}

void Midi::sendController(int channel, int cc, int value)
{
    Serial.write(clampChannel(channel));
    Serial.write(clampValue(cc));
    Serial.write(clampValue(value));
}

void Midi::sendNoteOn(int channel, int note, int velocity)
{
   Serial.write(clampChannel(channel));
   Serial.write(clampValue(note));
   Serial.write(clampValue(velocity)); 
}

void Midi::sendNoteOff(int channel, int note, int velocity)
{
   Serial.write(clampChannel(channel));
   Serial.write(clampValue(note));
   Serial.write(clampValue(velocity)); 
}

int Midi::clampChannel(int channel)
{
	if(channel > 16)
	{
		channel = 16;
	}
	else if(channel < 1)
	{
		channel = 1;
	}

	return channel;
}

int Midi::clampValue(int value)
{
	if(value > 127)
	{
		value = 127;
	}
	else if(value < 0)
	{
		value = 0;
	}

	return value;
}
