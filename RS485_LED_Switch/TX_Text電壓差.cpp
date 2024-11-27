#include <SoftwareSerial.h>
SoftwareSerial RS485(2, 3);

#define LED_pin 13

void setup() {

  Serial.begin(9600);
  RS485.begin(9600);

  pinMode(LED_pin, OUTPUT);
  
}

void loop() {

  RS485.write("K");
  while(RS485.available()){
    if(RS485.read() == 'K')
      digitalWrite(LED_pin, HIGH);
  }
}
