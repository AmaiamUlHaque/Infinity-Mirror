void IRTranslate() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData);
    buttonPressed();
    Serial.println();
    delay(100);
    IrReceiver.resume();
  }
}

void buttonPressed() {
  Serial.println(IrReceiver.decodedIRData.decodedRawData);
  Serial.println("next transition: " + String(transition));
  if (transition == 5)
    transition = 0;
  else
    transition += 1;


  switch (transition) {
    case 0:
      while (transition == 0)
        Default();
      break;
    case 1:
      while (transition == 1)
        Fade(crease);
      break;
    case 2:
      while (transition == 2)
        Spiral();
      break;
    case 3:
      while (transition == 3)
        Reload();
      break;
    case 4:
      while (transition == 4)
        Random();
      break;
    case 5:
      while (transition == 5)
        Purples();
      break;
  }
}
