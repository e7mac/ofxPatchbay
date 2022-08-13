//
//  ofxAudioInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxAudioInput.h"
#include "ofMain.h"

ofxAudioInput::ofxAudioInput(string deviceName, int srate, int bufferSize) {
    //    soundStream.printDeviceList();
    vector<ofSoundDevice> devices = soundStream.getMatchingDevices(deviceName);
    if( devices.empty() ) {
        devices = soundStream.getDeviceList();
    }
    if( !devices.empty() ) {
        initDevice(devices[0], srate, bufferSize);
    }
}

void ofxAudioInput::audioIn(ofSoundBuffer& buff) {
    buffer = &buff;
}

float ofxAudioInput::getRMS() {
    if (!buffer) return 0;
    return buffer->getRMSAmplitude();
}

float ofxAudioInput::getLowPassedRMS() {
    static float prevSample = 0;
    float lpSample = prevSample + getRMS();
    return lpSample;
}

void ofxAudioInput::initDevice(ofSoundDevice device, int srate, int bufferSize) {
    ofSoundStreamSettings settings;
    settings.setInDevice(device);
    settings.setInListener(this);
    settings.sampleRate = srate;
    settings.bufferSize = bufferSize;
    settings.numInputChannels = 2;
    settings.numOutputChannels = 0;
    soundStream.setup(settings);
}
