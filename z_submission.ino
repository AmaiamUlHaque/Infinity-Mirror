/*
   Amaiam ul Haque
   Last Updated: Jan 26, 2023
   Description:********************************************************************************************
   Let's-a-go! *insert super mario bros theme*
*/


/* Note:
 * Since this file has multiple tabs,
 * each of them run in a specific order.
 * It will always start off with the tab that the folder is named after,
 * and then the rest is determined by their alphabetical order.
 * Which is why each tab starts with a,b,c, so on and so forth,
 * and if there is a second letter following the first one, 
 * this is meant to serve as some sort of a subsection. 
 * 
 * For example, 
 * the transitions tabs start with the letter 'f',
 * while each different type of transition have their own tab/subsection (fa, fb, fc...) 
 * 
 * But in this case the only tabs that have to be in order are the declarations, setup, and loop.
 * Since all the other tabs are methods and will not run until called upon.
 */


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
                                


void setup() {
  Serial.begin(9600);
  Serial.println("Let the show begin!!!"); //program has started


  //configuration of the RGB LED strip using the FastLED library
  FastLED.addLeds<CHIP_SET, LED_PIN, COLOUR_CODE>(LEDs, LED_NUM); //adds LEDs so it is easier to use functions such as setBrightness, clear, and show
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 3000); //sets max power to ensure safe usage
  FastLED.setBrightness(brightness); //sets the brightness of LEDs
  FastLED.clear(); //clears and previous local data
  FastLED.show(); //updates the local data and displays it


  //configuration of the IR remote using the IRremote library
  irrecv.enableIRIn(); //IR Receiver begins receiving process
  pinMode(RECV_PIN, INPUT_PULLUP); //declares pin as input meant for an interrupt
  attachInterrupt(digitalPinToInterrupt(RECV_PIN), IRTranslate, RISING); //declares the pin, method, & activation state to setup the interrupt
}


//void loop() { //this is what is supposed to run if the IRTranslate method worked.
//  Default();
//}

void loop() {
  //since the IRTranslate method is not working, code will have to go through them each maually
  //everything below is just for easy copy paste


  //sets brightness and duration to what a value that the IR remote could have done and goes through each transition


  brightness = 75;
  FastLED.setBrightness(brightness);
  duration = 10;
  Default();

  brightness = 175;
  FastLED.setBrightness(brightness);
  duration = 5;
  Default();

  brightness = 255;
  FastLED.setBrightness(brightness);
  duration = 1;
  Default();


  Fade(crease);//this one only has duraution of one since it takes really long

  brightness = 75;
  FastLED.setBrightness(brightness);
  duration = 10;
  for (int i = 0; i < 5; i++)
    Spiral();

  brightness = 175;
  FastLED.setBrightness(brightness);
  duration = 5;
  for (int i = 0; i < 7; i++)
    Spiral();

  brightness = 255;
  FastLED.setBrightness(brightness);
  duration = 1;
  for (int i = 0; i < 10; i++)
    Spiral();


  brightness = 75;
  FastLED.setBrightness(brightness);
  duration = 10;
  for (int i = 0; i < 5; i++)
    Reload();

  brightness = 175;
  FastLED.setBrightness(brightness);
  duration = 5;
  for (int i = 0; i < 7; i++)
    Reload();

  brightness = 255;
  FastLED.setBrightness(brightness);
  duration = 1;
  for (int i = 0; i < 10; i++)
    Reload();

  brightness = 75;
  FastLED.setBrightness(brightness);
  duration = 10;
  for (int i = 0; i < 100; i++)
    Random();

  brightness = 175;
  FastLED.setBrightness(brightness);
  duration = 5;
  for (int i = 0; i < 250; i++)
    Random();

  brightness = 255;
  FastLED.setBrightness(brightness);
  duration = 1;
  for (int i = 0; i < 555; i++)
    Random();


  brightness = 175;
  FastLED.setBrightness(brightness);
  duration = 5;
  Purples();

  brightness = 255;
  FastLED.setBrightness(brightness);
  duration = 1;
  Purples();
}



//eee
void IRTranslate() {
  if (irrecv.decode(&results)) {
    delay(100);
    irrecv.resume();

    //stores the most recent input to avoid repeats
    //0xFFFFFFFF is the code received when a repeat is consecutive button pressed
    if (results.value == 0xFFFFFFFF)
      results.value = previousResult;
    else 
      previousResult = results.value;



    Serial.println("Current result = " + (results.value, HEX));
    Serial.println("Previous result = " + previousResult);
    switch (results.value) {
      //---------------------------------------------------------------------------------------
      case 0xFFA25D: //turns on and off the LEDS
        Serial.println("CH- button has been pressed");
        Serial.println("CH- = power");
        if (currentState == HIGH) { //to turn off
          currentState == LOW;
          FastLED.setBrightness(0);
          while (currentState == LOW)
            delay(50);
        }
        else { //to turn on
          currentState == HIGH;
          FastLED.setBrightness(brightness);
        }
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF22DD: //decreases the speed of transitions
        Serial.println("PREV button has been pressed");
        Serial.println("PREV = -speed");
        if (duration >= 50)
          duration -= 50;
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF02FD: //increases the speed of transitions
        Serial.println("NEXT button has been pressed");
        Serial.println("NEXT = +speed");
        if (duration <= 2500)
          duration += 50;
        break;
      //---------------------------------------------------------------------------------------
      case 0xFFC23D: //pauses the code and allows the current colour to only be displayed
        Serial.println("PAUSE button has been pressed");
        Serial.println("PAUSE/PLAY");
        if (paused == false) { //to pause
          paused = true;
          while (paused == true)
            delay (250);
        }
        else //to play/continue
          paused = false;
        break;
      //---------------------------------------------------------------------------------------
      case 0xFFE01F: //decreases the brightness of LEDs
        Serial.println("VOL- button has been pressed");
        Serial.println("VOL- = -brightness");
        if (brightness >= 15) {
          brightness -= 15;
          FastLED.setBrightness(brightness);
        }
        break;
      //---------------------------------------------------------------------------------------
      case 0xFFA857: //increases the brightness of LEDs
        Serial.println("VOL+ button has been pressed");
        Serial.println("VOL+ = +brightness");
        if (brightness <= 240) {
          brightness += 15;
          FastLED.setBrightness(brightness);
        }
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF906F: //swaps between all the dfferent transitions
        Serial.println("EQ button has been pressed");
        Serial.println("EQ = transition");
        if (transition == 5)
          transition = 0;
        else
          transition += 1;


        switch (transition) {
          case 0:
            while (transition == 0)
              Default();
            break;
          case 1:
            while (transition == 1)
              Fade(crease);
            break;
          case 2:
            while (transition == 2)
              Spiral();
            break;
          case 3:
            while (transition == 3)
              Reload();
            break;
          case 4:
            while (transition == 4)
              Random();
            break;
          case 5:
            while (transition == 5)
              Purples();
            break;
        }
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF38C7: //displays only purple
        Serial.println("5 button has been pressed");
        Serial.println("5 = purple");
        SetAllLEDs(255, 0, 255);
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF42BD: //display icy white
        Serial.println("7 button has been pressed");
        Serial.println("7 = icy white");
        SetAllLEDs(212, 235, 255);
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF4AB5: //display only white
        Serial.println("8 button has been pressed");
        Serial.println("8 = white");
        SetAllLEDs(255, 255, 255);
        break;
      //---------------------------------------------------------------------------------------
      case 0xFF52AD: //display warm white
        Serial.println("9 button has been pressed");
        Serial.println("9 = warm white");
        SetAllLEDs(255, 244, 229);
        break;
        //---------------------------------------------------------------------------------------
        //      default:
        //        //Serial.println("One of the following buttons have been pressed.\n\tCH \n\tCH+ \n\t0 \n\t+100 \n\t+200 \n\t1 \n\t2 \n\t3 \n\t4 \n\t6");
        //        //CH=FF629D, CH+=FFE21D, 0=FF6897, +100=FF9867, +200=FFB04F, 1=FF30CF, 2=FF18E7, 3=FF7A85, 4=FF10EF, 6=FF5AA5
        //        Serial.println("One of the following buttons have been pressed; CH, CH+, 0, +100, +200, 1, 2, 3, 4, 6");
        //        break;
    }
  }
}



void SetAllLEDs (byte r, byte g, byte b) { //sets all LEDS to a single colour using a for loop to go through all of them
  for (int i = 0; i < LED_NUM; i++)
    LEDs[i] = CRGB(r, g, b);
  FastLED.show();
  delay(duration);
}



void FadeBrightness(byte r, byte g, byte b) {//steadily increases and then decreases brightness of all LEDs based on the current colour
  for (byte i = 0; i < brightness; i++) {
    FastLED.setBrightness(i);
    SetAllLEDs(r, g, b);
    FastLED.show();
    delay(duration);
  }
  for (byte i = brightness; i > 0; i--) {
    FastLED.setBrightness(i);
    SetAllLEDs(r, g, b);
    FastLED.show();
    delay(duration);
  }
}



void UpdateCurrentLED() { 
  //keeps track of which LED currently display / updated with a new colour 
  //and then resets it back to index zero when it gets to the highest index
  if (currentLED < (LED_NUM - 1))
    currentLED++;
  else
    currentLED = 0;
  delay(duration);
}



void FadePreviousLED(byte r, byte g, byte b) {//a way to keep track of past LEDs with new colours

  for (byte i = 1; i <= 17; i++) {
    //since their is no setBrightness function for a single LED
    //reducing the amount of red/green/blue will make it appear to be dimmer
    r = r * i / 17;
    g = g * i / 17;
    b = b * i / 17;

    //keeps tracks of the previous LEDS for upto 17 behind of the currentLED
    if (i > currentLED)
      previousLEDs = LED_NUM - i - currentLED;
    else
      previousLEDs = currentLED - i;
  }
}


void Default() { //goes through all 16777216 possible colours with a smooth transition without any significant change
  for (byte i = 0; i < 255; i++)  //red to yellow
    SetAllLEDs(255, i, 0);
    
  for (byte i = 255; i > 0; i--)  //yellow to green
    SetAllLEDs(i, 255, 0);
    
  for (byte i = 0; i < 255; i++)  //green to cyan
    SetAllLEDs(0, 255, i);

  for (byte i = 255; i > 0; i--)  //cyan to blue
    SetAllLEDs(0, i, 255);

  for (byte i = 0; i < 255; i++)  //blue to purple
    SetAllLEDs(i, 0, 255);

  for (byte i = 255; i > 0; i--)  //purple to red
    SetAllLEDs(255, 0, i);
}



void Fade(byte crease) {//basically default transition but it slowly becomes brighter and until max desired brightness
  //and then slowly fades until completely dark
  
  for (byte i = 0; i < 255; i += crease)  //red to yellow
    FadeBrightness(255, i, 0);
    
  for (byte i = 255; i > 0; i -= crease)  //yellow to green
    FadeBrightness(i, 255, 0);
    
  for (byte i = 0; i < 255; i += crease)  //green to cyan
    FadeBrightness(0, 255, i);

  for (byte i = 255; i > 0; i -= crease)  //cyan to blue
    FadeBrightness(0, i, 255);

  for (byte i = 0; i < 255; i += crease)  //blue to purple
    FadeBrightness(i, 0, 255);

  for (byte i = 255; i > 0; i -= crease)  //purple to red
    FadeBrightness(255, 0, i);
}



void Spiral() {
  //allows for a single LED to be a colour while going all around in a circle not stopping while also steadily changing colours

  for (byte i = 0; i < 255; i += crease) { //red to yellow
    FastLED.clear();
    LEDs[currentLED] = CRGB(255, i, 0);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }
  for (byte i = 255; i > 0; i -= crease) { //yellow to green
    FastLED.clear();
    LEDs[currentLED] = CRGB(i, 255, 0);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 0; i < 255; i += crease) { //green to cyan
    FastLED.clear();
    LEDs[currentLED] = CRGB(0, 255, i);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 255; i > 0; i -= crease) { //cyan to blue
    FastLED.clear();
    LEDs[currentLED] = CRGB(0, i, 255);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 0; i < 255; i += crease) { //blue to purple
    FastLED.clear();
    LEDs[currentLED] = CRGB(i, 0, 255);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 255; i > 0; i -= crease) { //purple to red
    FastLED.clear();
    LEDs[currentLED] = CRGB(255, 0, i);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }
}



void Reload() {//like spiral transition but it affects all LEDs
  //as new LEDs are updated with new colours, old LEDs are replaced
  //all while steadily changing colours
  for (byte i = 0; i < 255; i += crease) { //red to yellow
    LEDs[currentLED] = CRGB(255, i, 0);
    FadePreviousLED(255, i, 0);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }
  for (byte i = 255; i > 0; i -= crease) { //yellow to green
    LEDs[currentLED] = CRGB(i, 255, 0);
    FadePreviousLED(i, 255, 0);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 0; i < 255; i += crease) { //green to cyan
    LEDs[currentLED] = CRGB(0, 255, i);
    FadePreviousLED(0, 255, i);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 255; i > 0; i -= crease) { //cyan to blue
    LEDs[currentLED] = CRGB(0, i, 255);
    FadePreviousLED(0, i, 255);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 0; i < 255; i += crease) { //blue to purple
    LEDs[currentLED] = CRGB(i, 0, 255);
    FadePreviousLED(i, 0, 255);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }

  for (byte i = 255; i > 0; i -= crease) { //purple to red
    LEDs[currentLED] = CRGB(255, 0, i);
    FadePreviousLED(255, 0, i);
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
  }
}



void Random(){ //basically is just relaod but each LED that is updated with a new colour, is randomised
    LEDs[currentLED] = CRGB(random(255), random(255), random(255));
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
}



void Purples() {//basically just the default transition but it goes through all the possible purples
  for (byte i = 0; i < 255; i++)  // red to purple
    SetAllLEDs(255, 0, i);

  for (byte i = 255; i > 0; i--)  //purple to blue
    SetAllLEDs(i, 0, 255);

  for (byte i = 0; i < 255; i++)  //blue to purple
    SetAllLEDs(i, 0, 255);
  
  for (byte i = 0; i < 255; i++)  //purple to white
    SetAllLEDs(255, i, 255);
    
  //reverse start
  for (byte i = 255; i > 0; i--)  //white to purple
    SetAllLEDs(255, i, 255);
  
  for (byte i = 255; i > 0; i--)  //purple to blue
    SetAllLEDs(i, 0, 255);
  
  for (byte i = 0; i < 255; i++)  //blue to purple
    SetAllLEDs(i, 0, 255);
 
  for (byte i = 255; i > 0; i--)  //purple to red
    SetAllLEDs(255, 0, i);
}
