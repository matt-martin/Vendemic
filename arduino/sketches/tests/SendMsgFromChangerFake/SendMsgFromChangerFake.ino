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

int numReads = 0;
void loop() // run over and over
{
  if (mySerial.available()) {
   int c = mySerial.read();
   Serial.print(c);
   Serial.print(", binary: ");
   Serial.println(c, BIN); 
   if (numReads == 1) {
     mySerial.write_nine_bits(0x1ff);
   }
  }
  numReads++;
}
