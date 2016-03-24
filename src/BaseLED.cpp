//BaseLED.cpp
#include "BaseLED.h"
#ifdef __cplusplus
extern "C" {
	namespace ofxRpiWS281x{
		ws2811_led_t Utils::Color(int red, int green, int blue){
			return (red << 16) | (green << 8) | blue ;
		}

		ws2811_led_t Utils::wheel(int pos) {

			if (pos < 85){
				return Color(pos * 3, 255 - pos * 3, 0);
			}
			if(pos < 170){
				pos -= 85;
				return Color(255 - pos * 3, 0, pos * 3);
			}
			else{
				pos -= 170;
				return Color(0, pos * 3, 255 - pos * 3);
			}

		}
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