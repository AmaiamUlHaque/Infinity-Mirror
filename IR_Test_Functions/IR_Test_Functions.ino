#define DECODE_NEC
#include <Arduino.h>
#include <IRremote.hpp>        //includes the library needed for the IR remote
const int IR_RECEIVE_PIN = 2;  //declares the incoming DATA pin


void setup() {
  Serial.begin(9600);
  Serial.println("\nprogram start.");
  //begins the receiver to receive incoming signals
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  printActiveIRProtocols(&Serial);
}


void loop() {
  if (IrReceiver.decode()) {
    buttonPressed();
    Serial.println();
    IrReceiver.resume();
  }
}

void buttonPressed() {
  switch (IrReceiver.decodedIRData.command) {
    case 69:
      Serial.println("Button pressed: CH-\t= power");
      break;
    case 70:
      Serial.println("Button pressed: CH");
      break;
    case 71:
      Serial.println("Button pressed: CH+");
      break;
    case 68:
      Serial.println("Button pressed: PREV\t= decrease speed");
      break;
    case 64:
      Serial.println("Button pressed: NEXT\t= increase speed");
      break;
    case 67:
      Serial.println("Button pressed: PLAY/PAUSE\t= pause");
      break;
    case 7:
      Serial.println("Button pressed: VOL-\t= decrease brightness");
      break;
    case 21:
      Serial.println("Button pressed: VOL+\t= increase brightness");
      break;
    case 9:
      Serial.println("Button pressed: EQ\t= next transition");
      break;
    case 22:
      Serial.println("Button pressed: 0");
      break;
    case 25:
      Serial.println("Button pressed: 100+");
      break;
    case 13:
      Serial.println("Button pressed: 200+");
      break;
    case 12:
      Serial.println("Button pressed: 1");
      break;
    case 24:
      Serial.println("Button pressed: 2");
      break;
    case 94:
      Serial.println("Button pressed: 3");
      break;
    case 8:
      Serial.println("Button pressed: 4\t= icy purple");
      break;
    case 28:
      Serial.println("Button pressed: 5\t= purple");
      break;
    case 90:
      Serial.println("Button pressed: 6\t= lilac");
      break;
    case 66:
      Serial.println("Button pressed: 7\t= icy white");
      break;
    case 82:
      Serial.println("Button pressed: 8\t= white");
      break;
    case 74:
      Serial.println("Button pressed: 9\t= warm white");
      break;
    default:
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        Serial.println("Received noise or an unknown (or not yet enabled) protocol");
        IrReceiver.printIRResultShort(&Serial);
      }
      break;
  }
}