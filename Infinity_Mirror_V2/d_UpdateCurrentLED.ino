void UpdateCurrentLED() { 
  //keeps track of which LED currently display / updated with a new colour 
  //and then resets it back to index zero when it gets to the highest index
  if (currentLED < (LED_NUM - 1))
    currentLED++;
  else
    currentLED = 0;
  delay(duration);
}