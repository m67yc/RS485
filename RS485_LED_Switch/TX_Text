#include <SoftwareSerial.h>
#define buttonPin 13
SoftwareSerial RS485(2, 3);

String message = "";

void setup(){

  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {

  while (Serial.available()) {

    char received = Serial.read();
    RS485.write(received);

  }

}
