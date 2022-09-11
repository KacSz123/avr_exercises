
#include <util/delay.h>
#include <avr/io.h>

void _7segment_init()
{
  DDRA=0xFF;
  DDRD=0xFF;
  PORTA=0xFF;

  DDRB|=(1<<PB0)|(1<<PB1);
  PORTB|=(1<<PA0);
}
#define LED (1<<PC4)
int main()
{
  _7segment_init();

   
 while(1)
  {
    for(int i=0; i<=1;++i)
    {
      PORTB=(1<<i);
        for(int j=0; j<7;++j)
          {
            PORTA=(1<<j);
            PORTD=(1<<j);
            _delay_ms(1000);
          }
    }
  
  }
  return 0;
}
