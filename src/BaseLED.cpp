//BaseLED.cpp
#include "BaseLED.h"
#ifdef __cplusplus
extern "C" {
	namespace ofxRPiWS281x{
		BaseLED::BaseLED(){

		}
		BaseLED::~BaseLED(){
			ws2811_fini(&ledstring);
		}
		void BaseLED::setup(int numLED, int brightness=255){
			ofLogVerbose("Init BaseLED");

			ledstring.freq = TARGET_FREQ;
		    ledstring.dmanum = DMA;
		    ledstring.channel[0].gpionum = GPIO_PIN;
		    ledstring.channel[0].count = numLED;
		    ledstring.channel[0].invert = 0;
		    ledstring.channel[0].brightness = 255;
		    ledstring.channel[1].gpionum = 0;
		    ledstring.channel[1].count = 0;
		    ledstring.channel[1].invert = 0;
		    ledstring.channel[1].brightness = 0;


		    if (board_info_init() < 0)
		    {
		        std::exit(-1);
		    }

		    

		    if (ws2811_init(&ledstring))
		    {
		        std::exit(-1);
		    }

		}

		
		void BaseLED::drawPiexls(int i ,ofColor color){
			if(i<0 || i > ledstring.channel[0].count){
				return;
			}
			ledstring.channel[0].leds[i] = Utils::Color(color.r,color.g,color.b);		
		}
		void BaseLED::update(){
			if(ws2811_render(&ledstring))
			{
				ofLogError("ws2811_render failed");
				exit(-1);	
				
			}

		}
	}
}
#endif