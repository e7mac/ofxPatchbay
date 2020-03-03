//
//  ofxMidiInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxMidiInput.h"
#include "ofMain.h"

ofxMidiInput::ofxMidiInput() {
    // print input ports to console
    midiIn[0].listInPorts();
    midiIn[0].openPort(0);
    midiIn[1].openPort(1);
//    midiIn.openPort("IAC Driver Bus 1");

    // add as a listener
    midiIn[0].addListener(this);
    midiIn[1].addListener(this);

    std::fill_n(control, NUM_MIDI_CHANNEL, 0.5);
    std::fill_n(program, NUM_MIDI_CHANNEL, 0.5);
}

void ofxMidiInput::newMidiMessage(ofxMidiMessage& msg) {
//    cout<<msg.status<<" : "<<msg.control<<", "<<msg.value<<endl;
    if (msg.status == MIDI_CONTROL_CHANGE) {
        control[msg.control] = msg.value / 127.f;
    } else if (msg.status == MIDI_PROGRAM_CHANGE) {
        program[msg.control] = msg.value / 127.f;
    } else if (msg.status == MIDI_NOTE_ON) {
        notesOn.insert(msg.pitch);
    } else if (msg.status == MIDI_NOTE_OFF) {
        notesOn.erase(msg.pitch);
    }
}
