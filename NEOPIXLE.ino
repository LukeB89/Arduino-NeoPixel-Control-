#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 3
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

char incomingByte[11], RedC[3], GreenC[3], BlueC[3];   // for incoming serial data
int Red, Green, Blue, inc;
void setup() 
{ 
      Serial.begin(57600);
      FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      
    
}

void loop() 
{ 
//  for(int i = 0; i<NUM_LEDS; i++)
//  {
//    for(int j = 0; j<255; j++)
//    {
//      // Turn the LED on, then pause
//      leds[i] = CHSV( j, 150, 150);
//      FastLED.show();
//      delay(100);
//    }
//  }
if (Serial.available() > 0) 
{
  inc = 0;
  // read the incoming byte:
  Serial.readBytes(incomingByte,11);
  char* command = strtok(incomingByte, ":");
  while (command != 0)
  {
    Red = atoi(command);
    command = strtok(0,":");
    Green = atoi(command);
    command = strtok(0,":");
    Blue = atoi(command);
    command = strtok(0,":");
  }
  

  
  // say what you got:
  Serial.print("R: ");
  Serial.println(Red);
  Serial.print("G: ");
  Serial.println(Green);
  Serial.print("B: ");
  Serial.println(Blue);
}
//Serial.readBytes(11
//FastLED.setBrightness(150);
leds[0] = CRGB(Red,Green,Blue);
leds[1] = CRGB(Red,Green,Blue);
leds[2] = CRGB(Red,Green,Blue);
FastLED.show();    
}
  
  

