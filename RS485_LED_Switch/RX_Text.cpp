#include <SoftwareSerial.h>
#define ledPin 12
SoftwareSerial RS485(2, 3);

String message = "";
bool read = 1;

void setup() {

  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(ledPin, OUTPUT);

}

void loop() {

  read = 1;
  while (RS485.available() > 0 && read == 1) {

    char receivedVal = RS485.read();

    if (receivedVal == '<') {

      Serial.print(receivedVal);
      Serial.print("  :  ");
      if (receivedVal != '>') {
        message += receivedVal;
        Serial.println(message);
      } else {
        read = 0;
        Serial.println(message);
        message = "";
      }

    }

  }
