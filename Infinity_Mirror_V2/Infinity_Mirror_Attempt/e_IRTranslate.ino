void IRTranslate() {
  if (IrReceiver.decode()) {
    Serial.println("decoded ir command data: " + String(IrReceiver.decodedIRData.command));
    buttonPressed();
    Serial.println();
    delay(100);
    IrReceiver.resume();
  }
}

void buttonPressed() {
  switch (IrReceiver.decodedIRData.command) {
    //--------------------------------------------------------------------------------------------------
    case 69:
      Serial.println("Button pressed: CH-\t= power");
      if (currentState == HIGH) {  //to turn off
        currentState == LOW;
        FastLED.setBrightness(0);
        while (currentState == LOW)
          delay(50);
      } else {  //to turn on
        currentState == HIGH;
        FastLED.setBrightness(brightness);
      }
      break;
    //--------------------------------------------------------------------------------------------------
    case 70:
      Serial.println("Button pressed: CH");
      break;
    //--------------------------------------------------------------------------------------------------
    case 71:
      Serial.println("Button pressed: CH+");
      break;
    //--------------------------------------------------------------------------------------------------
    case 68:
      Serial.println("Button pressed: PREV\t= decrease speed");
      if (duration >= 50)
        duration -= 50;
      break;
    //--------------------------------------------------------------------------------------------------
    case 64:
      Serial.println("Button pressed: NEXT\t= increase speed");
      if (duration <= 2500)
        duration += 50;
      break;
    //--------------------------------------------------------------------------------------------------
    case 67:
      Serial.println("Button pressed: PLAY/PAUSE\t= pause");
      if (paused == false) {  //to pause
        paused = true;
        while (paused == true)
          delay(250);
      } else  //to play/continue
        paused = false;
      break;
    //--------------------------------------------------------------------------------------------------
    case 7:
      Serial.println("Button pressed: VOL-\t= decrease brightness");
      if (brightness >= 15) {
        brightness -= 15;
        FastLED.setBrightness(brightness);
      }
      break;
    //--------------------------------------------------------------------------------------------------
    case 21:
      Serial.println("Button pressed: VOL+\t= increase brightness");
      if (brightness <= 240) {
        brightness += 15;
        FastLED.setBrightness(brightness);
      }
      break;
    //--------------------------------------------------------------------------------------------------
    case 9:
      Serial.println("Button pressed: EQ\t= next transition");
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
    //--------------------------------------------------------------------------------------------------
    case 22:
      Serial.println("Button pressed: 0");
      break;
    //--------------------------------------------------------------------------------------------------
    case 25:
      Serial.println("Button pressed: 100+");
      break;
    //--------------------------------------------------------------------------------------------------
    case 13:
      Serial.println("Button pressed: 200+");
      break;
    //--------------------------------------------------------------------------------------------------
    case 12:
      Serial.println("Button pressed: 1");
      break;
    //--------------------------------------------------------------------------------------------------
    case 24:
      Serial.println("Button pressed: 2");
      break;
    //--------------------------------------------------------------------------------------------------
    case 94:
      Serial.println("Button pressed: 3");
      break;
    //--------------------------------------------------------------------------------------------------
    case 8:
      Serial.println("Button pressed: 4\t= icy purple");
      SetAllLEDs(204, 204, 255);
      break;
    //--------------------------------------------------------------------------------------------------
    case 28:
      Serial.println("Button pressed: 5\t= purple");
      SetAllLEDs(255, 0, 255);
      break;
    //--------------------------------------------------------------------------------------------------
    case 90:
      Serial.println("Button pressed: 6\t= lilac");
      SetAllLEDs(214, 180, 252);
      break;
    //--------------------------------------------------------------------------------------------------
    case 66:
      Serial.println("Button pressed: 7\t= icy white");
      SetAllLEDs(212, 235, 255);
      break;
    //--------------------------------------------------------------------------------------------------
    case 82:
      Serial.println("Button pressed: 8\t= white");
      SetAllLEDs(255, 255, 255);
      break;
    //--------------------------------------------------------------------------------------------------
    case 74:
      Serial.println("Button pressed: 9\t= warm white");
      SetAllLEDs(255, 244, 229);
      break;
    //--------------------------------------------------------------------------------------------------
    default:
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    Serial.println(IrReceiver.decodedIRData.command);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      Serial.println("Received noise or an unknown (or not yet enabled) protocol");
      IrReceiver.printIRResultShort(&Serial);
    }
      break;
  }
}
