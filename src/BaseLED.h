//BaseLED.h
#ifdef __cplusplus
#include "ofMain.h"

extern "C" {

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <signal.h>

#include "board_info.h"
#include "clk.h"
#include "gpio.h"
#include "pwm.h"

#include "ws2811.h"


#define ARRAY_SIZE(stuff)                        (sizeof(stuff) / sizeof(stuff[0]))


#define GPIO_PIN                                 18
#define DMA                                      5

#define TARGET_FREQ                              WS2811_TARGET_FREQ
	namespace ofxRpiWS281x{
		class Utils{
		public:
			static ws2811_led_t Color(int red, int green, int blue);

			static ws2811_led_t wheel(int pos) ;
			
		};
		class BaseLED{
		public:
			BaseLED();
			~BaseLED();
			void setup(int numLED, int brightness);
			
			void drawPiexls(int i ,ofColor color);
			void update();
			virtual void draw(){};
		protected:
			
			ws2811_t ledstring;
		private:
			

		};
	}
}
#endif