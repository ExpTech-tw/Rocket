#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

int buttonPin = 8;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  mySerial.begin(9600);
}

void loop() {

  int buttonState = digitalRead(buttonPin);

  if (buttonState == 0) { 
    mySerial.println(1234);
  }
  delay(20);
}
