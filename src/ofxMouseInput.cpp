//
//  ofxMouseInput.cpp
//  mondrian
//
//  Created by Mayank Sanganeria on 2/29/20.
//

#include "ofxMouseInput.h"
#include "ofMain.h"

glm::vec2 ofxMouseInput::getXY() {
    return glm::vec2(getX(), getY());
}

float ofxMouseInput::getX() {
    return (float) ofGetMouseX() / ofGetWidth();
}

float ofxMouseInput::getY() {
    return (float) ofGetMouseY() / ofGetHeight();
}

bool ofxMouseInput::getPressed(int button) {
    return (float) ofGetMousePressed(button);
}
