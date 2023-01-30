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

void Timer::init(String countTime)
{
  time = millis()/1000;

  hoursCount   = countTime.substring(0,2).toInt();
  minutesCount = countTime.substring(3,5).toInt();
  secondsCount = countTime.substring(6,8).toInt();

  if(secondsCount == 0){
     if(minutesCount == 0){
        hoursCount--;
     }
     minutesCount--;
  }
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
    return (int)seconds;
}

int Timer::minute()
{
    return minutes;
}

int Timer::hour()
{
    return hours;
}

String Timer::countDown()
{
    getSeconds();
    getMinutes();
    getHours();

    if(checkTimeOut() == 1) resetAll();

    return convertCountDown(hoursCount, hours) + ':' + convertCountDown(minutesCount, minutes) + ':' + convertCountDown(secondsCount, seconds);

}

String Timer::convertCountDown(int time1, int time2)
{
    if(time1 - time2 <0){
        return convert(60 -(time2 - time1));
    }else{
        return convert(time1 - time2);
    }
}

bool Timer::checkTimeOut()
{
    if(hoursCount == hours && minutesCount == minutes && secondsCount == seconds) return true;
    return false;
}

void Timer::stop()
{
    time += increaseSeconds;
}
