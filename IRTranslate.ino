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
