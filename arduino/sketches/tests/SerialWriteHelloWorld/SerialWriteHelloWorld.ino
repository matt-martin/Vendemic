void setup()  
{
  Serial.begin(4800);
}

int i = 0;
void loop() // run over and over
{
  if (i > 0) {
    return;  
  }
  
  Serial.write("Hello from the Arduino UNO!");
  
  i++;
}
