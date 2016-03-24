#pragma once

#include "ofMain.h"
#include "ofxRpiWS281x.h"
class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void exit();
		

		ofxRpiWS281x::BaseLED *led;
};
