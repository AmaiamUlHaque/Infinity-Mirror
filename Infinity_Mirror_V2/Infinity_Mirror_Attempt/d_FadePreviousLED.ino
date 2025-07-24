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
