#include <SoftwareSerial.h>

SoftwareSerial GPS(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  GPS.begin(38400);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  Serial.print(millis());
  Serial.print(",");
  while (GPS.available() > 0) {
    char inByte = GPS.read();
    Serial.write(inByte);
  }
  Serial.print(",");
  Serial.println(analogRead(A0));
  digitalWrite(13, LOW);
  delay(1000);
}
