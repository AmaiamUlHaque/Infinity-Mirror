void setup() {
  Serial.begin(9600);
  Serial.println("\n\n\nLet the show begin!!!!!"); //program has started


  //configuration of the RGB LED strip using the FastLED library
  FastLED.addLeds<CHIP_SET, LED_PIN, COLOUR_CODE>(LEDs, LED_NUM); //adds LEDs so it is easier to use functions such as setBrightness, clear, and show
  FastLED.setMaxPowerInVoltsAndMilliamps(5,3000); //sets max power to ensure safe usage //parameters are (5,3000)
  FastLED.setBrightness(brightness); //sets the brightness of LEDs
  FastLED.clear(); //clears and previous local data
  FastLED.show(); //updates the local data and displays it


  //configuration of the IR remote using the IRremote library
  //begins the receiver to receive incoming signals
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
  //attachInterrupt(digitalPinToInterrupt(IR_RECEIVE_PIN), IRTranslate, RISING); //declares the pin, method, & activation state to setup the interrupt


  pinMode(IR_RECEIVE_PIN, INPUT_PULLUP); //declares the pin as an interrupt
  attachInterrupt(digitalPinToInterrupt(IR_RECEIVE_PIN), IRTranslate, CHANGE);
  //declares the pin number, the method name, and activation state in order for interrupt to run
  //there are three possible activation states
  //RISING activates when there is a rise in voltage
  //FALLING activates when there is a drop in voltage
  //CHANGE activates when they is either a rise or drop in voltage
}
