#include "IRLibAll.h"

//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(2);

//Create a decoder object
IRdecode myDecoder;

int stopPin = 12;
int upPin = 11;
int downPin = 10;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
  pinMode(stopPin, OUTPUT);
  pinMode(upPin, OUTPUT);
  pinMode(downPin, OUTPUT);
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    // myDecoder.dumpResults(true); //Uncomment this to find your IR codes
    if (myDecoder.protocolNum == NEC) {
      switch (myDecoder.value) {
        case 0x40bf807f:
          Serial.println("Projector Screen Down");
          digitalWrite(downPin, HIGH);
          delay(400);
          digitalWrite(downPin, LOW);
          break;
        case 0x40bfd02f:
          Serial.println("Projector Screen Stop");
          digitalWrite(stopPin, HIGH);
          delay(400);
          digitalWrite(stopPin, LOW);
          break;
        case 0x40bf906f:
          Serial.println("Projector Screen Up");
          digitalWrite(upPin, HIGH);
          delay(400);
          digitalWrite(upPin, LOW);
          break;
      }
    }
  }
  myReceiver.enableIRIn();      //Restart receiver
}

