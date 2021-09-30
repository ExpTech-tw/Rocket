#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 1);

int ledPin = 2;
unsigned long last = millis();

void setup() {
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {

  boolean ledState = digitalRead(ledPin);

  if (mySerial.available() > 1) {
    int input = mySerial.parseInt();

    if (millis() - last > 250) {
      if (ledState == 0 && input == 1234) { 
        digitalWrite(ledPin, HIGH);
      } else if (ledState == 1 && input == 1234) {
        digitalWrite(ledPin, LOW);
      }

    }

    mySerial.flush();
    last = millis();
  }
  delay(20);

}
