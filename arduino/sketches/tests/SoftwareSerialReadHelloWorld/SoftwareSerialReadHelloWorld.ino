#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);

void setup()  
{
  Serial.begin(4800);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(4800);
}

void loop() // run over and over
{
  if (mySerial.available()) {
   int c = mySerial.read();
   Serial.println(c, BIN); 
  }
}
