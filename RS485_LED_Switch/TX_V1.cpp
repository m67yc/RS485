#include <SoftwareSerial.h>

#define buttonPin 13
SoftwareSerial RS485(2, 3);

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  char returnVal;
  char inputVal;
  
  if (digitalRead(buttonPin) == 0) {
    inputVal = 'L';
    RS485.write(inputVal);
  } else {
    inputVal = 'D';
    RS485.write(inputVal);
  }
  returnVal = RS485.read();
  Serial.print(returnVal);
  Serial.print(" : ");
  Serial.println(inputVal);
}
