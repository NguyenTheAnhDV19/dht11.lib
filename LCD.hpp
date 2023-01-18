#ifndef _LCD_H_
#define _LCD_H_
#include<stdint.h>
#include<Arduino.h>

class LCD{
private:
  uint8_t address;
  void send(uint8_t value,bool mode);
  void command(uint8_t value);
  void write_bit(uint8_t value);
  void home();
  void on();

public:
  LCD(uint8_t _address);
   ~LCD();
  void init();
  void print(String s);
  void print_number(int number);
  void clear();
  void setCursor(uint8_t row,uint8_t column);
  void off();
};

#endif 
