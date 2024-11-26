#include <SoftwareSerial.h>

#define buttonPin 13
SoftwareSerial RS485(2, 3);

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

long int success_count = 0;
long int error_count = 0;
int success_rate;
char returnVal;
char inputVal;

void loop() {


  if (digitalRead(buttonPin) == 0) {
    inputVal = 'L';
    RS485.write("<L>");
  } else {
    inputVal = 'D';
    RS485.write("<D>");
  }

  while (!RS485.available()) {
    Serial.println("no");
    if (inputVal == 'L') {
      RS485.write("<L>");
    } else {
      RS485.write("<D>");
    }
    delay(10);
  }
  returnVal = RS485.read();
  Serial.print("    ");

  if (returnVal != inputVal)
    error_count++;
  else
    success_count++;
  success_rate = success_count / (success_count + error_count) * 100;

  Serial.print(returnVal);
  Serial.print(" : ");
  Serial.print(inputVal);
  Serial.print("   ;   ");
  Serial.print(error_count);
  Serial.print("-");
  Serial.print(success_count);
  Serial.print(":  ");
  Serial.print(success_rate);
  Serial.println("%");
}
