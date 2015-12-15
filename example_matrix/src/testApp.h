#pragma once

#include "ofMain.h"
#include "ofxRPiWS281x.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void exit();
		ofxRPiWS281x::Matrix *ledMatrix;
};

