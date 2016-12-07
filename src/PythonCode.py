Python 3.5.2 (v3.5.2:4def2a2901a5, Jun 26 2016, 10:47:25) 
[GCC 4.2.1 (Apple Inc. build 5666) (dot 3)] on darwin
Type "copyright", "credits" or "license()" for more information.
>>> WARNING: The version of Tcl/Tk (8.5.9) in use may be unstable.
Visit http://www.python.org/download/mac/tcltk/ for current information.
#import library to do http requests:
import urllib2
#import pyserial Library
import serial
#import time library for delays
import time

#import xml parser called minidom:
from xml.dom.minidom import parseString

#Initialize the Serial connection in COM3 or whatever port your arduino uses at 9600 baud rate
ser = serial.Serial("\\.\COM3", 9600)
i = 1
#delay for stability while connection is achieved
time.sleep(5)
while i == 1:
     #download the rss file feel free to put your own rss url in here
     file = urllib2.urlopen('http://news.sky.com/feeds/rss/world.xml')
     #convert to string
     data = file.read()
     #close the file
     file.close()
     #parse the xml from the string
     dom = parseString(data)
     #retrieve the first xml tag (<tag>data</tag>) that the parser finds with name tagName change tags to get different data
     xmlTag = dom.getElementsByTagName('title')[2].toxml()
     # the [2] indicates the 3rd title tag it finds will be parsed, counting starts at 0
     #strip off the tag (<tag>data</tag>  --->   data)
     xmlData=xmlTag.replace('<title>','').replace('</title>','')
     #write the marker ~ to serial
     ser.write('~')
     time.sleep(5)
     #split the string into individual words
     nums = xmlData.split(' ')
     #loop until all words in string have been printed
     for num in nums:
          #write 1 word
          ser.write(num)
          # write 1 space
          ser.write(' ')
          # THE DELAY IS NECESSARY. It prevents overflow of the arduino buffer.
          time.sleep(2)
     # write ~ to close the string and tell arduino information sending is finished
     ser.write('~')
     # wait 5 minutes before rechecking RSS and resending data to Arduino
     time.sleep(300)

SyntaxError: multiple statements found while compiling a single statement
>>> 
