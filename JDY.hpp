#ifndef _JDY_
#define _JDY_

#include<Arduino.h>
#include<SoftwareSerial.h>
#include<stdint.h>

class JDY
{
  private:
    String name, data;
    SoftwareSerial* device;

  public:
    JDY(SoftwareSerial* _device);
    ~JDY();
    String getCommand();
};

#endif
