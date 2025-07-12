void Fade(byte crease) {//basically default transition but it slowly becomes brighter and until max desired brightness
  //and then slowly fades until completely dark
  
  for (byte i = 0; i < 255; i += crease)  //red to yellow
    FadeBrightness(255, i, 0);
    
  for (byte i = 255; i > 0; i -= crease)  //yellow to green
    FadeBrightness(i, 255, 0);
    
  for (byte i = 0; i < 255; i += crease)  //green to cyan
    FadeBrightness(0, 255, i);

  for (byte i = 255; i > 0; i -= crease)  //cyan to blue
    FadeBrightness(0, i, 255);

  for (byte i = 0; i < 255; i += crease)  //blue to purple
    FadeBrightness(i, 0, 255);

  for (byte i = 255; i > 0; i -= crease)  //purple to red
    FadeBrightness(255, 0, i);
}
