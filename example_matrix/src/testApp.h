#pragma once

#include "ofMain.h"
#include "ofxRpiWS281x.h"

class testApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void exit();
		ofxRpiWS281x::Matrix *ledMatrix;
};

