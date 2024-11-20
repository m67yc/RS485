#include <SoftwareSerial.h>
// #define DE 3
// #define RE 2

SoftwareSerial mySerial(2, 3);
int buttonPin = 13;
// int buttonPin1 = 4;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  // pinMode(buttonPin1, INPUT_PULLUP);
  // pinMode(DE, OUTPUT);
  // pinMode(RE, OUTPUT);
  // digitalWrite(DE, HIGH);
  // digitalWrite(RE, HIGH);
}

void loop() {

  char a;
  int error = 0;

  if (digitalRead(buttonPin) == LOW) {
    mySerial.write('A');
    a = 'A';

  } else {
    mySerial.write('B');
    a = 'B';
  }

  // if (digitalRead(buttonPin1) == LOW) {
  //   mySerial.write('C');
  // } else {
  //   mySerial.write('D');
  // }
  while(mySerial.available() > 0){
    char c = mySerial.read();
    if(c != a){
      Serial.print("error!");
      Serial.print("  ;  ");
    }
    Serial.println(c);
  }
  delay(100);
}
