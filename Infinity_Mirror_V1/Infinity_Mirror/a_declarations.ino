#include <FastLED.h>              //the library for RGB LEDs
#define LED_PIN         5         //LED data pin
#define CHIP_SET        WS2812B   //type of RGB LED Strip
#define COLOUR_CODE     GRB       //the sequence of colours
#define LED_NUM         54        //# of LEDs in strip
CRGB LEDs[LED_NUM];               //array to hold all LEDs


#include <IRremote.h>     //library for the IR receiver
const int RECV_PIN = 2;   //incoming & outgoing signal pin
IRrecv irrecv (RECV_PIN); //create and name receiver object
decode_results results;   //stores incoming code/results



int duration = 1;               //the delay between each colour/transition
byte brightness = 255;          //the desired brightness level of the LEDs (0 = off, 1 = dimmest 255 = brightest)
boolean currentState = HIGH;    //tracks the current state of power (whether the LEDs are on or off)
boolean paused = false;         //tracks whether or not the LEDs are stopped/paused at a chosen colour
int transition = 0;             //tracks the current transition to switch between each of them
byte crease = 15;               //the (in/de)crease / step for each colour in between the fade transition
int currentLED = 0;             //keeps track of current LED in the array for the spiral transition
int previousLEDs;               //keeps tracks of previous LEDs to update their brightness
                                //currently this is not working how i want it to
int previousResult;             //keeps track of the most recent input received from the IR remote
