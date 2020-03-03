//
//  ofxAudioInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxAudioInput.h"
#include "ofMain.h"

ofxAudioInput::ofxAudioInput() {
    //    soundStream.printDeviceList();
    auto devices = soundStream.getMatchingDevices("Soundflower (2ch)");
    if( !devices.empty() ) {
        ofSoundStreamSettings settings;
        settings.setInDevice(devices[0]);
        settings.setInListener(this);
        settings.sampleRate = 44100;
        settings.bufferSize = 1024;
        settings.numInputChannels = 2;
        settings.numOutputChannels = 0;
        soundStream.setup(settings);
    }
}

void ofxAudioInput::audioIn(ofSoundBuffer& buff) {
    buffer = &buff;
}

float ofxAudioInput::getRMS() {
    if (!buffer) return 0;
    return buffer->getRMSAmplitude();
//    auto flo = buffer->getBuffer();
//    std::for_each(std::execution::par, flo.begin(), flo.end(), [&](int i) {
//      flo[i] = flo[i] * flo[i]; // Error: data race
//    });
}
