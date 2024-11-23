#include <SoftwareSerial.h>
#define ledPin 12
SoftwareSerial RS485(2, 3);

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  while (RS485.available() > 0) {

    char receivedVal = RS485.read();
    RS485.write(receivedVal);
    Serial.println(receivedVal);

    if (receivedVal == 'L')
      digitalWrite(ledPin, HIGH);
    else if (receivedVal == 'D')
      digitalWrite(ledPin, LOW);
    
  }
  
}
