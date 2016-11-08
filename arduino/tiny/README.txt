
Arduino-Tiny is an open source set of ATtiny "cores" for the Arduino platform.

The Arduino platform currently supports Atmel ATmega processors. There is a need
for the Arduino platform to work with physically smaller DIP package processors.
The intent of this project is fulfill that need. Specifically, our goal is to
provide a core that enables Arduino users to work with the ATtiny84 (84/44/24),
ATtiny85 (85/45/25), and ATtiny2313 processors.

For more information about Arduino, see the website at: http://www.arduino.cc/


INSTALLATION

First ensure the Arduino software is correctly installed.

Next...

* Ensure the Arduino IDE is NOT running.

* Download the Arduino-Tiny archive (ZIP-file).

* Locate the Arduino Sketchbook folder.  This is the folder where the Arduino 
  IDE stores Sketches.

* Ensure the "hardware" folder exists under the Arduino Sketchbook folder.  For
  example, if the Arduino Sketchbook folder is...

      C:\Projects\Arduino\

  Ensure this folder exists...

      C:\Projects\Arduino\hardware\

* Extract the contents of the archive into the "hardware" folder.  For example,
  if the Arduino Sketchbook folder is...

      C:\Projects\Arduino

  After extracting, the following files / folders should exist...

      C:\Projects\Arduino\hardware\tiny\avr\license.txt
      C:\Projects\Arduino\hardware\tiny\avr\platform.txt
      C:\Projects\Arduino\hardware\tiny\avr\Prospective Boards.txt
      C:\Projects\Arduino\hardware\tiny\avr\README
      C:\Projects\Arduino\hardware\tiny\avr\bootloaders\
      C:\Projects\Arduino\hardware\tiny\avr\cores\

  The following folder should contain the source files for the Arduino-Tiny
  core...

      C:\Projects\Arduino\hardware\tiny\avr\cores\tiny\

* Create a new file named "boards.txt" in the tiny\avr directory.  Following 
  from the examples above, the file would be here...

      C:\Projects\Arduino\hardware\tiny\avr\boards.txt

* Open the "boards.txt" file and the "Prospective Boards.txt" file using your
  favourite text editor.

* Copy board entries of interest from "Prospective Boards.txt" to "boards.txt"
  (or copy the entire contents of "Prospective Boards.txt" to "boards.txt").
  Board entries are delineated by a long line of pound-signs.

* In the "boards.txt" file, change the "upload.tool" entries to the
  appropriate value for your setup.

* Save and close "boards.txt".  Close "Prospective Boards.txt".

* Start the Arduino IDE and ensure the new boards of interest are listed under
  the [Tools] [Board] menu...

      "ATtiny84 @ 16 MHz  (external crystal; 4.3 V BOD)"
      "ATtiny85 @ 8 MHz  (internal oscillator; BOD disabled)"
      etcetera

You are now ready to use Arduino-Tiny!


CREDITS

Arduino is an open source project, supported by many.

The Arduino team is composed of Massimo Banzi, David Cuartielles, Tom Igoe,
Gianluca Martino, and David A. Mellis.

Arduino uses the GNU avr-gcc toolchain, avrdude, avr-libc, and code from
Processing and Wiring.

Arduino-Tiny is based on work by David A. Mellis, René Bohne, R. Wiersma,
Alessandro Saporetti, and Brian Cook.
