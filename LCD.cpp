/* 
It lacks a lot of feature though but i write it for fun so anyway :)))
Note that this library was written based on LiquidCrystle_I2C library on GITHUB 
The link to the datasheet of HD448780:
	https://html.alldatasheet.com/html-pdf/63673/HITACHI/HD44780/11541/46/HD44780.html
*/

#include "LCD.hpp"
#include<stdint.h>
#include<Arduino.h>
#include<Wire.h>

LCD::LCD(uint8_t _address)
: address(_address) {};

LCD::~LCD()
{
    ~address;
}

void LCD::init()
{
  Wire.begin();
  delay(50);
  write_bit(0x03<<4);
  delayMicroseconds(4500);
  write_bit(0x03<<4);
  delayMicroseconds(4500);
  write_bit(0x03<<4);
  delayMicroseconds(150);
  home();
  command(0x04);
  clear();
  command(0x28 | 0x06);
  on();
}

void LCD::off()
{
  command(0x08);
  delay(500);
}

void LCD::on()
{
  command(0x0C);
  delay(500);
}

void LCD::home()
{
  command(0x02);
  delay(500);
}

void LCD::setCursor(uint8_t row, uint8_t column)
{
  !row ? (command(0x80|column)) : (command(0xC0 | column));
}

void LCD::clear()
{
  command(0x01);
  delay(500);
}

void LCD::print(String s)
{
  for(int i=0;i<s.length();i++)
    send(s[i],1);
}

void LCD::print_number(int number)
{
  String s = String(number);
   for(int i=0;i<s.length();i++)
    send(s[i],1);
}

void LCD::command(uint8_t value)
{
  send(value,0);
}

void LCD::write_bit(uint8_t value)
{
  Wire.beginTransmission(address);
  Wire.write(value| 0x04);
  Wire.endTransmission();
  delayMicroseconds(1);

  Wire.beginTransmission(address);
  Wire.write(value &~0x04);
  Wire.endTransmission();
  delayMicroseconds(50);

  Wire.beginTransmission(address);
  Wire.write((int)(value |0x08));
  Wire.endTransmission();

}

void LCD::send(uint8_t value,bool mode)
{
  uint8_t highnib=value&0xf0;
  uint8_t lownib=(value<<4)&0xf0;
  write_bit((highnib)|mode);
  write_bit((lownib)|mode);
}
