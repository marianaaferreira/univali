/*
  Serial example
  https://youtu.be/a6LGLwfO154
  https://akuzechie.blogspot.com/2021/10/assembly-via-arduino-programming-serial.html
*/

//------------------------------------------------
// Programming Serial Port - Printing Text Message
//------------------------------------------------
extern "C"
{
  void init_serial();
  void print_msg();
}
//----------------------------------------------------
void setup()
{
  init_serial();
}
//----------------------------------------------------
void loop()
{
  print_msg();
  delay(1000);  // delay in between reads for stability
}
