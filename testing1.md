<details>
  <summary>Click to see Heading 1</summary>

  ### This is a Collapsible Heading
  This is the content associated with the collapsible heading.
</details>






<details>
  <summary>Click to see Heading 2</summary>



### Arduino Programs

#### Sketch 1: Original Code Found Online for

Sketch 1: Original Code Found Online for LEDs

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>//link:
https://www.makerguides.com/how-to-control-ws2812b-individually-addressable-leds-using-arduino/</p>
<p>#include &lt;FastLED.h&gt;</p>
<p>#define RGB_PIN 6 // LED DATA PIN</p>
<p>#define RGB_LED_NUM 10 // 10 LEDs [0...9]</p>
<p>#define BRIGHTNESS 200 // brightness range [0..255]</p>
<p>#define CHIP_SET WS2812B // types of RGB LEDs</p>
<p>#define COLOR_CODE GRB //sequence of colours in data stream</p>
<p>// Define the array of LEDs</p>
<p>CRGB LEDs[RGB_LED_NUM];</p>
<p>void setup() {</p>
<p>Serial.begin(9600); //initialise monitor and baud rate</p>
<p>Serial.println("WS2812B LEDs strip Initialize"); //program start</p>
<p>FastLED.addLeds&lt;CHIP_SET, RGB_PIN, COLOR_CODE&gt;(LEDs,
RGB_LED_NUM); //adds LEDs into a group to make it easier to use
functions (e.g. setBrightness, clear, show, etc)</p>
<p>FastLED.setBrightness(BRIGHTNESS); //sets the brightness of the LED
strip to the value of BRIGHTNESS</p>
<p>FastLED.setMaxPowerInVoltsAndMilliamps(5, 500); //sets the maximum
power to ensure safe usage</p>
<p>FastLED.clear(); //clears all local data in the LEDs, basically just
wipes it clean from any previous data</p>
<p>FastLED.show(); //used to update the Arduino about the status of the
CRGB function</p>
<p>//CRGB function responsible for the colours displayed to represent
the red, green, and blue values which can range from a byte or 0 to
255</p>
<p>//it does not show anything here though since all local data was just
removed</p>
<p>//this gives LEDs a fresh start</p>
<p>}</p>
<p>void loop() {</p>
<p>Toggle_RED_LED(); //calls on the method 'Toggle_RED_LED'</p>
<p>}</p>
<p>void Toggle_RED_LED(void) {</p>
<p>//for loop goes through each of the LEDs to make it turn red and then
back to black with 1 second delay in between</p>
<p>for (int i = 0; i &lt; RGB_LED_NUM; i++)</p>
<p>LEDs[i] = CRGB(255, 0, 0 ); //this is the rgb values needed to
represent red</p>
<p>FastLED.show();</p>
<p>delay(1000);</p>
<p>for (int i = 0; i &lt; RGB_LED_NUM; i++)</p>
<p>LEDs[i] = CRGB(0, 0, 0 );</p>
<p>FastLED.show();</p>
<p>delay(1000);</p>
<p>}</p></td>
</tr>
</tbody>
</table>

Sketch 2: Original Code Found Online for IR Receiver and Remote

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>#include &lt;IRremote.h&gt; //includes the library needed for the
IR remote</p>
<p>const int RECV_PIN = 2; //declares the incoming DATA pin</p>
<p>IRrecv irrecv (RECV_PIN); //creates and names the receiver object</p>
<p>decode_results results; //stores incoming code from 'irrecv'</p>
<p>void setup() {</p>
<p>Serial.begin(9600); //initialises serial monitor and baud rate to
9600</p>
<p>Serial.println("program start.");</p>
<p>irrecv.enableIRIn(); //begins the receiver to receive incoming
signals</p>
<p>}</p>
<p>void loop() {</p>
<p>//ensure to press each button, and record the hexadecimal (the code
that is 6 letters and numbers long)</p>
<p>//they will be needed later to code a certain task to each
corresponding button</p>
<p>if (irrecv.decode(&amp;results)) { //stores a code if a signal is
received</p>
<p>Serial.println(results.value, HEX); //prints out the code received in
hexadecimal</p>
<p>irrecv.resume(); //allows the receiver to continue to receive
incoming signals</p>
<p>}</p>
<p>}</p></td>
</tr>
</tbody>
</table>

Sketch 3: Testing Out All LEDs

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>#include &lt;FastLED.h&gt; //includes the FastLED library</p>
<p>#define RGB_PIN 6 //declares LED strip DATA pin</p>
<p>#define RGB_LED_NUM 60 //declares how many LEDs are in the strip</p>
<p>#define BRIGHTNESS 255 //declares a brightness, which ranges from 0
to 255, equivalent to a byte</p>
<p>#define CHIP_SET WS2812B //declares what type of RGB LEDs the strip
is</p>
<p>#define COLOR_CODE GRB //declares the order of the red, green, and
blue values</p>
<p>//in this case it is green, then red, then blue</p>
<p>// define the array of LEDs</p>
<p>CRGB LEDs[RGB_LED_NUM];</p>
<p>void setup() {</p>
<p>Serial.begin(9600); //initialises serial monitor and baud rate to
9600</p>
<p>Serial.println("program start.");</p>
<p>FastLED.addLeds&lt;CHIP_SET, RGB_PIN, COLOR_CODE&gt;(LEDs,
RGB_LED_NUM);</p>
<p>//adds LEDs to make in easier to use functions such as setBrightness,
clear, show, etc</p>
<p>FastLED.setBrightness(BRIGHTNESS); //sets brightness according to the
variable 'BRIGHTNESS'</p>
<p>FastLED.setMaxPowerInVoltsAndMilliamps(5, 500); //sets maximum power
for safe usage</p>
<p>FastLED.clear(); //clears any local LED data</p>
<p>FastLED.show(); //updates local RGB LED data</p>
<p>}</p>
<p>void loop() {</p>
<p>//each function makes the enitre LED strip to display a single
colour</p>
<p>//red, green, and blue are the primary colours of light</p>
<p>//with them you can make all the colours you want, specifially upto
16'777'216 colours</p>
<p>//mix all three, and you get white</p>
<p>//white is tested to ensure the LED strip can handle max power</p>
<p>//purple is displayed only because it is my favourite colour</p>
<p>AllRed();</p>
<p>AllGreen();</p>
<p>AllBlue();</p>
<p>AllWhite();</p>
<p>AllPurple();</p>
<p>}</p>
<p>//each method uses a for loop to set each LED in the array to the
written hexcode</p>
<p>//then clears the local data stored on it</p>
<p>//returning all the LEDs to black</p>
<p>void AllRed() {</p>
<p>SetAllLEDs(255, 0, 0 );</p>
<p>delay(3500);</p>
<p>FastLED.clear();</p>
<p>delay(1500);</p>
<p>}</p>
<p>void AllGreen() {</p>
<p>SetAllLEDs(0, 255, 0 );</p>
<p>delay(3500);</p>
<p>FastLED.clear();</p>
<p>delay(1500);</p>
<p>}</p>
<p>void AllBlue() {</p>
<p>SetAllLEDs(0, 0, 255 );</p>
<p>delay(3500);</p>
<p>FastLED.clear();</p>
<p>delay(1500);</p>
<p>}</p>
<p>void AllWhite() {</p>
<p>SetAllLEDs(255, 255, 255 );</p>
<p>delay(3500);</p>
<p>FastLED.clear();</p>
<p>delay(1500);</p>
<p>}</p>
<p>void AllPurple() {</p>
<p>SetAllLEDs(255, 0, 255 );</p>
<p>delay(3500);</p>
<p>FastLED.clear();</p>
<p>delay(1500);</p>
<p>}</p>
<p>void SetAllLEDs (byte r, byte g, byte b) {</p>
<p>//sets all LEDS to a single colour using a for loop to go through
each LED</p>
<p>//only needs the parameters of each rgb value</p>
<p>for (int i = 0; i &lt; LED_NUM; i++)</p>
<p>LEDs[i] = CRGB(r, g, b);</p>
<p>FastLED.show();</p>
<p>}</p></td>
</tr>
</tbody>
</table>

Sketch 4 : IR Remote Switch Cases

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>#include &lt;IRremote.h&gt; //includes the library needed for the
IR remote</p>
<p>const int RECV_PIN = 2; //declares the incoming DATA pin</p>
<p>IRrecv irrecv (RECV_PIN); //creates and names the receiver object</p>
<p>decode_results results; //stores incoming code from 'irrecv'</p>
<p>void setup() {</p>
<p>Serial.begin(9600); //initialises serial monitor and baud rate to
9600</p>
<p>Serial.println("program start.");</p>
<p>irrecv.enableIRIn(); //begins the receiver to receive incoming
signals</p>
<p>}</p>
<p>void loop() {</p>
<p>//ensure to press each button, and record the hexadecimal (the code
that is 6 letters and numbers long)</p>
<p>//they will be needed later to code a certain task to each
corresponding button</p>
<p>if (irrecv.decode(&amp;results)) { //stores a code if a signal is
received</p>
<p>Serial.println(results.value, HEX); //prints out the code received in
hexadecimal</p>
<p>irrecv.resume(); //allows the receiver to contune to receive incoming
signals</p>
<p>switch (results.value) {</p>
<p>//depending the results of the incoming signals, a certain task is
done</p>
<p>//in this case it prints what button was pressed to the serial
monitor</p>
<p>case 0xFFA25D:</p>
<p>Serial.println("CH- button has been pressed");</p>
<p>break;</p>
<p>case 0xFF629D:</p>
<p>Serial.println("CH button has been pressed");</p>
<p>break;</p>
<p>case 0xFFE21D:</p>
<p>Serial.println("CH+ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF22DD:</p>
<p>Serial.println("PREV button has been pressed");</p>
<p>break;</p>
<p>case 0xFF02FD:</p>
<p>Serial.println("NEXT button has been pressed");</p>
<p>break;</p>
<p>case 0xFFC23D:</p>
<p>Serial.println("PAUSE button has been pressed");</p>
<p>break;</p>
<p>case 0xFFE01F:</p>
<p>Serial.println("VOL- button has been pressed");</p>
<p>break;</p>
<p>case 0xFFA857:</p>
<p>Serial.println("VOL+ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF906F:</p>
<p>Serial.println("EQ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF6897:</p>
<p>Serial.println("0 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF9867:</p>
<p>Serial.println("+100 button has been pressed");</p>
<p>break;</p>
<p>case 0xFFB04F:</p>
<p>Serial.println("+200 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF30CF:</p>
<p>Serial.println("1 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF18E7:</p>
<p>Serial.println("2 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF7A85:</p>
<p>Serial.println("3 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF10EF:</p>
<p>Serial.println("4 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF38C7:</p>
<p>Serial.println("5 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF5AA5:</p>
<p>Serial.println("6 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF42BD:</p>
<p>Serial.println("7 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF4AB5:</p>
<p>Serial.println("8 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF52AD:</p>
<p>Serial.println("9 button has been pressed");</p>
<p>break;</p>
<p>}</p>
<p>}</p>
<p>}</p></td>
</tr>
</tbody>
</table>

Sketch 5: IR Remote Interrupt

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>#include &lt;IRremote.h&gt; //includes the library needed for the
IR remote</p>
<p>const int RECV_PIN = 2; //declares the incoming DATA pin</p>
<p>IRrecv irrecv (RECV_PIN); //creates and names the receiver object</p>
<p>decode_results results; //stores incoming code from 'irrecv'</p>
<p>void setup() {</p>
<p>Serial.begin(9600); //initialises serial monitor and baud rate to
9600</p>
<p>Serial.println("program start.");</p>
<p>irrecv.enableIRIn(); //begins the receiver to receive incoming
signals</p>
<p>pinMode(RECV_PIN, INPUT_PULLUP); //declares the pin as an
interrupt</p>
<p>attachInterrupt(digitalPinToInterrupt(RECV_PIN), eee, CHANGE);</p>
<p>//declares the pin number, the method name, and activation state in
order for interrupt to run</p>
<p>//there are three possible activation states</p>
<p>//RISING activates when there is a rise in voltage</p>
<p>//FALLING activates when there is a drop in voltage\</p>
<p>//CHANGE activates when they is either a rise or drop in voltage</p>
<p>}</p>
<p>void loop() {</p>
<p>Serial.println("on standby...");</p>
<p>delay(2500);</p>
<p>}</p>
<p>void IRTranslate() {</p>
<p>//this ensures that the interrupt is working if certain button
outputs are printed to the serial monitor</p>
<p>//depending on what button is pressed, a certain task is carried
out</p>
<p>if (irrecv.decode(&amp;results)) { //stores a code if a signal is
received</p>
<p>Serial.println(results.value, HEX); //prints out the code received in
hexadecimal</p>
<p>irrecv.resume(); //allows the receiver to contune to receive incoming
signals</p>
<p>switch (results.value) {</p>
<p>//depending the results of the incoming signals, a certain task is
done</p>
<p>//in this case it prints what button was pressed to the serial
monitor</p>
<p>case 0xFFA25D:</p>
<p>Serial.println("CH- button has been pressed");</p>
<p>break;</p>
<p>case 0xFF629D:</p>
<p>Serial.println("CH button has been pressed");</p>
<p>break;</p>
<p>case 0xFFE21D:</p>
<p>Serial.println("CH+ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF22DD:</p>
<p>Serial.println("PREV button has been pressed");</p>
<p>break;</p>
<p>case 0xFF02FD:</p>
<p>Serial.println("NEXT button has been pressed");</p>
<p>break;</p>
<p>case 0xFFC23D:</p>
<p>Serial.println("PAUSE button has been pressed");</p>
<p>break;</p>
<p>case 0xFFE01F:</p>
<p>Serial.println("VOL- button has been pressed");</p>
<p>break;</p>
<p>case 0xFFA857:</p>
<p>Serial.println("VOL+ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF906F:</p>
<p>Serial.println("EQ button has been pressed");</p>
<p>break;</p>
<p>case 0xFF6897:</p>
<p>Serial.println("0 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF9867:</p>
<p>Serial.println("+100 button has been pressed");</p>
<p>break;</p>
<p>case 0xFFB04F:</p>
<p>Serial.println("+200 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF30CF:</p>
<p>Serial.println("1 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF18E7:</p>
<p>Serial.println("2 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF7A85:</p>
<p>Serial.println("3 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF10EF:</p>
<p>Serial.println("4 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF38C7:</p>
<p>Serial.println("5 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF5AA5:</p>
<p>Serial.println("6 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF42BD:</p>
<p>Serial.println("7 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF4AB5:</p>
<p>Serial.println("8 button has been pressed");</p>
<p>break;</p>
<p>case 0xFF52AD:</p>
<p>Serial.println("9 button has been pressed");</p>
<p>break;</p>
<p>}</p>
<p>}</p>
<p>}</p></td>
</tr>
</tbody>
</table>

Sketch 6: Final Version -

*\*Note - this is much neater in the .INO file.*

<table>
<colgroup>
<col style="width: 100%" />
</colgroup>
<tbody>
<tr>
<td><p>/*</p>
<p>Amaiam ul Haque</p>
<p>Last Updated: Jan 26, 2023</p>
<p>Description:********************************************************************************************</p>
<p>Let's-a-go! *insert super mario bros theme*</p>
<p>*/</p>
<p>/* Note:</p>
<p>* Since this file has multiple tabs,</p>
<p>* each of them run in a specific order.</p>
<p>* It will always start off with the tab that the folder is named
after,</p>
<p>* and then the rest is determined by their alphabetical order.</p>
<p>* Which is why each tab starts with a,b,c, so on and so forth,</p>
<p>* and if there is a second letter following the first one,</p>
<p>* this is meant to serve as some sort of a subsection.</p>
<p>*</p>
<p>* For example,</p>
<p>* the transitions tabs start with the letter 'f',</p>
<p>* while each different type of transition have their own
tab/subsection (fa, fb, fc...)</p>
<p>*</p>
<p>* But in this case the only tabs that have to be in order are the
declarations, setup, and loop.</p>
<p>* Since all the other tabs are methods and will not run until called
upon.</p>
<p>*/</p>
<p>#include &lt;FastLED.h&gt; //the library for RGB LEDs</p>
<p>#define LED_PIN 5 //LED data pin</p>
<p>#define CHIP_SET WS2812B //type of RGB LED Strip</p>
<p>#define COLOUR_CODE GRB //the sequence of colours</p>
<p>#define LED_NUM 54 //# of LEDs in strip</p>
<p>CRGB LEDs[LED_NUM]; //array to hold all LEDs</p>
<p>#include &lt;IRremote.h&gt; //library for the IR receiver</p>
<p>const int RECV_PIN = 2; //incoming &amp; outgoing signal pin</p>
<p>IRrecv irrecv (RECV_PIN); //create and name receiver object</p>
<p>decode_results results; //stores incoming code/results</p>
<p>int duration = 1; //the delay between each colour/transition</p>
<p>byte brightness = 255; //the desired brightness level of the LEDs (0
= off, 1 = dimmest 255 = brightest)</p>
<p>boolean currentState = HIGH; //tracks the current state of power
(whether the LEDs are on or off)</p>
<p>boolean paused = false; //tracks whether or not the LEDs are
stopped/paused at a chosen colour</p>
<p>int transition = 0; //tracks the current transition to switch between
each of them</p>
<p>byte crease = 15; //the (in/de)crease / step for each colour in
between the fade transition</p>
<p>int currentLED = 0; //keeps track of current LED in the array for the
spiral transition</p>
<p>int previousLEDs; //keeps tracks of previous LEDs to update their
brightness</p>
<p>//currently this is not working how i want it to</p>
<p>int previousResult; //keeps track of the most recent input received
from the IR remote</p>
<p>void setup() {</p>
<p>Serial.begin(9600);</p>
<p>Serial.println("Let the show begin!!!"); //program has started</p>
<p>//configuration of the RGB LED strip using the FastLED library</p>
<p>FastLED.addLeds&lt;CHIP_SET, LED_PIN, COLOUR_CODE&gt;(LEDs, LED_NUM);
//adds LEDs so it is easier to use functions such as setBrightness,
clear, and show</p>
<p>FastLED.setMaxPowerInVoltsAndMilliamps(5, 3000); //sets max power to
ensure safe usage</p>
<p>FastLED.setBrightness(brightness); //sets the brightness of LEDs</p>
<p>FastLED.clear(); //clears and previous local data</p>
<p>FastLED.show(); //updates the local data and displays it</p>
<p>//configuration of the IR remote using the IRremote library</p>
<p>irrecv.enableIRIn(); //IR Receiver begins receiving process</p>
<p>pinMode(RECV_PIN, INPUT_PULLUP); //declares pin as input meant for an
interrupt</p>
<p>attachInterrupt(digitalPinToInterrupt(RECV_PIN), IRTranslate,
RISING); //declares the pin, method, &amp; activation state to setup the
interrupt</p>
<p>}</p>
<p>//void loop() { //this is what is supposed to run if the IRTranslate
method worked.</p>
<p>// Default();</p>
<p>//}</p>
<p>void loop() {</p>
<p>//since the IRTranslate method is not working, code will have to go
through them each maually</p>
<p>//everything below is just for easy copy paste</p>
<p>//sets brightness and duration to what a value that the IR remote
could have done and goes through each transition</p>
<p>brightness = 75;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 10;</p>
<p>Default();</p>
<p>brightness = 175;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 5;</p>
<p>Default();</p>
<p>brightness = 255;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 1;</p>
<p>Default();</p>
<p>Fade(crease);//this one only has duraution of one since it takes
really long</p>
<p>brightness = 75;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 10;</p>
<p>for (int i = 0; i &lt; 5; i++)</p>
<p>Spiral();</p>
<p>brightness = 175;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 5;</p>
<p>for (int i = 0; i &lt; 7; i++)</p>
<p>Spiral();</p>
<p>brightness = 255;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 1;</p>
<p>for (int i = 0; i &lt; 10; i++)</p>
<p>Spiral();</p>
<p>brightness = 75;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 10;</p>
<p>for (int i = 0; i &lt; 5; i++)</p>
<p>Reload();</p>
<p>brightness = 175;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 5;</p>
<p>for (int i = 0; i &lt; 7; i++)</p>
<p>Reload();</p>
<p>brightness = 255;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 1;</p>
<p>for (int i = 0; i &lt; 10; i++)</p>
<p>Reload();</p>
<p>brightness = 75;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 10;</p>
<p>for (int i = 0; i &lt; 100; i++)</p>
<p>Random();</p>
<p>brightness = 175;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 5;</p>
<p>for (int i = 0; i &lt; 250; i++)</p>
<p>Random();</p>
<p>brightness = 255;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 1;</p>
<p>for (int i = 0; i &lt; 555; i++)</p>
<p>Random();</p>
<p>brightness = 175;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 5;</p>
<p>Purples();</p>
<p>brightness = 255;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>duration = 1;</p>
<p>Purples();</p>
<p>}</p>
<p>//eee</p>
<p>void IRTranslate() {</p>
<p>if (irrecv.decode(&amp;results)) {</p>
<p>delay(100);</p>
<p>irrecv.resume();</p>
<p>//stores the most recent input to avoid repeats</p>
<p>//0xFFFFFFFF is the code received when a repeat is consecutive button
pressed</p>
<p>if (results.value == 0xFFFFFFFF)</p>
<p>results.value = previousResult;</p>
<p>else</p>
<p>previousResult = results.value;</p>
<p>Serial.println("Current result = " + (results.value, HEX));</p>
<p>Serial.println("Previous result = " + previousResult);</p>
<p>switch (results.value) {</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFFA25D: //turns on and off the LEDS</p>
<p>Serial.println("CH- button has been pressed");</p>
<p>Serial.println("CH- = power");</p>
<p>if (currentState == HIGH) { //to turn off</p>
<p>currentState == LOW;</p>
<p>FastLED.setBrightness(0);</p>
<p>while (currentState == LOW)</p>
<p>delay(50);</p>
<p>}</p>
<p>else { //to turn on</p>
<p>currentState == HIGH;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>}</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF22DD: //decreases the speed of transitions</p>
<p>Serial.println("PREV button has been pressed");</p>
<p>Serial.println("PREV = -speed");</p>
<p>if (duration &gt;= 50)</p>
<p>duration -= 50;</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF02FD: //increases the speed of transitions</p>
<p>Serial.println("NEXT button has been pressed");</p>
<p>Serial.println("NEXT = +speed");</p>
<p>if (duration &lt;= 2500)</p>
<p>duration += 50;</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFFC23D: //pauses the code and allows the current colour to
only be displayed</p>
<p>Serial.println("PAUSE button has been pressed");</p>
<p>Serial.println("PAUSE/PLAY");</p>
<p>if (paused == false) { //to pause</p>
<p>paused = true;</p>
<p>while (paused == true)</p>
<p>delay (250);</p>
<p>}</p>
<p>else //to play/continue</p>
<p>paused = false;</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFFE01F: //decreases the brightness of LEDs</p>
<p>Serial.println("VOL- button has been pressed");</p>
<p>Serial.println("VOL- = -brightness");</p>
<p>if (brightness &gt;= 15) {</p>
<p>brightness -= 15;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>}</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFFA857: //increases the brightness of LEDs</p>
<p>Serial.println("VOL+ button has been pressed");</p>
<p>Serial.println("VOL+ = +brightness");</p>
<p>if (brightness &lt;= 240) {</p>
<p>brightness += 15;</p>
<p>FastLED.setBrightness(brightness);</p>
<p>}</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF906F: //swaps between all the dfferent transitions</p>
<p>Serial.println("EQ button has been pressed");</p>
<p>Serial.println("EQ = transition");</p>
<p>if (transition == 5)</p>
<p>transition = 0;</p>
<p>else</p>
<p>transition += 1;</p>
<p>switch (transition) {</p>
<p>case 0:</p>
<p>while (transition == 0)</p>
<p>Default();</p>
<p>break;</p>
<p>case 1:</p>
<p>while (transition == 1)</p>
<p>Fade(crease);</p>
<p>break;</p>
<p>case 2:</p>
<p>while (transition == 2)</p>
<p>Spiral();</p>
<p>break;</p>
<p>case 3:</p>
<p>while (transition == 3)</p>
<p>Reload();</p>
<p>break;</p>
<p>case 4:</p>
<p>while (transition == 4)</p>
<p>Random();</p>
<p>break;</p>
<p>case 5:</p>
<p>while (transition == 5)</p>
<p>Purples();</p>
<p>break;</p>
<p>}</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF38C7: //displays only purple</p>
<p>Serial.println("5 button has been pressed");</p>
<p>Serial.println("5 = purple");</p>
<p>SetAllLEDs(255, 0, 255);</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF42BD: //display icy white</p>
<p>Serial.println("7 button has been pressed");</p>
<p>Serial.println("7 = icy white");</p>
<p>SetAllLEDs(212, 235, 255);</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF4AB5: //display only white</p>
<p>Serial.println("8 button has been pressed");</p>
<p>Serial.println("8 = white");</p>
<p>SetAllLEDs(255, 255, 255);</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>case 0xFF52AD: //display warm white</p>
<p>Serial.println("9 button has been pressed");</p>
<p>Serial.println("9 = warm white");</p>
<p>SetAllLEDs(255, 244, 229);</p>
<p>break;</p>
<p>//---------------------------------------------------------------------------------------</p>
<p>// default:</p>
<p>// //Serial.println("One of the following buttons have been
pressed.\n\tCH \n\tCH+ \n\t0 \n\t+100 \n\t+200 \n\t1 \n\t2 \n\t3 \n\t4
\n\t6");</p>
<p>// //CH=FF629D, CH+=FFE21D, 0=FF6897, +100=FF9867, +200=FFB04F,
1=FF30CF, 2=FF18E7, 3=FF7A85, 4=FF10EF, 6=FF5AA5</p>
<p>// Serial.println("One of the following buttons have been pressed;
CH, CH+, 0, +100, +200, 1, 2, 3, 4, 6");</p>
<p>// break;</p>
<p>}</p>
<p>}</p>
<p>}</p>
<p>void SetAllLEDs (byte r, byte g, byte b) { //sets all LEDS to a
single colour using a for loop to go through all of them</p>
<p>for (int i = 0; i &lt; LED_NUM; i++)</p>
<p>LEDs[i] = CRGB(r, g, b);</p>
<p>FastLED.show();</p>
<p>delay(duration);</p>
<p>}</p>
<p>void FadeBrightness(byte r, byte g, byte b) {//steadily increases and
then decreases brightness of all LEDs based on the current colour</p>
<p>for (byte i = 0; i &lt; brightness; i++) {</p>
<p>FastLED.setBrightness(i);</p>
<p>SetAllLEDs(r, g, b);</p>
<p>FastLED.show();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = brightness; i &gt; 0; i--) {</p>
<p>FastLED.setBrightness(i);</p>
<p>SetAllLEDs(r, g, b);</p>
<p>FastLED.show();</p>
<p>delay(duration);</p>
<p>}</p>
<p>}</p>
<p>void UpdateCurrentLED() {</p>
<p>//keeps track of which LED currently display / updated with a new
colour</p>
<p>//and then resets it back to index zero when it gets to the highest
index</p>
<p>if (currentLED &lt; (LED_NUM - 1))</p>
<p>currentLED++;</p>
<p>else</p>
<p>currentLED = 0;</p>
<p>delay(duration);</p>
<p>}</p>
<p>void FadePreviousLED(byte r, byte g, byte b) {//a way to keep track
of past LEDs with new colours</p>
<p>for (byte i = 1; i &lt;= 17; i++) {</p>
<p>//since their is no setBrightness function for a single LED</p>
<p>//reducing the amount of red/green/blue will make it appear to be
dimmer</p>
<p>r = r * i / 17;</p>
<p>g = g * i / 17;</p>
<p>b = b * i / 17;</p>
<p>//keeps tracks of the previous LEDS for upto 17 behind of the
currentLED</p>
<p>if (i &gt; currentLED)</p>
<p>previousLEDs = LED_NUM - i - currentLED;</p>
<p>else</p>
<p>previousLEDs = currentLED - i;</p>
<p>}</p>
<p>}</p>
<p>void Default() { //goes through all 16777216 possible colours with a
smooth transition without any significant change</p>
<p>for (byte i = 0; i &lt; 255; i++) //red to yellow</p>
<p>SetAllLEDs(255, i, 0);</p>
<p>for (byte i = 255; i &gt; 0; i--) //yellow to green</p>
<p>SetAllLEDs(i, 255, 0);</p>
<p>for (byte i = 0; i &lt; 255; i++) //green to cyan</p>
<p>SetAllLEDs(0, 255, i);</p>
<p>for (byte i = 255; i &gt; 0; i--) //cyan to blue</p>
<p>SetAllLEDs(0, i, 255);</p>
<p>for (byte i = 0; i &lt; 255; i++) //blue to purple</p>
<p>SetAllLEDs(i, 0, 255);</p>
<p>for (byte i = 255; i &gt; 0; i--) //purple to red</p>
<p>SetAllLEDs(255, 0, i);</p>
<p>}</p>
<p>void Fade(byte crease) {//basically default transition but it slowly
becomes brighter and until max desired brightness</p>
<p>//and then slowly fades until completely dark</p>
<p>for (byte i = 0; i &lt; 255; i += crease) //red to yellow</p>
<p>FadeBrightness(255, i, 0);</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) //yellow to green</p>
<p>FadeBrightness(i, 255, 0);</p>
<p>for (byte i = 0; i &lt; 255; i += crease) //green to cyan</p>
<p>FadeBrightness(0, 255, i);</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) //cyan to blue</p>
<p>FadeBrightness(0, i, 255);</p>
<p>for (byte i = 0; i &lt; 255; i += crease) //blue to purple</p>
<p>FadeBrightness(i, 0, 255);</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) //purple to red</p>
<p>FadeBrightness(255, 0, i);</p>
<p>}</p>
<p>void Spiral() {</p>
<p>//allows for a single LED to be a colour while going all around in a
circle not stopping while also steadily changing colours</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //red to yellow</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(255, i, 0);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //yellow to green</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(i, 255, 0);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //green to cyan</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(0, 255, i);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //cyan to blue</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(0, i, 255);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //blue to purple</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(i, 0, 255);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //purple to red</p>
<p>FastLED.clear();</p>
<p>LEDs[currentLED] = CRGB(255, 0, i);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>}</p>
<p>void Reload() {//like spiral transition but it affects all LEDs</p>
<p>//as new LEDs are updated with new colours, old LEDs are replaced</p>
<p>//all while steadily changing colours</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //red to yellow</p>
<p>LEDs[currentLED] = CRGB(255, i, 0);</p>
<p>FadePreviousLED(255, i, 0);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //yellow to green</p>
<p>LEDs[currentLED] = CRGB(i, 255, 0);</p>
<p>FadePreviousLED(i, 255, 0);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //green to cyan</p>
<p>LEDs[currentLED] = CRGB(0, 255, i);</p>
<p>FadePreviousLED(0, 255, i);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //cyan to blue</p>
<p>LEDs[currentLED] = CRGB(0, i, 255);</p>
<p>FadePreviousLED(0, i, 255);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 0; i &lt; 255; i += crease) { //blue to purple</p>
<p>LEDs[currentLED] = CRGB(i, 0, 255);</p>
<p>FadePreviousLED(i, 0, 255);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>for (byte i = 255; i &gt; 0; i -= crease) { //purple to red</p>
<p>LEDs[currentLED] = CRGB(255, 0, i);</p>
<p>FadePreviousLED(255, 0, i);</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>}</p>
<p>void Random(){ //basically is just relaod but each LED that is
updated with a new colour, is randomised</p>
<p>LEDs[currentLED] = CRGB(random(255), random(255), random(255));</p>
<p>FastLED.show();</p>
<p>UpdateCurrentLED();</p>
<p>delay(duration);</p>
<p>}</p>
<p>void Purples() {//basically just the default transition but it goes
through all the possible purples</p>
<p>for (byte i = 0; i &lt; 255; i++) // red to purple</p>
<p>SetAllLEDs(255, 0, i);</p>
<p>for (byte i = 255; i &gt; 0; i--) //purple to blue</p>
<p>SetAllLEDs(i, 0, 255);</p>
<p>for (byte i = 0; i &lt; 255; i++) //blue to purple</p>
<p>SetAllLEDs(i, 0, 255);</p>
<p>for (byte i = 0; i &lt; 255; i++) //purple to white</p>
<p>SetAllLEDs(255, i, 255);</p>
<p>//reverse start</p>
<p>for (byte i = 255; i &gt; 0; i--) //white to purple</p>
<p>SetAllLEDs(255, i, 255);</p>
<p>for (byte i = 255; i &gt; 0; i--) //purple to blue</p>
<p>SetAllLEDs(i, 0, 255);</p>
<p>for (byte i = 0; i &lt; 255; i++) //blue to purple</p>
<p>SetAllLEDs(i, 0, 255);</p>
<p>for (byte i = 255; i &gt; 0; i--) //purple to red</p>
<p>SetAllLEDs(255, 0, i);</p>
<p>}</p></td>
</tr>
</tbody>
</table>

