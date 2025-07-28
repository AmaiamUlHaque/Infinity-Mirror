# Arduino-Powered RGB Infinity Mirror

A self-built, interactive infinity mirror featuring an individually addressable RGB LED strip controlled by an Arduino Nano and an IR remote. This project serves as both a functional mirror and a dynamic decorative piece with smooth color transitions and customizable settings.


## Table of Contents

1. [Summary](#summary)
2. [Operating Instructions](#operating-instructions)
3. [Problems & Possibilities](#problems--possibilities)
4. [Investigation & Ideas](#investigation--ideas) 
    1. [Research Findings](#research-findings)
    2. [Appendix](#appendix)
5. [Construction](#construction)
    1. [Parts List](#parts-list)
    2. [Rough Sketches](#rough-sketches)
    3. [Schematic View](#schematic-view)
    4. [Construction Chart](#construction-chart)
    5. [Arduino Programs](#arduino-programs)
    6. [Progress Pictures](#progress-pictures)
6. [Evaluation](#evaluation)
7. [Bibliography](#bibliography)


## Summary 

The infinity mirror is mainly for decorative purposes, however it serves
as a regular mirror while powered off. However, the entire story changes
when it is turned on. The smooth vivid transition that greets the user
as soon as they turn it on, along with the various settings that allow
the user to change it to their liking. It is designed purely to suit
user preferences and convenience. Well the user in this case is me,
since this is made and tweaked to my liking. As a result, the final
product is a success if I am satisfied with it. When I first started
looking into this, initially it seemed much more difficult and I did not
think that the colour transitions would be *that* eye-catching. But
after finally starting the project and getting into the colour
transitions, I have never been so immersed with just lights. When I
first succeeded in getting the transitions to finally work, I stared at
them to the point where my eyes began to hurt. Therefore, I would find
this to be a major success.

## Operating Instructions

<u>IR Remote Button Diagram:</u>

<img src=".\attachments\test1/media/image1.jpg"
style="width:2.48825in;height:4.83245in" />

<u>Instructions:</u>

*\*Note: IR Remote diagram shows the various buttons and what they are
each for.*

1.  Ensure that the power supply is charged.

2.  Turn on the infinity mirror with the use of the remote control.

    1.  If it does not turn on, check if the power supply is off by
        taking a look at the back panel. The power supply should have a
        number displaying how much it is charged out of 100%.

    2.  If it does not display a number, simply press the only button
        found on the side.

    3.  If that does not work, it may just need to charge.

3.  The default setting will automatically start on start up.

4.  To swap through the various colour transitions, click the transition
    button until you are satisfied with one.

5.  If at any given time, there is a colour that is displayed and you
    would like it to stay as it is, click the pause button.

    1.  To unpause, simply click the exact same button again.

6.  To increase or decrease the brightness, click increase / decrease
    brightness in the respective order.

7.  To increase or decrease the speed, click increase / decrease speed
    in the respective order.

8.  In order to choose purple, click the purple button.

9.  In order to choose white, click the purple white.

10. In order to choose warm white, click the warm white button.

11. In order to choose icy white, click the icy white button.

12. In order to turn it off, simply just click the power button again.

<u>Core Components:</u>

The IR remote and receiver uses interrupts in order to allow for the
user’s input to instantly start without waiting for the current section
of code to finish. It also allows for the most convenient user interface
that adjusts to their liking.

The individually addressable RGB LED strip allows for each and every
single LED to be programmed separately instead of only being able to
change the entire strip to a single colour. The desired user input to be
outputted to showcase whatever the user wants to see. It is solely for
visual purposes.

## Problems & Possibilities

There were only a few, yet crucial limitations to this project.

One of the major limitations would be time constraints. If I had more
time, I would have liked to program a few more features. I had
originally planned to add in a setting that would allow users to set
their own colour transition range. For example they would be able to
choose a starting and ending colour and the LEDs would only display that
range of colours in whatever transition they would have liked, just as I
have my own custom transitions of purples, since it is my favourite
colour. Another feature would be adding in a default startup. With this
users would be able to set up their favourite transitions along with the
colours that they like, without having to go through the hassle of
setting it up every single time they turn on the LEDs. The last feature
that I wanted to add would be an additional colour transition. It would
resemble a reloading symbol, starting off at max brightness while
leaving a fading trail following it.

Another limitation would be the resources department. When it came to
the time where I had to stick the ordinary mirror to the back panel, if
it had been left upside down for a prolonged period of time, it would
slowly come off. Fortunately, it did not break, but it takes quite a bit
of effort just trying to centre the mirror without opening it up again.
I used double sided tape, I would use a stronger adhesive next time,
such as gorilla glue.

## Investigation & Ideas

Front View: 

<img src=".\attachments\test1/media/image2.jpg" style="width:6.5in;height:7.77778in" />

Back View:

<img src=".\attachments\test1/media/image3.jpg" style="width:6.5in;height:6.18056in" />


Side View:

<img src=".\attachments\test1/media/image4.jpg" style="width:3.63883in;height:6.80564in" />


<u>IR Receiver:</u>
There is a pin for each VCC, which provides voltage to the component,
GND, which is an exit for the current to return back to VCC and get
power again, and then there is OUT. It is the data pin for the
component, it receives incoming data.

<img src=".\attachments\test1/media/image5.png" style="width:2.125in;height:1.66667in" />


<u>RGB LED:</u>
The pin for DIN (DATA IN) is responsible for all incoming data, while
DOUT (DATA OUT) is responsible for all outgoing data. Usually to provide
power there is VCC, which is for the entire circuit. But in this case
there is VDD, which is the voltage for the chip and VSS is is the
voltage drainage system, in other words, GND.

<img src=".\attachments\test1/media/image6.png" style="width:2.83333in;height:1.63542in" />


### Research Findings

Through my journey through the internet, I have learned various concepts
that are crucial for this project. The two main components work in ways
that I have never seen before. The RGB LED strip uses a byte each to
represent red, green, and blue. Since these are all the primary colours
of light, with just these three, you can make all the colours of light,
to be more specific 16’777’216 different colours. The website gave me an
insight on the basic commands and uses of the FastLED library by Daniel
Garcia. The second major component would be the IR receiver. It uses
incoming infrared light signals from the remote to take in decoded
information. The video I watched taught me about the basics of how to
use the IR remote library by Ken Shiriff and how to decode my remote
codes in order to customise it for my own use. Both of these tutorials
gave me a gist of how everything worked and provided me with enough
information that I code on my own from scratch.

### Appendix

IR Receiver Pinout Diagram:

Original Tinkercad Circuit:

<img src=".\attachments\test1/media/image7.png"
style="width:6.0397in;height:2.34675in" />

Schematic:

<img src=".\attachments\test1/media/image8.png"
style="width:4.46354in;height:4.9893in" />

RGB LED Pinout Diagram:

Original Tinkercad Circuit:

<img src=".\attachments\test1/media/image9.png"
style="width:6.86458in;height:3.46025in" />

Schematic:

<img src=".\attachments\test1/media/image10.png"
style="width:7.05208in;height:3.64215in" />

## Construction

### Parts List 

<table>
<colgroup>
<col style="width: 16%" />
<col style="width: 83%" />
</colgroup>
<tbody>
<tr>
<td>Quantity</td>
<td>Component Name</td>
</tr>
<tr>
<td>x 1</td>
<td>Arduino Nano</td>
</tr>
<tr>
<td>x 1</td>
<td>Male USB Type A to Male USB Micro</td>
</tr>
<tr>
<td>x 1</td>
<td>Breadboard 3 Inch</td>
</tr>
<tr>
<td>x 1</td>
<td>Individually Addressable RGB LED Strip 1m</td>
</tr>
<tr>
<td>x 1</td>
<td>Power Bank/Portable Charger "DC 5V 3A"</td>
</tr>
<tr>
<td>x 1</td>
<td>IR Remote Control with +8 buttons</td>
</tr>
<tr>
<td>x 1</td>
<td>IR Receiver Module</td>
</tr>
<tr>
<td>x 1</td>
<td>One Way Mirror Film</td>
</tr>
<tr>
<td>x 1</td>
<td>Clock Frame</td>
</tr>
<tr>
<td>x 1</td>
<td>Glass from Clock Frame</td>
</tr>
<tr>
<td>x 1</td>
<td>Circular Mirror (0.5 inches in diameter less than the clock
frame)</td>
</tr>
<tr>
<td>x 1</td>
<td>Window Film Application Kit</td>
</tr>
</tbody>
</table>

### Rough Sketches 

Front View:

<img src=".\attachments\test1/media/image11.jpg"
style="width:6.5in;height:7.86111in" />

Back View:

<img src=".\attachments\test1/media/image12.jpg"
style="width:6.5in;height:6.09722in" />

Side View:

<img src=".\attachments\test1/media/image13.jpg"
style="width:4.26764in;height:7.55044in" />

In the end, the only difference was that the IR Receiver is now at the
top front instead of being at the bottom back of the entire model in
order to increase the range of the IR receiver.

### Schematic View

*\*Note: I know it says to use fritzing, but every single site to
download it looked sketchy, so I just wanted to be safe rather than
sorry.*

<u>Original Tinkercad View:</u>

<img src=".\attachments\test1/media/image14.png"
style="width:6.95205in;height:3.2497in" />

<u>Schematic View:</u>

*\*Note: The wires in this view do not let me manually pickup and drag
them around.*

<img src=".\attachments\test1/media/image15.png"
style="width:6.94792in;height:3.63994in" />

### Construction Chart

*\*Note: For any doubts in wiring, refer to the wiring in the ‘Schematic
View’ or ‘Appendix’ section.*

<table style="width:100%;">
<colgroup>
<col style="width: 7%" />
<col style="width: 11%" />
<col style="width: 39%" />
<col style="width: 13%" />
<col style="width: 28%" />
</colgroup>
<tbody>
<tr>
<td>Step</td>
<td>Operation</td>
<td>Tips/Details</td>
<td>Equipment</td>
<td>Safety</td>
</tr>
<tr>
<td>1</td>
<td>Research</td>
<td>Used websites and videos to research how to code and wire both the
RGB LED strip and IR receiver and remote control using their respective
libraries and how to apply transparent mirror film.</td>
<td>-A device with an internet connection</td>
<td>N/A</td>
</tr>
<tr>
<td>2</td>
<td>Testing</td>
<td>Wired and tested the RGB LED strip ensuring that each of the colours
(red, green, blue, white) work at max brightness (255) by uploading the
code, <em>Sketch #3</em> in the <em>Arduino Program</em> section, into
the Arduino.</td>
<td>-A device capable of uploading code onto the Arduino</td>
<td>Ensure to wire correctly by referring to the wiring in the
<em>Schematic View</em> section, so no short circuits are caused, which
would ultimately lead to the circuit catching on fire from the excess
voltage overload.</td>
</tr>
<tr>
<td>3</td>
<td>Testing</td>
<td>Wired and tested out IR receiver and remote control and retrieved
the specific codes by uploading <em>Sketch #</em> 5 in the <em>Arduino
Program</em> section to the Arduino.</td>
<td>-A device capable of uploading code onto the Arduino</td>
<td><p>Ensure to wire correctly by referring to the wiring in the
<em>Schematic View</em> section, so no short circuits are caused, which
would ultimately lead to the circuit catching on fire from the excess
voltage overload.</p>
<p>Additionally be careful of the IR receiver component, since it is
spiky underneath as a result of the cut off parts.</p></td>
</tr>
<tr>
<td>4</td>
<td>Assembly</td>
<td>Measured, cut, and applied mirror film to glass by following the
exact steps of the video found on this site, <a
href="https://www.amazon.ca/Gila-Window-Films-RTK500-Application/dp/B002YXPITY/ref=sr_1_4?crid=1BJ7U1HFA2086&amp;keywords=mirror%2Bfilm%2Bapplication%2Bkit&amp;qid=1670131878&amp;refinements=p_72%3A11192170011&amp;rnid=11192166011&amp;sprefix=mirror%2Bfilm%2Bapplication%2Bkit%2Caps%2C138&amp;sr=8-4"><u>Window
Application Process</u></a></td>
<td><p>-An exacto knife</p>
<p>-A low lint cloth</p>
<p>-A solution (could be just water) in a spray bottle</p></td>
<td><p>Always handle glass gently in an area free of clutter and always
place it in an area where it is easily visible to avoid any possible
mishaps leading to broken sharp pieces of glass.</p>
<p>Take caution when also using anything that involves a blade. When not
in immediate use, put the cover on the blade to avoid any possible
cuts.</p></td>
</tr>
<tr>
<td>5</td>
<td>Assembly</td>
<td>Temporarily align the LED strip along the inner rim of the back
panel and measure how many LEDs can fit. Use tape to temporarily hold
the strip down along the rim if it keeps moving if necessary. Then cut
along the white thin line (there is one between each LED and there are
three gold ovals on them).</td>
<td>-wire cutters</td>
<td>Take caution while using wire cutters as they could cause possible
cuts. Ensure to enable the safety lock when not in immediate use.</td>
</tr>
<tr>
<td>6</td>
<td>Assembly</td>
<td>Use an exacto knife to make a hole right next to any spot along the
inner rim of the back panel. Note that the hole needs to be big enough
so that there is at least a bit of extra space for the widest part of
the wires to go through (might have to consider size of solderless
clip)</td>
<td>-Exacto knife</td>
<td>Take caution when also using anything that involves a blade. When
not in immediate use, put the cover on the blade to avoid any possible
cuts.</td>
</tr>
<tr>
<td>7</td>
<td>Assembly</td>
<td>Use a strong adhesive to stick the LED strip along the inner rim of
the back panel. Begin with the starting of the LED strip from where the
hole starts, since the wires have to go through it. Use tape if
necessary to hold it temporarily while the adhesive dries if it needs
to.</td>
<td>-A strong adhesive</td>
<td>Take caution when using a string adhesive. Especially gorilla glue.
Wear gloves if necessary. If any adhesive sticks onto yourself, read
safety steps on the product’s label.</td>
</tr>
<tr>
<td>8</td>
<td>Assembly</td>
<td><p>Used black tape to tightly wrap around the LED wires, enough so
that even if the wires rub against the edges of the hole, that they will
not be damaged. Then, poked the wires through the hole of the back
panel. Flipped the back panel over and firmly taped to seal the
hole.</p>
<p>Then stuck the normal mirror to the back panel with a strong
adhesive, while ensuring that it is centred.</p></td>
<td>-Black roll of tape</td>
<td><p>Take caution of frayed or damaged wires. Use electrical tape if
any problems arise.</p>
<p>Be careful with glass and mirrors as they can easily shatter. Always
place them in a clearly visible area.</p></td>
</tr>
<tr>
<td>9</td>
<td>Assembly</td>
<td>Cleaned off the smudges on both the normal mirror and one way mirror
with a glass cleaner. Placed the one way mirror on top of the front of
the back panel while holding it from the sides ensuring to not smudge
it.</td>
<td>-A low lint cloth</td>
<td>Take caution when handling mirrors as they can have sharp edges and
can shatter easily.</td>
</tr>
<tr>
<td>10</td>
<td>Assembly</td>
<td>Gently placed and fitted the front part / screen onto the front of
the back panel while ensuring the one way mirror is centred and remains
unsmudged. Then slowly picked up and flipped the entire model over to
firmly but gently press the front part / screen onto the back
panel.</td>
<td>N/A</td>
<td>Be careful with glass and mirrors as they can easily shatter. Always
place them in a clearly visible area.</td>
</tr>
<tr>
<td>11</td>
<td>Assembly</td>
<td>Temporarily placed all electrical components where they belong. Then
picked up each component one by one and stuck a piece of velcro to the
component and stuck the other piece directly onto the velcro piece, as
velcro should stick to each other, and then placed the component on the
exact spot that it was initially placed on.</td>
<td>N/A</td>
<td>Ensure to place all components in a clearly visible area neatly as
to avoid any possible damage and frayed wires.</td>
</tr>
<tr>
<td>12</td>
<td>Coding</td>
<td>Wired and uploaded the final version of the code onto the Arduino
using <em>Sketch #6</em> in the <em>Arduino Programs</em> section.</td>
<td>-A device capable of uploading code onto the Arduino</td>
<td>Ensure to place all components in a neat and clear area to avoid
damaging and fraying wires.</td>
</tr>
<tr>
<td>13</td>
<td>Assembly</td>
<td>Finally, tidied up wires on the back panel either using tape, zip
ties, or anything that can hold its shape.</td>
<td>-Tape / zip ties / etc…</td>
<td>N/A</td>
</tr>
</tbody>
</table>

### Arduino Programs

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


### Progress Pictures

Testing out red, green, and blue to see each LED is capable of
outputting each colour. Tested out white at max brightness, to test if
each LED is capable of outputting at max power. Tested out purple since
it is my favourite colour.

<img src=".\attachments\test1/media/image16.png"
style="width:2.10302in;height:2.81606in" /><img src=".\attachments\test1/media/image17.png"
style="width:2.10417in;height:2.81455in" />

<img src=".\attachments\test1/media/image18.png"
style="width:2.10417in;height:2.79656in" />

<img src=".\attachments\test1/media/image19.png"
style="width:2.10417in;height:2.80203in" /><img src=".\attachments\test1/media/image20.png"
style="width:2.10417in;height:2.80556in" /><img src=".\attachments\test1/media/image21.png"
style="width:2.10417in;height:2.80832in" />

Applying the transparent one way mirror film to glass, then cutting off
excess film, and finally cleaning the mirror.

<img src=".\attachments\test1/media/image22.png"
style="width:4.78412in;height:3.57795in" />

<img src=".\attachments\test1/media/image23.png"
style="width:4.77945in;height:4.23234in" />

<img src=".\attachments\test1/media/image24.png"
style="width:2.96944in;height:3.97708in" /><img src=".\attachments\test1/media/image25.png"
style="width:3.04514in;height:4in" />Temporarily placing the LED strip
along the inner rim of the back panel. In the amidst of doing so, I
snapped the extra GND wire. Tested the one-way mirror to check for its
reflectivity and clarity.

<img src=".\attachments\test1/media/image26.png"
style="width:3.25373in;height:3.27617in" /><img src=".\attachments\test1/media/image27.png"
style="width:3.05833in;height:3.29678in" />

Measuring how much of the LED strip to cut off, then cutting it, and
finally testing if it still works as it should be.

<img src=".\attachments\test1/media/image28.png"
style="width:2.83958in;height:4.29167in" /><img src=".\attachments\test1/media/image29.png"
style="width:3.45703in;height:4.60938in" /><img src=".\attachments\test1/media/image30.png"
style="width:2.79583in;height:3.82292in" />

Recutting, restriping, and resoldering the LED strip’s VCC, GND, and
DATA wires, since they were not done as well as I wanted them to be.
Also cutting off the extra VCC and GND wires since they were unnecessary
in this case. They are used when there are multiple strips to add in
additional power since they will not be as bright anymore.

<img src=".\attachments\test1/media/image31.png"
style="width:3.59766in;height:4.79688in" />

Sticking the LED strip along the inner rim of the back panel with
gorilla glue. Then, using double sided tape to stick the mirror.

<img src=".\attachments\test1/media/image32.png"
style="width:3.72396in;height:4.96828in" />

<img src=".\attachments\test1/media/image33.png"
style="width:3.77422in;height:5.03646in" />

Making a hole in the back panel for the LED strip wires to come through,
and then sealing the hole with tape. Finally, placing velcro for the IR
remote, power bank, and breadboard.

<img src=".\attachments\test1/media/image34.png"
style="width:5.09896in;height:3.82422in" />

<img src=".\attachments\test1/media/image35.png"
style="width:5.11979in;height:3.84997in" />

Final Results:

<img src=".\attachments\test1/media/image36.png"
style="width:3.63542in;height:3.89944in" />

<img src=".\attachments\test1/media/image37.png"
style="width:2.81641in;height:3.75521in" />

<img src=".\attachments\test1/media/image38.png"
style="width:3.63021in;height:3.41667in" />

## Evaluation

A **strength** about my infinity mirror would be the smooth transitions
between each colour. As each colour progresses, there is a very slight
change in colour through the use of loops with an increment of one.
These ever so small changes ensure that the transition does not look
choppy.

Another **strength** would be the user interface. Through the use of an
IR receiver and remote control, the user only has to press a designated
button in order to switch between the various options. All products are
heavily chosen and used for their convenience. If it is a hassle just to
switch between options, would it even be used in the first place?

The first **weakness** would be the IR remote control buttons. Without
looking at the operating instructions, it might be difficult to remember
which button is for what. What I would have liked to do was get a few
circular stickers and design a few icons for each button so each of
their functions could be identified at first glance.

The second **weakness** would be the inner mirror sometimes coming off.
However this was only an issue when it was placed the front facing the
ground. It almost always goes back in place when slowly flipped back to
the correct orientation. To resolve this, I would used a stronger form
of adhesive to stick the mirror to the back panel. This time I used
thick double sided tape with some type of squishy foam texture. Next
time, I would either find stronger double sided tape or gorilla glue.

A **problem** that I faced was that the wires for the LED strip
continuously frayed making it almost impossible to place into the
solderless breadboard. In order to fix this, I simply applied a thin
layer of solder to each of the frayed wires, ensuring they would
solidify as one whole wire instead of a bunch of miniscule frayed ones.

Another **problem** that I encountered would be the IR receiver looking
a bit out of place while it hung from the bottom of the frame. So I
instead placed it at the top. At first I thought this would have been a
problem with doing so, since it might have been hard for it to receive
signals from all the way up there with the limited range. However, after
receiving the component, I realised that the IR receiver itself can be
tilted, which can counteract the issue with the range limit of the IR
receiver.

In terms of any **changes**, if I were to make an infinity mirror again,
I would like to use a better one-way mirror, in terms of both its
clarity and reflectivity. This would allow for better practical use when
it is turned off to function as a normal mirror, since as of now, it is
just a tad bit blurry. Moreover, with a higher reflectiveness, there
would be more illusions of the “infinite” LEDs, allowing for a deeper
effect and appearance of the void of the abyss.


## Bibliography

Finio, Ben. “Arduino-Controlled RGB Led Infinity Mirror.”
*Instructables*, Autodesk, 17 Sept. 2013,
[<u>https://www.instructables.com/Arduino-controlled-RGB-LED-Infinity-Mirror/</u>](https://www.instructables.com/Arduino-controlled-RGB-LED-Infinity-Mirror/).

A self-directed project by BEn Finio that used an Arduino UNO to program
an RGB LED strip using a potentiometer to control each the red, green,
and blue values in order to creat an infinity mirror.

Pattabiraman, Krishna. “How to Set up an IR Remote and Receiver on an
Arduino.” *Circuit Basics*, 2 Nov. 2021,
[<u>https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/</u>](https://www.circuitbasics.com/arduino-ir-remote-receiver-tutorial/).

A tutorial by Kirshna Pattabiraman on how to wire and set an IR remote
and receiver for an Arduino and explaining the concepts behind them.

Window Films, Gila. “Gila RTK500 Complete Window Film Application Kit,
1-Pack.” *Gila RTK500 Complete Window Film Application Kit, 1-Pack*,
Amazon, 7 Apr. 2018,
[<u>https://www.amazon.ca/Gila-Window-Films-RTK500-Application/dp/B002YXPITY/ref=sr\_1\_4?crid=1BJ7U1HFA2086&keywords=mirror%2Bfilm%2Bapplication%2Bkit&qid=1670131878&refinements=p\_72%3A11192170011&rnid=11192166011&sprefix=mirror%2Bfilm%2Bapplication%2Bkit%2Caps%2C138&sr=8-4</u>](https://www.amazon.ca/Gila-Window-Films-RTK500-Application/dp/B002YXPITY/ref=sr_1_4?crid=1BJ7U1HFA2086&keywords=mirror%2Bfilm%2Bapplication%2Bkit&qid=1670131878&refinements=p_72%3A11192170011&rnid=11192166011&sprefix=mirror%2Bfilm%2Bapplication%2Bkit%2Caps%2C138&sr=8-4).

A tutorial that is included as a video and step-by-step instructions in
the description and pictures of the product’s site.

Workshop, DroneBot. “Using IR Remote Controls with the Arduino.” *Using
IR Remote Controls with the Arduino*, YouTube, 5 Jan. 2018,
[<u>https://www.youtube.com/watch?v=8E3ltjnbV0c</u>](https://www.youtube.com/watch?v=8E3ltjnbV0c).

A detailed runthrough of how to use IR remote controls with an Arduino
by the creator of DroneBot Workshop. He goes over the following topics;

- An introduction

- How IR remotes work

- How to “see” infrared light

- The IR sensor

- Decoding IR remote codes

- Getting manufacturers codes

- Repurposing an IR remote

- Building a custom IR control
