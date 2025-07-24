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