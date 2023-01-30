#ifndef _TIMER_
#define _TIMER_

#include<Arduino.h>

class Timer
{
  public:
    String getTime();
    String countDown();
    String convertCountDown(int time1, int time2);
    void init(String countTime);
    bool checkTimeOut();
    void resetSeconds();
    void resetMinutes();
    void resetHours();
    void resetAll();
    int second();
    int minute();
    int hour();
    void stop();
  
  private:
    int hours,minutes;
    unsigned long seconds,time;
    int hoursCount,minutesCount,secondsCount;
    void getSeconds();
    void getMinutes();
    void getHours();
    String currentHours();
    String currentMinutes();
    String currentSeconds();
    String convert(int number);
};

#endif

