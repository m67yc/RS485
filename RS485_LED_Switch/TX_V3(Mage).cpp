#define buttonPin 13

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

long int success_count = 0, error_count = 0;
int success_rate, count;
char returnVal, inputVal;
unsigned long time, time2;

void loop() {

  if(count == 26)
    count = 0;
  inputVal = 'A' + count;
  count++;
  time = micros();
  Serial3.write('<');
  Serial3.write(inputVal);
  Serial3.write('>');

  // while (!Serial3.available()) {
  //   Serial.println("no");
  //   if (inputVal == 'L') {
  //     Serial3.write("<L>");
  //   } else {
  //     Serial3.write("<D>");
  //   }
  //   delay(10);
  // }
  delay(5);
  returnVal = Serial3.read();
  time2 = micros();
  Serial.print("    ");

  if (returnVal != inputVal)
    error_count++;
  else
    success_count++;
  success_rate = (success_count * 100) / (success_count + error_count);

  unsigned long time_long = time2 - time;

  Serial.print(returnVal);
  Serial.print(" : ");
  Serial.print(inputVal);
  Serial.print("   ;   ");
  Serial.print(error_count);
  Serial.print("-");
  Serial.print(success_count);
  Serial.print(":  ");
  Serial.print(success_rate);
  Serial.print("%");
  Serial.print("   ;   ");
  Serial.print(time_long);
  Serial.println("micros");
}
