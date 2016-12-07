//I tried to modify this code to make it work for my project

// This code is for the Arduino RSS feed project, by Fritter
// Read the comment lines to figure out how it works

int startstring = 0;     // recognition of beginning of new string
int charcount = 0;     // keeps track of total chars on screen
       
#include  <LiquidCrystal.h>  // import the LiquidCrystal Library
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  lcd.begin(16,2);            // Initialize the LCD size 16x2. Change if using a larger LCD
  lcd.setCursor(0,0);     // Set cursor position to top left corner
  pinMode(13, OUTPUT);
}

void loop() {
  char incomingByte = 0;   // for incoming serial data
       
    if (Serial.available() > 0) {        // Check for incoming Serial Data
      digitalWrite(13, HIGH);
      incomingByte = Serial.read();
      if ((incomingByte == '~') && (startstring == 1)){            // Check for the closing '~' to end the printing of serial data      
        startstring = 0;                                                                  // Set the printing to off
        delay(5000);                                                                     // Wait 5 seconds
        lcd.clear();                                                                         // Wipe the screen
        charcount = 0;                                                                   // reset the character count to 0
        lcd.setCursor(0,0);                                                          // reset the cursor to 0,0
      }
      if (startstring == 1){                                                             // check if the string has begun if first '~' has been read
        if (charcount <= 30){                                                        // check if charcount is under or equal to 30
          lcd.print(incomingByte);                                                // Print the current byte in the serial
          charcount = charcount++;                                             // Increment the charcount by 1 yes I know it's awkward
        }
      }
      if (charcount == 31){                                                         // if the charcount is equal to 31 aka the screen is full
        delay(500);
        lcd.clear();                                                                        // clear the screen
        lcd.setCursor(0,0);                                                         // set cursor to 0,0
        lcd.print(incomingByte);                                                // continue printing data
        charcount = 1;                                                                 // set charcount back to 1
      }
                  
      if (incomingByte == '~'){                                                    // Check if byte is marker ~ to start the printing
                  
        startstring = 1;                                                                  // start printing
      }
    }
  digitalWrite(13, LOW);
  delay(10);                                                                            // 10ms delay for stability
 } 
