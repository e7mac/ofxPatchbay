//
//  ofxPatchbay.h
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#ifndef ofxPatchbay_h
#define ofxPatchbay_h

#include <iostream>
#include <map>
#include <set>
#include "ofMain.h"
#include "ofxPatchbayInput.h"

using namespace std;

class ofxPatchbay {
public:
    ofxPatchbay(bool kb = true, bool mouse = true, bool midi = true, bool audio = true);
    void update(int updateFrequency = 1);
    void registerAllInputs();
    
    void connect1f(string controller, string controllable);
    void connect2f(string controller, string controllable);

    void disconnect1f(string controller, string controllable);
    void disconnect2f(string controller, string controllable);

    void disconnectAll();
    void disconnectAll1f();
    void disconnectAll2f();

    void registerControllable1f(string, function<void (float)>);
    void registerController1f(string, function<float ()>);

    void registerControllable2f(string, function<void (ofVec2f)>);
    void registerController2f(string, function<ofVec2f ()>);

    void print();
    void printConnections();
    void print1f();
    void print2f();
protected:
    map<string, set<string>> connections1f;
    map<string, set<string>> connections2f;

    map<string, function<void (float)>> controllable1f;
    map<string, function<float ()>> controller1f;

    map<string, function<void (ofVec2f)>> controllable2f;
    map<string, function<ofVec2f ()>> controller2f;
    
    ofxPatchbayInput input;
    int _tick = 0;
};

#endif /* ofxPatchbay_h */
