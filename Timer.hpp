#ifndef _TIMER_
#define _TIMER_

#include<Arduino.h>

class Timer
{
  public:
    String getTime();
    void init();
    void resetSeconds();
    void resetMinutes();
    void resetHours();
    void resetAll();
    int second();
    int minute();
    int hour();

  private:
    int hours,minutes;
    unsigned long seconds,time;
    void getSeconds();
    void getMinutes();
    void getHours();
    String currentHours();
    String currentMinutes();
    String currentSeconds();
    String convert(int number);

};

#endif
