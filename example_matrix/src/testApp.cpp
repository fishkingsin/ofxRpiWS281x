#include "testApp.h"
static int i = 0;
static int inputX,inputY;
//--------------------------------------------------------------
using namespace ofxRPiWS281x;
void testApp::setup()
{
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofLogVerbose("ledMatrix init");
	ledMatrix = new ofxRPiWS281x::Matrix();
	ledMatrix->setupMatrix(8, 8, 4, 1);
	for (int y = 0; y < ledMatrix->getMatrixWidth(); y++)
	{
		for (int x = 0; x < ledMatrix->getMatrixHeight(); x++)
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
	if(inputX>ledMatrix->getMatrixWidth()-1)
	{
		inputY++;
		inputX = 0;
		if(inputY>ledMatrix->getMatrixHeight()-1)
		{
			inputY = 0;
		}
	}

	ledMatrix->update();
}
void testApp::exit()
{
	ledMatrix->~Matrix();
}


//--------------------------------------------------------------
void testApp::update()
{
	
}


//--------------------------------------------------------------
void testApp::draw(){

}	


