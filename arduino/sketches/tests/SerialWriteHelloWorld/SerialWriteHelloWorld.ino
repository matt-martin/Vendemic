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

uint16_t i = 254;
void loop() // run over and over
{
  if (i > 512) {
    return;  
  }
  
  //Serial.write("Hello from the Arduino UNO!");
  mySerial.write_nine_bits(i);
  //mySerial.write(i);
  
  i++;
}
