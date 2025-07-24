void Random(){ //basically is just relaod but each LED that is updated with a new colour, is randomised
    LEDs[currentLED] = CRGB(random(255), random(255), random(255));
    FastLED.show();
    UpdateCurrentLED();
    delay(duration);
}