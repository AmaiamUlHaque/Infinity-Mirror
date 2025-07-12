void Purples() {                  //basically just the default transition but it goes through all the possible purples
  for (byte i = 0; i < 255; i++)  // red to purple
    SetAllLEDs(255, 0, i);

  for (byte i = 255; i > 0; i--)  //purple to blue
    SetAllLEDs(i, 0, 255);

  for (byte i = 0; i < 255; i++)  //blue to purple
    SetAllLEDs(i, 0, 255);

  for (byte i = 0; i < 255; i++)  //purple to white
    SetAllLEDs(255, i, 255);

  //reverse start
  for (byte i = 255; i > 0; i--)  //white to purple
    SetAllLEDs(255, i, 255);

  for (byte i = 255; i > 0; i--)  //purple to blue
    SetAllLEDs(i, 0, 255);

  for (byte i = 0; i < 255; i++)  //blue to purple
    SetAllLEDs(i, 0, 255);

  for (byte i = 255; i > 0; i--)  //purple to red
    SetAllLEDs(255, 0, i);
}
