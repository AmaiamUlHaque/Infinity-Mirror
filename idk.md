# Arduino-Powered RGB Infinity Mirror

A self-built, interactive infinity mirror featuring an individually addressable RGB LED strip controlled by an Arduino Nano and an IR remote. This project serves as both a functional mirror and a dynamic decorative piece with smooth color transitions and customizable settings.

![Infinity Mirror](https://github.com/user/attachments/if-you-have-a-picture-put-link-here)

## Table of Contents

1.  [Features](#features)
2.  [Operating Instructions](#operating-instructions)
3.  [Core Components](#core-components)
4.  [Installation & Setup](#installation--setup)
5.  [Wiring Schematic](#wiring-schematic)
6.  [Construction](#construction)
7.  [Arduino Code](#arduino-code)
8.  [Troubleshooting](#troubleshooting)
9.  [Future Improvements](#future-improvements)
10. [License](#license)
11. [Acknowledgements](#acknowledgements)

## Features

*   **Multiple Color Transitions:** Cycle through various pre-programmed light shows including a full color spectrum fade, a spiral effect, a "reload" trail, random colors, and a dedicated purple-themed sequence.
*   **IR Remote Control:** Full control over the mirror's functions without any physical buttons on the device itself.
*   **Adjustable Settings:**
    *   **Brightness Control:** Increase or decrease the LED intensity.
    *   **Speed Control:** Adjust the transition speed of the animations.
    *   **Pause/Play:** Freeze on any current color.
*   **Static Color Selection:** Directly select specific colors: Purple, White, Warm White, and Icy White.
*   **Power On/Off:** Remote-controlled power switching.

## Operating Instructions

1.  Ensure the 5V power bank is charged.
2.  Point the IR remote at the receiver (located at the top of the frame) and press the **POWER** button to turn on the mirror.
3.  Use the **TRANSITION (EQ)** button to cycle through the different light animations.
4.  Use **VOL+** and **VOL-** to adjust brightness.
5.  Use **NEXT** and **PREV** to adjust the animation speed.
6.  Press **PAUSE/PLAY** to freeze or resume the current animation.
7.  Use buttons **5 (Purple)**, **8 (White)**, **9 (Warm White)**, and **7 (Icy White)** to switch to those specific static colors.
8.  Press the **POWER** button again to turn the lights off (the mirror remains functional).


## Core Components

*   **Microcontroller:** Arduino Nano
*   **LEDs:** 1m Individually Addressable RGB LED Strip (WS2812B, 54 LEDs)
*   **Power:** 5V 3A Portable Power Bank
*   **Control:** IR Receiver Module & IR Remote Control
*   **Optics:** One-Way Mirror Film, Circular Glass, Standard Mirror
*   **Enclosure:** Repurposed Clock Frame
*   **Other:** Breadboard, Wires, Adhesives, Application Kit for film


## Installation & Setup

### 1. Software (Arduino IDE)

1.  Install the [Arduino IDE](https://www.arduino.cc/en/software).
2.  Install the required libraries:
    *   **FastLED** by Daniel Garcia (for LED control)
    *   **IRremote** by Ken Shirriff (for IR control)
3.  You can install these via the Arduino Library Manager (Sketch > Include Library > Manage Libraries...).

### 2. Hardware Assembly

*   **Wiring:** Connect the components as shown in the [Wiring Schematic](#wiring-schematic) below.
*   **Upload Code:** Connect the Arduino Nano to your computer via USB, select the correct board and port in the Arduino IDE, and upload the `Infinity_Mirror_Final.ino` sketch.

## Wiring Schematic

| Component | Arduino Pin | Connection |
| :--- | :--- | :--- |
| IR Receiver | `VCC` | `5V` |
| | `GND` | `GND` |
| | `OUT` | `D2` |
| LED Strip | `VDD` (5V) | `5V` (from Power Source) |
| | `VSS` (GND) | `GND` (from Power Source & Arduino) |
| | `DIN` (Data) | `D5` |

**Note:** The LED strip must be powered directly by the 5V power bank to provide sufficient current. The Arduino and IR receiver are also powered from this source.

## Construction

The mirror was built into a circular clock frame. The process involved:

1.  **Applying Film:** Carefully applying one-way mirror film to the glass.
2.  **Preparing LEDs:** Measuring, cutting, and soldering the LED strip to fit the circular frame.
3.  **Assembly:** Gluing the LED strip to the inner rim of the back panel, creating a hole for wires, and mounting the standard mirror.
4.  **Mounting Electronics:** Securing the Arduino, breadboard, and power bank with velcro inside the frame for easy access and maintenance.

Refer to the detailed **Construction Chart** (Pages 17-19 of the report) for a full step-by-step guide with safety tips.

## Arduino Code

The main sketch (`Infinity_Mirror_Final.ino`) uses a state-machine structure controlled by IR input. Key features of the code:

*   **Interrupts:** The IR receiver uses an interrupt for responsive, non-blocking remote control.
*   **Modular Functions:** Each light animation is its own function (e.g., `Default()`, `Spiral()`, `Purples()`).
*   **Efficient LED Control:** Uses the FastLED library for high-performance, easy-to-manage LED operations.
*   **Commented:** The code is thoroughly commented for clarity and understanding.

The code includes functions for:
*   `IRTranslate()`: Handles all remote control inputs.
*   `SetAllLEDs()`: Sets the entire strip to a solid color.
*   `Default()`, `Fade()`, `Spiral()`, `Reload()`, `Random()`, `Purples()`: The various animation sequences.

## Troubleshooting

*   **Mirror won't turn on:** Check the power bank charge level. Ensure all connections are secure, especially the 5V and GND lines to the LED strip.
*   **IR Remote not working:** Ensure the IR receiver is correctly wired (VCC, GND, OUT). Check for obstructions between the remote and the receiver.
*   **LEDs are flickering or wrong colors:** This is often a power issue. Ensure you are using a capable 5V 3A power source and that all ground connections are shared. Double-check the data wire connection.
*   **Inner mirror becomes loose:** The adhesive may need to be stronger. Consider using a high-strength epoxy or gorilla glue for a permanent bond.

## Future Improvements

*   **Custom Color Palette:** Allow users to define and save their own start/end colors for transitions.
*   **Saved Settings:** Implement EEPROM storage to remember the last used transition, brightness, and speed after power-off.
*   **Wireless Charging:** Integrate a Qi wireless charging receiver to charge the internal power bank without opening the frame.
*   **Sound Reactivity:** Add a microphone module to make the lights react to music or ambient sound.

## License

This project is offered as-is for educational and personal use.

## Acknowledgements

*   **FastLED Library:** [http://fastled.io/](http://fastled.io/)
*   **IRremote Library:** [https://github.com/Arduino-IRremote/Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)
