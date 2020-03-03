//
//  ofxAudioInput.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxAudioInput_h
#define ofxAudioInput_h

#include <stdio.h>
#include "ofMain.h"

class ofxAudioInput {
public:
    ofxAudioInput();
    void audioIn(ofSoundBuffer& buffer);
    ofSoundBuffer *buffer;

    float getRMS();

private:
    ofSoundStream soundStream;
};


#endif /* ofxAudioInput_h */
