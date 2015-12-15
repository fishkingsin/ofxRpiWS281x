//Utils.cpp
#include "Utils.h"
extern "C" {
	#include "board_info.h"
	#include "clk.h"
	#include "gpio.h"
	#include "pwm.h"

	#include "ws2811.h"
	namespace ofxRPiWS281x{
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
	};
}