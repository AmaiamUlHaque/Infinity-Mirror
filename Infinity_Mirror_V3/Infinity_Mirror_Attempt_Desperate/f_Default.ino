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
