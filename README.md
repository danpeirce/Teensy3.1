# Teensy 3.1

Notes Related to Teensy 3.1 ARM MCU Board

* [The Teensy 3.1 web page](https://www.pjrc.com/teensy/teensy31.html)

The Teensy 3.1 board can be used for projects written in C, Arduino and/or MicroPython. I'm intrigued by the 
possibilities in an educational set ting. With that in mind I will acquire one of these boards and explore the possibilities.

## Installation

The pjrc Teensy web page gives a good set of instructions on the installation for the Teensy 3.1. 
The steps include downloading software for Arduino and then downloading and installing Teensyduino. 
Even the Micro Python project assumes this will be done.

* [PJRC - Download Teensyduino, Version 1.19](https://www.pjrc.com/teensy/td_download.html)

I'll need to get a board to try this.

## Links to Schematic and Datasheet

* [Teensy 3.0 & 3.1 Schematic](https://www.pjrc.com/teensy/schematic.html)
* [Teensy 3.1 MK20DX256 Manual from Freescale](https://www.pjrc.com/teensy/K20P64M72SF1RM.pdf)

## Using Teensy 3.1 With the Arduino IDE

Followed the instrucions on the PJRC Teensy website. I tried one of the simple Arduino examples that blinks a LED. I then made a change to the blink rate and duty cycle. All worked as expected.

```arduino
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
*/
 
// Pin 13 has an LED connected on most Arduino boards.
// Pin 11 has the LED on Teensy 2.0
// Pin 6  has the LED on Teensy++ 2.0
// Pin 13 has the LED on Teensy 3.0
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a 0.1 second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(900);               // wait for a 0.9 second
}
```

## Using Teensy 3.1 Without the Arduino IDE

See 
* <http://forum.pjrc.com/threads/24861-Teensy-3-1-without-arduino-IDE>
* <https://www.pjrc.com/teensy/gcc.html>
