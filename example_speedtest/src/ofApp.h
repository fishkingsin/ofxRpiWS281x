#pragma once

#include "ofMain.h"
#include "ofxRpiWS281x.h"
#define LED_COUNT 90
class ofApp : public ofBaseApp, ofThread{
	public:
		void setup();
		void update();
		void draw();
		void exit();
		

		ofxRpiWS281x::BaseLED *led;
		void threadedFunction();
};
