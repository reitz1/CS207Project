/*
 * This is the code I tried to modify to use the Ethernet shield
 * for my project
 */


#include <SPI.h>

#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>


#include <LiquidCrystal.h>
#include <Ethernet.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 10,0,0,0177};
byte gw[] = {142,165,227,118};
EthernetServer server(80);
char worrd[32];
char target[7] = {'<', 't', 'i', 't', 'l', 'e', '>' };
char tolcd[80];
int counter = 0;
int lcdcount = 0;
int count = 0;
int foundcount = 0;
int linecount = 0;
boolean worded = true;
boolean taketext = false;
boolean tag = false;
int ledPin = 13;
EthernetClient client;

void setup()
{
Ethernet.begin(mac, ip);
Serial.begin(9600);
// pinMode(1, OUTPUT);
delay(1000);
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.setCursor(0,0);
lcd.print("connecting…");
Serial.println("connecting…");

if (client) {
// Print a message to the LCD.
lcd.clear();
Serial.println("connected");
delay(1000);
lcd.print("connected.");
delay(1000);
client.println("GET /rss/newsonline_uk_edition/front_page/rss.xml");
client.println();
} else {
Serial.println("connection failed");
lcd.print("connection failed.");
}
}
void loop()
{
// lcd.clear();
if (client.available()) {
//only works if xml is formatted with line breaks
/* while(linecount < 2){
char c = client.read();
if (c == 10){linecount++;}}*/
char c = client.read();
if(c == '<'){
for(int i=0; i<7; i++){
// Serial.print(c);
if(c != target[i]){ worded=false; }
c = client.read();
if(i==6 && worded==true){
//STUFF TO DO AFTER TITLE TAG GOES HERE
for(int i=0; i<80; i++){
tolcd[i]=' ';}
//Serial.print(c);
while(tag==false){
if(c=='<'){tag=true;}
tolcd[lcdcount]=c;
lcdcount++;
//Serial.print(c);
c = client.read();
}
for(int i=0; i<16; i++){
tolcd[lcdcount-1]=(' ');
lcdcount++;
}
Serial.print(lcdcount);
for(int p=0; p<(lcdcount-16); p++){
char dispchar = tolcd[p];
Serial.print(dispchar);
for(int i=0; i<16; i++){
lcd.setCursor(0, 0);
lcd.print("Headlines:");
char displaychar = tolcd[(i+counter)%lcdcount];
lcd.setCursor(i,1);
lcd.print(displaychar);
}
if(p==0){delay(1000);}
counter++;
delay(120);
}
counter=0;
lcdcount=0;
if(tag==true){tag=false; Serial.println(" ");}
}
}
}
if(worded==false){worded=true;}
}
}
