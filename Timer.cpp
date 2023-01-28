#include "Timer.hpp"
#include<Arduino.h>

String Timer::getTime()
{
  return currentHours() + ':' + currentMinutes() + ':' + currentSeconds();
}

String Timer::currentHours()
{
    getHours();
    return convert(hours);
}

String Timer::currentMinutes()
{
    getMinutes();
    return convert(minutes);
}

String Timer::currentSeconds()
{
    getSeconds();
    return convert(seconds);
}

void Timer::getSeconds()
{
  seconds = millis()/1000 - time;
}

void Timer::getMinutes()
{
  if(seconds >=60)
  {
    resetSeconds();
    minutes++;
  }
}

void Timer::getHours()
{
  if(minutes >=60)
  {
    resetMinutes();
    hours++;
  }

  if(hours == 24) resetHours();
}

String Timer::convert(int number)
{
  if(number >=10){
    return String(number);
  }else{
    return '0' + String(number);
  }
}

void Timer::init()
{
  time = millis()/1000;
}

void Timer:: resetSeconds()
{
    time +=seconds;
    seconds =0;
}

void Timer::resetHours()
{
    hours =0;
}

void Timer::resetMinutes()
{
    minutes =0;
}

void Timer::resetAll()
{
    resetHours();
    resetMinutes();
    resetSeconds();
}

int Timer::second()
{
    return seconds;
}

int Timer::minute()
{
    return minutes;
}

int Timer::hour()
{
    return hours;
}

