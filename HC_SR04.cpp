#include "HC_SR04.hpp"
#include<Arduino.h>
#include<stdint.h>

SR04::SR04(uint8_t _trigger, uint8_t _echo)
:trigger(_trigger), echo(_echo) {}

void SR04::init()
{
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT_PULLUP);
  digitalWrite(trigger,LOW);
}

void SR04::get_data()
{
  delayMicroseconds(10);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  distance = get_time()/58;
}

float SR04::result()
{
  return distance;
}

int SR04::get_time()
{
  return pulseIn(echo,HIGH);
}
