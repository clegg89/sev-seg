# Arduino Stop-Watch Application

This project implements a timer using an Arduino, a 4-digit 7-segment display, 2 momentary push buttons, and resistors.

## Hardware

There is a Fritzing project under the Hardware directory which has a schematic and breadboard layout for the hardware.

## Software

All the software is in [src/main.cpp](https://github.com/clegg89/sev-seg/blob/master/src/main.cpp). It uses the [SevSeg](https://github.com/DeanIsMe/SevSeg) library, which can be installed for PlatformIO or the Arduino IDE.

Some small tweaks may need to be made for different board types, and if different pins are used.
