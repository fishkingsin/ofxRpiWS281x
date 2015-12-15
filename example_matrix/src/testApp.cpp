#include "testApp.h"
static int i = 0;
static int inputX,inputY;
//--------------------------------------------------------------
using namespace ofxRPiWS281x;
void testApp::setup()
{
	// ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogVerbose("ledMatrix init");
	ledMatrix = new ofxRPiWS281x::Matrix();
	ledMatrix->setupMatrix(8, 8, 4, 1);
	
	
	
}
void testApp::exit()
{
	ledMatrix->~Matrix();
}


//--------------------------------------------------------------
void testApp::update()
{
	for (int y = 0; y < ledMatrix->getHeight(); y++)
	{
		for (int x = 0; x < ledMatrix->getWidth(); x++)
		{
			if(x==inputX && y==inputY)
			{
				ledMatrix->drawMatrix(x, y, ofColor(255,255,255));
			}
			else{
				ledMatrix->drawMatrix( x, y, ofColor(0,0,0));
			}
			
		}
	}
	i++;
	inputX++;
	if(inputX>ledMatrix->getWidth()-1)
	{
		inputY++;
		inputX = 0;
		if(inputY>ledMatrix->getHeight()-1)
		{
			inputY = 0;
		}
	}

	ledMatrix->update();
}


//--------------------------------------------------------------
void testApp::draw(){
	ledMatrix->update();
}	


