#include "ofApp.h"
using namespace ofxRpiWS281x;
ofColor wheel(int pos){
	
	if (pos < 85){
		return ofColor(pos * 3, 255 - pos * 3, 0);
	}
	else if (pos < 170){
		pos -= 85;
		return ofColor(255 - pos * 3, 0, pos * 3);
	}
	else{
		pos -= 170;
		return ofColor(0, pos * 3, 255 - pos * 3);
	}


}
void ofApp::setup(){
	led = new ofxRpiWS281x::BaseLED();
	led->setup(LED_COUNT, 125);
}
void ofApp::exit(){
	for(int i = 0 ; i < LED_COUNT ; i++){
		led->drawPiexls(i,0);
	}
	led->update();
}
//--------------------------------------------------------------
void ofApp::update(){
	for(int i = 0 ; i < LED_COUNT ; i++){
		led->drawPiexls(i,wheel((i+ofGetFrameNum())%255));
	}
	led->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}


