#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    patchbay.registerControllable1f("rect-size", [&] (float value) {
        rect.setSize(200*value, 200*value);
    });
    patchbay.registerControllable1f("rect-color", [&] (float value) {
        color = ofColor(255*value, 255, 255);
    });
    patchbay.registerControllable1f("rect-scale", [&] (float value) {
        scale = 0.5 + 10*value;
    });

    patchbay.connect1f("mouse-x", "rect-size");
    patchbay.connect1f("mouse-y", "rect-color");

    patchbay.connect1f("audio-rms", "rect-scale");

}

//--------------------------------------------------------------
void ofApp::update(){
    patchbay.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofBackground(0);
    ofSetColor(color);
    ofDrawRectangle(rect.x - scale*rect.width/2, rect.y - scale*rect.height, scale*rect.width, scale*rect.height);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
