//
//  ofxMidiInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxMidiInput_h
#define ofxMidiInput_h

#include <stdio.h>
#include "ofxMidi.h"

#define NUM_MIDI_CHANNEL 128

class ofxMidiInput : public ofxMidiListener {
public:
    ofxMidiInput();

    float control[NUM_MIDI_CHANNEL];
    float program[NUM_MIDI_CHANNEL];
    std::set<int> notesOn;

    void newMidiMessage(ofxMidiMessage& msg);
private:
    ofxMidiIn midiIn[2];
};


#endif /* ofxMidiInput_h */
