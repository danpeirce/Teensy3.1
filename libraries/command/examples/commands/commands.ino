extern "C"{
#include <command.h>
};

enum commands_type the_command=startc;
const int ledPin = 13;

void setup()
{
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  static char rx_char=0;
  
  if (Serial.available()) 
  {
    rx_char = Serial.read();
    Serial.write(rx_char);
  }
  else rx_char =0;
  
  the_command = command(rx_char);
  if (the_command == startc) Serial.print("\nstart\r\n>");
  else if (the_command == resetc) Serial.print("\nreset\r\n>");
  else if (the_command == on13c)
  {
    Serial.print("\nLED on\r\n>");
    digitalWrite(ledPin, HIGH);
  }
  else if (the_command == off13c)
  {
    Serial.print("\nLED off\r\n>");
    digitalWrite(ledPin, LOW);
  }
}


