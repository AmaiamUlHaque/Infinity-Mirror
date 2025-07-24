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
