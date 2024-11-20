#include <SoftwareSerial.h>
#define ledPin 12
SoftwareSerial RS485(2, 3);
bool error;

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  while (RS485.available() > 0) {
    char receivedVal = RS485.read();
    long int counter = millis();
    RS485.write(receivedVal);
    Serial.println(receivedVal);
    if (receivedVal == 'L')
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
  }
}
