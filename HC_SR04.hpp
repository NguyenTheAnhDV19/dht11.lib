#ifndef _HC_SR04_
#define _HC_SR04_
#include<Arduino.h>
#include<stdint.h>

class SR04{

  private:
    uint8_t distance;
    uint8_t trigger,echo;
    int get_time();

  public:
    SR04(uint8_t _trigger, uint8_t _echo);
    ~SR04();
    void init();
    float result();
    void get_data();
};

#endif
