#ifndef _DHT11_
#define _DHT11_
#include<Arduino.h>
#include<stdint.h>
#include<stdio.h>

class DHT11{
private:
  uint8_t data[5];
  int _pin;
  int get_time(int up, bool state);
  bool debug();

public:
  DHT11(int pin);
  ~DHT11();
  void get_data();
  float get_temperature(bool C);
  int get_humidity();
};

#endif
