#define buttonPin 13

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  delay(500);
}

long int success_count = 0, error_count = 0;
int success_rate, count = 0, RX = 0;
char returnVal[100], inputVal[100];
unsigned long time, time2;

void loop() {

  if (count == 26)
    count = 0;
  if (RX == 26)
    RX = 0;

  inputVal[count] = 'A' + count;
  Serial.print(count);
  Serial.print(" : ");
  Serial.print(inputVal[count]);

  time = micros();
  Serial3.write('<');
  Serial3.write(inputVal[count]);
  Serial3.write('>');
  count++;

  if (Serial3.available()) {
    returnVal[27]= Serial3.read();
    RX = int(returnVal[27] - 'A');
    returnVal[RX] = returnVal[27];
    time2 = micros();
    Serial.print("   ;   ");
    Serial.print(RX);
    Serial.print(" : ");
    Serial.print(returnVal[RX]);
    // Serial.print("    ");

    if (returnVal[RX] != inputVal[RX])
      error_count++;
    else
      success_count++;
    success_rate = (success_count * 100) / (success_count + error_count);
    unsigned long time_long = time2 - time;

    Serial.print("   ;   ");
    Serial.print(returnVal[RX]);
    Serial.print(" : ");
    Serial.print(inputVal[RX]);
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
}
