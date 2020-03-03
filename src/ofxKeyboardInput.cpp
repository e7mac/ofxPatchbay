//
//  ofxKeyboardInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxKeyboardInput.h"
#include "ofMain.h"

bool ofxKeyboardInput::isKeyPressed(int key) {
    return ofGetKeyPressed(key);
}
