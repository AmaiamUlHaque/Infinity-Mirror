#include <FastLED.h>              //the library for RGB LEDs
#define LED_PIN         13        //LED data pin
#define CHIP_SET        WS2812B   //type of RGB LED Strip
#define COLOUR_CODE     GRB       //the sequence of colours
#define LED_NUM         54        //# of LEDs in strip
CRGB LEDs[LED_NUM];               //array to hold all LEDs


//please keep these four lines in this exact order
#define DECODE_NEC
#include <Arduino.h>
#include <IRremote.hpp>        //includes the library needed for the IR remote
const int IR_RECEIVE_PIN = 2;  //declares the incoming DATA pin



int duration = 1;               //the delay between each colour/transition
byte brightness = 255;          //the desired brightness level of the LEDs (0 = off, 1 = dimmest 255 = brightest)
boolean currentState = HIGH;    //tracks the current state of power (whether the LEDs are on or off)
boolean paused = false;         //tracks whether or not the LEDs are stopped/paused at a chosen colour
int transition = 0;             //tracks the current transition to switch between each of them
byte crease = 15;               //the (in/de)crease / step for each colour inbetween the fade transition
int currentLED = 0;             //keeps track of current LED in the array for the spiral transition
int previousLEDs;               //keeps tracks of previous LEDs to update their brightness
