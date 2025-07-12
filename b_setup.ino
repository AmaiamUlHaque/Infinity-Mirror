void setup() {
  Serial.begin(9600);
  Serial.println("Let the show begin!!!"); //program has started


  //configuration of the RGB LED strip using the FastLED library
  FastLED.addLeds<CHIP_SET, LED_PIN, COLOUR_CODE>(LEDs, LED_NUM); //adds LEDs so it is easier to use functions such as setBrightness, clear, and show
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 3000); //sets max power to ensure safe usage
  FastLED.setBrightness(brightness); //sets the brightness of LEDs
  FastLED.clear(); //clears and previous local data
  FastLED.show(); //updates the local data and displays it


  //configuration of the IR remote using the IRremote library
  irrecv.enableIRIn(); //IR Receiver begins receiving process
  pinMode(RECV_PIN, INPUT_PULLUP); //declares pin as input meant for an interrupt
  attachInterrupt(digitalPinToInterrupt(RECV_PIN), IRTranslate, RISING); //declares the pin, method, & activation state to setup the interrupt
}
