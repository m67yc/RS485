#include <SoftwareSerial.h>
#define ledPin 12
SoftwareSerial RS485(2, 3);

bool read = 0;
String message = "";

void setup() {
  
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  
  while (RS485.available() > 0) {
    char receivedVal = RS485.read();
    
    if (read == 1) {
      
      if (receivedVal == '>') {
        Serial.println(message);
        read = 0;
      }
      
      message += receivedVal;
    }
    if (receivedVal == '<') {
      message = "";
      read = 1;
    }
    
  }
  
}
