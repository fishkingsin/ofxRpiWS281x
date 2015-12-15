#include "ofApp.h"
#ifdef __cplusplus
extern "C"{
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

    #define TARGET_FREQ                              WS2811_TARGET_FREQ
    #define GPIO_PIN                                 18
    #define DMA                                      5

    #define WIDTH                                    64
    #define HEIGHT                                   1
    #define LED_COUNT                                (WIDTH * HEIGHT)

    ws2811_t ledstring;

    ws2811_led_t matrix[WIDTH][HEIGHT];



    void matrix_render(void)
    {
        int x, y;

        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[x][y];
            }
        }
    }

    void matrix_render_black(int c)
    {
        int x, y;

        for (x = 0; x < WIDTH; x++)
        {
            for (y = 0; y < HEIGHT; y++)
            {
                ledstring.channel[0].leds[(y * WIDTH) + x] = c;
            }
        }
    }

    void matrix_raise(void)
    {
        int x, y;

        for (y = 0; y < (HEIGHT - 1); y++)
        {
            for (x = 0; x < WIDTH; x++)
            {
                matrix[x][y] = matrix[x][y + 1];
            }
        }
    }

    int dotspos[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    ws2811_led_t dotcolors[] =
    {
        0x200000,  // red
        0x202000,  // yellow
        0x002020,  // lightblue
        0x200010,  // pink
        0x002000,  // green
        0x100010,  // purple
        0x000020,  // blue
        0x201000,  // orange
    };

    ws2811_led_t Color(int red, int green, int blue){
        return (red << 16) | (green << 8) | blue ;
    }

    ws2811_led_t wheel(int pos){

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

    void matrix_bottom(void)
    {
        int i;
        static int x = 0;

        for (i = 0; i < WIDTH; i++)
        {
            // matrix[i][HEIGHT - 1] = wheel((x+i));
            matrix[i][HEIGHT - 1] = dotcolors[ (x+i)%7 & 7];
        }
        x++;
    }
    //--------------------------------------------------------------
    void ofApp::setup(){

        ledstring.freq = TARGET_FREQ;
        ledstring.dmanum = DMA;
        ledstring.channel[0].gpionum = GPIO_PIN;
        ledstring.channel[0].count = LED_COUNT;
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
    void ofApp::exit(){
        matrix_render_black(0);
        if (ws2811_render(&ledstring))
        {
            std::exit(-1);
            // break;
        }
        if (0)
        {

            void *p = malloc(32000000);
            memset(p, 42, 32000000);
            free(p);
        }
        ws2811_fini(&ledstring);
    }
    //--------------------------------------------------------------
    void ofApp::update(){
        // while (1)
        {
            matrix_raise();
            matrix_bottom();
            if (0)
            {
                void *p = malloc(64000000);
                memset(p, 42, 64000000);
                free(p);
            }
            matrix_render();

            if (ws2811_render(&ledstring))
            {
                std::exit(-1);
                // break;
            }

            // 15 frames /sec
            // usleep(500000);
        }
    }

    //--------------------------------------------------------------
    void ofApp::draw(){

    }

    //--------------------------------------------------------------
    void ofApp::keyPressed(int key){

    }

    //--------------------------------------------------------------
    void ofApp::keyReleased(int key){

    }

    //--------------------------------------------------------------
    void ofApp::mouseMoved(int x, int y){

    }

    //--------------------------------------------------------------
    void ofApp::mouseDragged(int x, int y, int button){

    }

    //--------------------------------------------------------------
    void ofApp::mousePressed(int x, int y, int button){

    }

    //--------------------------------------------------------------
    void ofApp::mouseReleased(int x, int y, int button){

    }

    //--------------------------------------------------------------
    void ofApp::windowResized(int w, int h){

    }

    //--------------------------------------------------------------
    void ofApp::gotMessage(ofMessage msg){

    }

    //--------------------------------------------------------------
    void ofApp::dragEvent(ofDragInfo dragInfo){ 

    }
}
#endif