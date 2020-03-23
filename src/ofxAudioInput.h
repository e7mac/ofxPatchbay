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
    ofxAudioInput(string deviceName="BlackHole 16ch", int srate=44100, int bufferSize=1024);
    void audioIn(ofSoundBuffer& buffer);
    ofSoundBuffer *buffer;

    float getRMS();

private:
    void initDevice(ofSoundDevice device, int srate, int bufferSize);
    ofSoundStream soundStream;
};


#endif /* ofxAudioInput_h */
