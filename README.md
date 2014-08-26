# Teensy 3.1

Notes Related to Teensy 3.1 ARM MCU Board

* [The Teensy 3.1 web page](https://www.pjrc.com/teensy/teensy31.html)

The Teensy 3.1 board can be used for projects written in C, Arduino and/or MicroPython. I'm intrigued by the 
possibilities in an educational setting. With that in mind I will acquire one of these boards and explore the possibilities.

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

Followed the instructions on the PJRC Teensy website. I tried one of the simple Arduino examples that blinks a LED. I then made a change to the blink rate and duty cycle. All worked as expected.

A number of lines of comments were pulled out.

```arduino
/*
  Blink --   This example code is in the public domain.
*/

int led = 13;

// the setup routine runs once:
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

### added C library

* [c library](libraries)

## Using Teensy 3.1 Without the Arduino IDE
 
### This was run under Windows.

See 
* <http://forum.pjrc.com/threads/24861-Teensy-3-1-without-arduino-IDE>
* <https://www.pjrc.com/teensy/gcc.html>

Followed the essential instructions on the teensy web pages by changing references in the makefile to refer to the 3.1 and not the 3.0. For this 
(all references to 128 were changed to 256).

One section seemed to indicate I should change the line commented out for windows but it turned out the comment was wrong and 
I left it like it is to work on windows computer.

```
# path location for Teensy Loader, teensy_post_compile and teensy_reboot
TOOLSPATH = $(ARDUINOPATH)/hardware/tools   # on Linux
#TOOLSPATH = $(ARDUINOPATH)/hardware/tools/tools/avr/bin   # on Mac or Windows
```

I simplified the example program and saved it as main.c 

```c 
#include "WProgram.h"

int main(void)
{

	pinMode(13, OUTPUT);
	while (1) {
		digitalWriteFast(13, HIGH);
		delay(101);
		digitalWriteFast(13, LOW);
		delay(900);
	}

}

```

### Under Linux

The alterations to the Makefile were exactly the same as under windows.

* [Makefile](linux/Makefile)

In the case of main.cpp I tested it essentially as extracted from the downloaded Teensyduino archive.

* [main.cpp](linux/main.cpp)

#### Item I lost track of

* <http://forum.pjrc.com/threads/24527-Teensy-3-0-Project-Template>

I should have a closser look at this template (setup for Linux)
Also see
* <https://github.com/apmorton/teensy-template>

## MicroPython
 
### Building Micro Python for Teensy 3.1.

Currently the Teensy 3.1 port of Micro Python builds under Linux and not under Windows.

The tool chain required for the build can be found at <https://launchpad.net/gcc-arm-embedded>.

Downlaod the current Linux *.tar.bz2 file. Instructions regarding unpacking the file and moving it to the correct location 
as well as adding the extracted folders to the enviroment variable can be found at 
<http://eliaselectronics.com/stm32f4-tutorials/setting-up-the-stm32f4-arm-development-toolchain/>

* [MicroPython interactive session](linux/micropython_help.txt)

An interactive session with Micro Python looked like this (many features listed are not yet implemented in Teensy 3.1)

```
Executing main.py
Micro Python v1.2-59-gecb5792 on 2014-08-11; Teensy-3.1 with MK20DX256
Type "help()" for more information.
>>> 
>>> help()
Welcome to Micro Python!

For online help please visit http://micropython.org/help/.

Quick overview of commands for the board:
  pyb.info()    -- print some general information
  pyb.gc()      -- run the garbage collector
  pyb.delay(n)  -- wait for n milliseconds
  pyb.Switch()  -- create a switch object
                   Switch methods: (), callback(f)
  pyb.LED(n)    -- create an LED object for LED n (n=1,2,3,4)
                   LED methods: on(), off(), toggle(), intensity(<n>)
  pyb.Pin(pin)  -- get a pin, eg pyb.Pin('X1')
  pyb.Pin(pin, m, [p]) -- get a pin and configure it for IO mode m, pull mode p
                   Pin methods: init(..), value([v]), high(), low()
  pyb.ExtInt(pin, m, p, callback) -- create an external interrupt object
  pyb.ADC(pin)  -- make an analog object from a pin
                   ADC methods: read(), read_timed(buf, freq)
  pyb.DAC(port) -- make a DAC object
                   DAC methods: triangle(freq), write(n), write_timed(buf, freq)
  pyb.RTC()     -- make an RTC object; methods: datetime([val])
  pyb.rng()     -- get a 30-bit hardware random number
  pyb.Servo(n)  -- create Servo object for servo n (n=1,2,3,4)
                   Servo methods: calibration(..), angle([x, [t]]), speed([x, [t]])
  pyb.Accel()   -- create an Accelerometer object
                   Accelerometer methods: x(), y(), z(), tilt(), filtered_xyz()

Pins are numbered X1-X12, X17-X22, Y1-Y12, or by their MCU name
Pin IO modes are: pyb.Pin.IN, pyb.Pin.OUT_PP, pyb.Pin.OUT_OD
Pin pull modes are: pyb.Pin.PULL_NONE, pyb.Pin.PULL_UP, pyb.Pin.PULL_DOWN
Additional serial bus objects: pyb.I2C(n), pyb.SPI(n), pyb.UART(n)

Control commands:
  CTRL-A        -- on a blank line, enter raw REPL mode
  CTRL-B        -- on a blank line, enter normal REPL mode
  CTRL-C        -- interrupt a running program
  CTRL-D        -- on a blank line, do a soft reset of the board

For further help on a specific object, type help(obj)
>>> 
 CTRL-A Z for help |115200 8N1 | NOR | Minicom 2.6.1  | VT102 |      Offline                                                

```

### Early Setup to Build Micro Python for Teensy 3.1.

MicroPython was compiled following the instructions at (links to Teensy forum)

* <http://forum.pjrc.com/threads/24794-MicroPython-for-Teensy-3-1?p=39515&viewfull=1#post39515>

and

* <http://forum.pjrc.com/threads/24794-MicroPython-for-Teensy-3-1?p=41582&viewfull=1#post41582>

MicroPython was cross compiled on a Linux computer. Once the hex file is created it can be loaded onto the Teensy3.1. 
I accessed Micropython via Minicom on Linux. I also accessed it using PuTTY on a Windows computer. A short interactive session with MicroPython can be seen here:

* [MicroPython interactive session](linux/micropython.txt)
