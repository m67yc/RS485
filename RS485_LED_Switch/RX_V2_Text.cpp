#include <SoftwareSerial.h>
#define ledPin 12
SoftwareSerial RS485(2, 3);

bool read = 0;
String message = "";
char m[100];

void setup() {

  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int time = 0;

  while (RS485.available() > 0) {
    char receivedVal = RS485.read();

    if (read == 1) {

      if (receivedVal == '>') {
        Serial.print(message);
        Serial.print("    ");

        for(int i = 0;i <= time;i++){
          RS485.write(m[i]);
          Serial.print(m[i]);
        }

        Serial.println();
        
        message = "";
        read = 0;
        break;
      }

      message += receivedVal;
      m[time] = receivedVal;
      time++;
    }

    if (receivedVal == '<') {
      read = 1;
    }
  }
}
