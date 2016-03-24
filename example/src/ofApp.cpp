#include "ofApp.h"
using namespace ofxRpiWS281x;
void ofApp::setup(){
    led = new ofxRpiWS281x::BaseLED();
    led->setup(288, 125);
}
void ofApp::exit(){
	
}
//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

}


