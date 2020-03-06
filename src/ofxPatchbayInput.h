//
//  ofxPatchbayInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxPatchbayInput_h
#define ofxPatchbayInput_h

#include <iostream>
#include "ofxMidiInput.h"
#include "ofxMouseInput.h"
#include "ofxKeyboardInput.h"
#include "ofxAudioInput.h"

using namespace std;

class ofxPatchbay;

class ofxPatchbayInput {
public:
    void registerInputs(ofxPatchbay *patchbay);
    void registerKeyboardInputs(ofxPatchbay *patchbay);
    void registerMouseInputs(ofxPatchbay *patchbay);
    void registerMidiInputs(ofxPatchbay *patchbay);
    void registerAudioInputs(ofxPatchbay *patchbay);
protected:

    ofxMidiInput midi;
    ofxMouseInput mouse;
    ofxKeyboardInput keyboard;
    ofxAudioInput audio;
};

#endif /* ofxPatchbayInput_h */
