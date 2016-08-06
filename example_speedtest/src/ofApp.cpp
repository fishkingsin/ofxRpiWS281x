#include "ofApp.h"
using namespace ofxRpiWS281x;
int step = 0;
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
	startThread();
}
void ofApp::threadedFunction(){
	while(isThreadRunning()){
		if(lock()){
			for(int i = 0 ; i < LED_COUNT ; i++){
				if(step==i){
					led->drawPiexls(step,ofColor(50,50,50));
				}else{
					led->drawPiexls(step,ofColor(0,0,0));
				}
			}
			led->update();
			step++;
			step%=LED_COUNT;
			lock();
		}
	}
}
void ofApp::exit(){
	stopThread();
	for(int i = 0 ; i < LED_COUNT ; i++){
		led->drawPiexls(i,0);
	}
	led->update();
}
//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
}


