//Matrix.cpp
#include "Matrix.h"

namespace ofxRpiWS281x{

	Matrix::Matrix()
	{

	}
	void Matrix::setupMatrix(int _matrixWidth, int _matrixHeight, int _matrixColum, int _matrixRow){
		
		matrixColum = _matrixColum;
		matrixRow = _matrixRow;
		matrixWidth = _matrixWidth;
		matrixHeight = _matrixHeight;

		totalMatrix = matrixWidth * matrixHeight;
		ledWidth = matrixWidth * matrixColum;
		ledHeight = matrixHeight * matrixRow;
		totalLED = ledWidth*ledHeight;

		BaseLED::setup(totalLED, 255);

		
	}
	Matrix::~Matrix()
	{
		for(int i = 0 ; i < totalLED ;i++)
		{
			drawPiexls(i,ofColor(0,0,0));
		}
        update();
        if (0)
        {

            void *p = malloc(32000000);
            memset(p, 42, 32000000);
            free(p);
        }
		ws2811_fini(&ledstring);
	}
	void Matrix::draw(){
		for(int y = 0 ; y < getHeight() ;y++)
		{
			for(int x = 0 ; x < getWidth() ;x++)
			{
				ofRect(0,0,getWidth(),getHeight());
			}
		}
	}
	// void setupStrip(int numPixes){};
	// void setupGrid(){};
	void Matrix::drawMatrix(int x, int y ,ofColor color){
		drawPiexls( remapIndex(x, y), color);		
	}
	int Matrix::getWidth(){
		return ledWidth;
	}
	int Matrix::getHeight(){
		return ledHeight;
	}

	int Matrix::getMatrixWidth(){
		return matrixWidth;
	}
	int Matrix::getMatrixHeight(){
		return matrixHeight;
	}
	int Matrix::getMatrixColum(){
		return matrixColum;
	}
	int Matrix::getMatrixRow(){
		return matrixRow;
	}
	int Matrix::remapIndex(int x, int y){
		int mod = y%2;
		
		int block = ((( y / (matrixHeight ))* matrixColum )+( x / (matrixWidth ))) * totalMatrix;
		int tX = (mod==1)?(matrixWidth -1)- (x% matrixWidth):(x% matrixWidth);
		int tY = (y% matrixHeight)* matrixWidth;
		return block+tX+tY;
	}
}