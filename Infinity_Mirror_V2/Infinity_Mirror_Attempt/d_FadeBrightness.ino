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