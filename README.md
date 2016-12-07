# CS207Project
Project repository for CS207

# Stock Price Display for Multiple Stocks Using Arduino

The purpose of this project is to build a display for stock prices.  Stock prices can change by the second.  For some people, this is very important in their jobs, and for others, monitoring the stock market can be a hobby or important for their personal finances.  My idea is to create a device that uses RSS feeds to obtain stock quotes from the interenet, and has buttons to cycle between different stocks. The device will in return display the real-time price as it changes.  Ideally, I wanted to be able to input any stock symbol, rather then “preloading” the machine with only a handful of stocks.  This would allow someone to look up any stock they’re interested in.

insert picture here...
IMG_4423.JPG

# Repository Contents

/src
/hardware
/build
/libraries
/examples
/img
/LICENSE
/README.md

# Requirements and Materials

Dependencies
Arduino
Python
PySerial
LiquidCrystal library
Ethernet Library

Bill of Materials
1 x Arduino LCD sheild (16 x 2 LCD, with 6 buttons)
1 x Arduino Ethernet Shield

# Build Instructions
This device is very simple to build. 
The first version using Python is assembled by attaching the LCD shield onto the Arduino
The second version uses an Ethernet shield instead of Python and is simply the Ethernet shield on the Arduino with the LCD shield on the Ethernet shield.
Here is the pin allocation:
Pin	Function
Analog 0	Button (select, up, right, down and left)
Digital 4	DB4
Digital 5	DB5
Digital 6	DB6
Digital 7	DB7
Digital 8	RS (Data or Signal Display Selection)
Digital 9	Enable
Digital 10	Backlit Control

# Usage
Upload the code to the device
Use the buttons to cycle between the displayed stocks.
Display the device to keep up to date on stock quotes.

# Team
The build team consists of:
Just me! Zac Reitmeier

# Credits
Fish, E. (2012, July 30). This Arduino Hack Makes Reading RSS Feeds More Fun. Retrieved December 01, 2016, from http://www.pcworld.com/article/260058/this_arduino_hack_makes_reading_rss_feeds_more_fun.html

Fritterdonut. (2012). An Arduino RSS Feed Display. Retrieved December 04, 2016, from http://www.instructables.com/id/Wiring-up-the-LCD-and-the-LED/

LCD KeyPad Shield For Arduino SKU: DFR0009. (n.d.). Retrieved November 16, 2016, from https://www.dfrobot.com/wiki/index.php/LCD_KeyPad_Shield_For_Arduino_SKU:_DFR0009

Randofo, (2012). Arduino Ethernet Shield Tutorial. Retrieved November 25, 2016, from http://www.instructables.com/id/Arduino-Ethernet-Shield-Tutorial/

