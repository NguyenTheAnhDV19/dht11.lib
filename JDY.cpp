#include "JDY.hpp"
#include<Arduino.h>
#include<SoftwareSerial.h>
#include<stdint.h>

JDY::JDY(SoftwareSerial* _device)
: device(_device){}

JDY::~JDY()
{
  delete device;
}

String JDY::getCommand()
{
  String data;
   /* send data from JDY to ARDUINO*/
  if(device->available()){
   data += device->readString();
   data = data.substring(0,data.length()-2);
   Serial.println(data);
  }
  return data;
}

