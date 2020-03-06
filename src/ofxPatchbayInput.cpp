//
//  ofxPatchbayInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxPatchbayInput.h"
#include "ofxPatchbay.h"

void ofxPatchbayInput::registerInputs(ofxPatchbay *patchbay) {
    registerKeyboardInputs(patchbay);
    registerMouseInputs(patchbay);
    registerMidiInputs(patchbay);
    registerAudioInputs(patchbay);
}

void ofxPatchbayInput::registerKeyboardInputs(ofxPatchbay *patchbay) {
    for (char i = 32; i < 127; ++i) {
        string name = "kb-";
        name.append(1, i);
        patchbay->registerController1f(name, [&, i] {
          return ofGetKeyPressed(i);
      });
    }
}

void ofxPatchbayInput::registerMouseInputs(ofxPatchbay *patchbay) {
    patchbay->registerController1f("mouse-x", [&] {
        return mouse.getX();
    });

    patchbay->registerController1f("mouse-y", [&] {
        return mouse.getY();
    });

    patchbay->registerController2f("mouse-xy", [&] {
        return mouse.getXY();
    });

    patchbay->registerController1f("mouse-btn", [&] {
        return mouse.getPressed(0);
    });

    patchbay->registerController1f("mouse-btn-right", [&] {
        return mouse.getPressed(1);
    });
}

void ofxPatchbayInput::registerMidiInputs(ofxPatchbay *patchbay) {
    for (int i=0;i<NUM_MIDI_CHANNEL; i++) {
        patchbay->registerController1f("midi-cc-" + to_string(i), [&, i] {
            return midi.control[i];
        });
    }
    for (int i=0;i<NUM_MIDI_CHANNEL; i++) {
        patchbay->registerController1f("midi-prog-" + to_string(i), [&, i] {
            return midi.program[i];
        });
    }
    for (int i=0;i<NUM_MIDI_CHANNEL; i++) {
        patchbay->registerController1f("midi-note-" + to_string(i), [&, i] {
            return (midi.notesOn.find(i) != midi.notesOn.end()) ? 1 : 0;
        });
    }

}

void ofxPatchbayInput::registerAudioInputs(ofxPatchbay *patchbay) {
    patchbay->registerController1f("audio-rms", [&] {
        return audio.getRMS();
    });
}
