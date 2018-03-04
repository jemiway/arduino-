#include <OneWire.h>
#include <DallasTemperature.h>
#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS A0

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  byte numDigits = 4;   
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {7,6,12,11,10,8,9,13};
  
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  sensors.begin();
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(10);
}

void loop(void)
{ 
  int i=0;
  
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
//  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
//  Serial.println("DONE");
  
//  Serial.print("Temperature for the device 1 (index 0) is: ");
//  Serial.println(sensors.getTempCByIndex(0));  

    sevseg.setNumber(sensors.getTempCByIndex(0), 2);

  for (i=0;i<3000;i++)
  {
    sevseg.refreshDisplay(); // Must run repeatedly
  }
  
}
