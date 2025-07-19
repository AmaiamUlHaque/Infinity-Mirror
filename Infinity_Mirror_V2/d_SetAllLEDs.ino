void SetAllLEDs (byte r, byte g, byte b) { //sets all LEDS to a single colour using a for loop to go through all of them
  for (int i = 0; i < LED_NUM; i++)
    LEDs[i] = CRGB(r, g, b);
  FastLED.show();
  delay(duration);
}
