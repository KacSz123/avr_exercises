
#include <util/delay.h>
#include <avr/io.h>

#ifndef _BV
#define _BV(bit)				(1<<(bit))
#endif
#ifndef sbi
#define sbi(reg,bit)		reg |= (_BV(bit))
#endif
 
#ifndef cbi
#define cbi(reg,bit)		reg &= ~(_BV(bit))
#endif
#define TIME 100
//#define TIME2 500
/** 
 * @autor: Kacper Szczepanowski
 * 
 */
volatile uint8_t zmienna[10];
uint8_t tab[8]={1,2,4,8,16,32,64,128};
uint8_t tab2[8]={1,2,4,8,16,32,64,128};
int main(void)
{ 
    DDRC=31;
    int i;
     //   _delay_ms(1000);
	while (1) 
    {   
    //PC0
        
        PORTC=31;
        _delay_ms(500);
        for(i=0;i<=5;++i)
        {
            PORTC=(31>>i);
            _delay_ms(500);
        }

	}
}