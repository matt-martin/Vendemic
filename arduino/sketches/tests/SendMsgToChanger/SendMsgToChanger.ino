#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3

SoftwareSerial mySerial = SoftwareSerial(rxPin, txPin);

void setup()  
{
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  
}

int numWrites = 0;
uint16_t i = 0x21;
void loop() // run over and over
{
  if (numWrites == 0) {
    mySerial.write_nine_bits(i);
    mySerial.write_nine_bits(i); // This should be the checksum, but we're sending random stuff for now.
  } else {
    if (mySerial.available()) {
     int c = mySerial.read();
     Serial.print(c);
     Serial.print(", binary: ");
     Serial.println(c, BIN); 
    }
  }
  
  
  //mySerial.write(i);
  delay(100);
  numWrites++;
}
