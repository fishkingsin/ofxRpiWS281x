//Matrix.h
#pragma once

#include "ofMain.h"
#include "BaseLED.h"

#define MATRIX_W                                 8
#define MATRIX_H                                 8
#define MATRIX_TOTAL                             (MATRIX_W*MATRIX_H)
#define MATRIX_COL                               4
#define MATRIX_ROW                               1


#define WIDTH                                    (MATRIX_W*MATRIX_COL)
#define HEIGHT                                   (MATRIX_W*MATRIX_ROW)
#define LED_COUNT                                (WIDTH * HEIGHT)
using namespace std;
namespace ofxRPiWS281x{
	class Matrix : public BaseLED{
	public:
		Matrix();
		void setupMatrix(int _matrixWidth 
			, int _matrixHeight 
			, int _matrixColum 
			, int _matrixRow );
		~Matrix();
		void draw();
		// void setupStrip(int numPixes){};
		// void setupGrid(){};
		
		void drawMatrix(int x, int y ,ofColor color);
		int getWidth();
		int getHeight();
		int getMatrixWidth();
		int getMatrixHeight();
		int getMatrixColum();
		int getMatrixRow();
	
	private:
		int remapIndex(int x, int y);
		int matrixHeight;
		int matrixWidth;
		int matrixColum;
		int matrixRow;
		int totalMatrix;
		int ledWidth;
		int ledHeight;
		int totalLED;


	};
}
