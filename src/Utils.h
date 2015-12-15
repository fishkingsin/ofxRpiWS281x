//Utils.h
#ifdef __cplusplus
#include "ofMain.h"

extern "C" {
	#include "board_info.h"
	#include "clk.h"
	#include "gpio.h"
	#include "pwm.h"

	#include "ws2811.h"

	namespace ofxRPiWS281x{
		class Utils{
		public:
			static ws2811_led_t Color(int red, int green, int blue);

			static ws2811_led_t wheel(int pos) ;
			
		};

	}
}
#endif