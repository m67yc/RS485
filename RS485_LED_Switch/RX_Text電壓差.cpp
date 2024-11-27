#include <SoftwareSerial.h>
SoftwareSerial RS485(2, 3);

void setup() {

  Serial.begin(9600);
  RS485.begin(9600);

}

void loop() {

  while (RS485.available()) {

    char receivedVal = RS485.read();
    RS485.write(receivedVal);
    Serial.print(receivedVal);
    Serial.println("    k");
    
  }

  
}
