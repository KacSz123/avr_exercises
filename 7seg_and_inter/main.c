#include<stdio.h>
#include<avr/io.h>
#include<util/delay.h>
//#include "7seg_display.h"



void _7segment_init()
{
  DDRA=0xFF;
  DDRD=0xFF;
  PORTA=0xFF;

  DDRB|=(1<<PB0)|(1<<PB1);
  PORTB|=(1<<PA0);
} 

uint8_t _7seg_num_tab[10]={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110,
                           0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01100111};
int main()
{
 _7segment_init();
 while(1)
 {
  for(int i=0; i<10;++i)
    {
      PORTA=_7seg_num_tab[i];
      _delay_ms(1000);
    }
 }
  return 0;
}
