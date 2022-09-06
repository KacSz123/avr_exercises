/**
 * @autor: Kacper Szczepanowski
 *
 */
#include <util/delay.h>
#include <avr/io.h>

//MAcro section
#define TIME 100
#define TIME2 1000
#define SWITCH PC1
#define LED PD0
#define LED_ON PORTD|=(1<<LED)
#define LED_OFF PORTD&=~(1<<LED)
#define LED_TOGGLE PORTD^=(1<<LED)
#define SWITCH_DOWN !(PINC&(1<<SWITCH))

//init of PORTD
void ddrd_init()
{
    DDRD = 0b11111111;
}

void portd_pin_set(int bit)
{
    PORTD |= (1 << bit);
}
void portd_pin_reset(int bit)
{
    PORTD &= ~(1 << bit);
}
void four_led_blink()
{
    PORTD = 0;
    int i;
    for (i = 0; i < 4; ++i)
    {
        portd_pin_set(i);
        _delay_ms(TIME2);
        portd_pin_reset(i);
    }

    for (i = 2; i >= 1; --i)
    {
        portd_pin_set(i);
        _delay_ms(TIME2);
        portd_pin_reset(i);
    }
}
int is_key_down()
{                
            if ( SWITCH_DOWN)
        {
            _delay_ms(50);
            if ( SWITCH_DOWN)
                return 1;
                //PORTD ^= (1 << LED);
            _delay_ms(200);
        }
        return 0;
}
void switch_init()
{
    DDRC = 0b00000000; // set PC3 as input
    PORTC |= (1 << SWITCH);
}
void snake()
{
        PORTD = 0;
    int i;
    for (i = 0; i < 8; ++i)
    {
        portd_pin_set(i);
        _delay_ms(TIME2);
        portd_pin_reset(i);
    }

    for (i = 6; i >= 1; --i)
    {
        portd_pin_set(i);
        _delay_ms(TIME2);
        portd_pin_reset(i);
    }
}

int main(void)
{

    ddrd_init();
    while (1)
    {
        snake();
    }
}





// #ifndef _BV
// #define _BV(bit) (1 << (bit))
// #endif
// #ifndef sbi
// #define sbi(reg, bit) reg |= (_BV(bit))
// #endif

// #ifndef cbi
// #define cbi(reg, bit) reg &= ~(_BV(bit))
// #endif