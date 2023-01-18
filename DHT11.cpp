/*
  link to the DHT11 datasheet:
    https://html.alldatasheet.com/html-pdf/1440068/ETC/DHT11/395/6/DHT11.html
*/

#include "DHT11.hpp"
#include<Arduino.h>

DHT11::DHT11(int pin)
: pin(_pin) {}

DHT11::~DHT11{~pin;}

void DHT11::get_data(){
  //init here
  pinMode(_pin,OUTPUT);
  digitalWrite(_pin,LOW);
  delay(20);
  pinMode(_pin,INPUT_PULLUP);
  delayMicroseconds(55);

  get_time(80,HIGH);
  get_time(80,LOW);

  //getbyte here
  for(int i=0;i<5;i++){
    for(int j=0;j<8;j++){
      int time_50 =get_time(50,HIGH);
      int time = get_time(70,LOW);
      if(time< time_50){
        (data[i] <<=1);
      }else{
        data[i] = (data[i] <<1) |1;
      }
    }
  }
  if(debug() == false) Serial.println("Error");
}

float DHT11::get_temperature(bool C){
    if(C){
        return data[2];
    }else{
        return (data[2]*9/5 +32);
    }
}

int DHT11::get_humidity(){
  return data[0];
}


int DHT11::get_time(int up,bool state){
    uint16_t count = micros();
    while(1){
        if(digitalRead(_pin)== state){
            return micros()-count;
        }
    }
}

bool DHT11::debug()
{
    if(data[0]+data[1]+data[2]+data[3] != data[4]) return false;
    return true;
}
