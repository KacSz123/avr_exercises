/**
 * @file _hd44780.h
 * @author Kacper Szczepanowski
 * @brief Library for LCD based on hd44780 driver
 *          using 4-bit bus
 * @version 0.8
 * @date 2022-09-10
 * 
 */

#ifndef HD44780_H_
#define HD44780_H_

#include<avr/io.h>
#include<util/delay.h>
// #define A DDRA
// #define B DDRB
// #define C DDRC
// #define D DDRD

// X-col & Y-rows size of display
#define LCD_X 16
#define LCD_Y 2



// RW line configuration
#define RW_ON 1
#define RW_OFF 0
#define USE_RW RW_ON // 0 - pin shorted to GND, 1 - RW conn. to μC

// configuration of D4-D7 lines of LCD
#define LCD_D7_PORT C
#define LCD_D7 2

#define LCD_D6_PORT C
#define LCD_D6 3

#define LCD_D5_PORT C
#define LCD_D5 4

#define LCD_D4_PORT C
#define LCD_D4 5

// configuration of RS, RW, E pins
#define LCD_RS_PORT B
#define LCD_RS 2

#define LCD_RW_PORT B
#define LCD_RW 1

#define LCD_E_PORT B
#define LCD_E 0
// simplify makro
// port
#define PORT(x) SPORT(x)
#define SPORT(x) (PORT##x)
//pin
#define PIN(x) SPIN(x)
#define SPIN(x) (PIN##x)
//ddr
#define DDR(x) SDDR(x)
#define SDDR(x) (DDR##x)

// defined for 4 or 2 rows displays
#if ((LCD_X==20) && (LCD_Y==4))
    #define LCD_LINE1 0x00
    #define LCD_LINE2 0x28
    #define LCD_LINE3 0x14
    #define LCD_LINE4 0x54
#else
    #define LCD_LINE1 0x00
    #define LCD_LINE2 0x40
    #define LCD_LINE3 0x10
    #define LCD_LINE4 0x50
#endif

#define SET_RS PORT(LCD_RS_PORT)|=(1<<LCD_RS)
#define RESET_RS PORT(LCD_RS_PORT)&=~(1<<LCD_RS)

#define SET_RW PORT(LCD_RW_PORT)|=(1<<LCD_RW)
#define RESET_RW PORT(LCD_RW_PORT)&=~(1<<LCD_RW)

#define SET_E PORT(LCD_E_PORT)|=(1<<LCD_E)
#define RESET_E PORT(LCD_E_PORT)&=~(1<<LCD_E)

#if USE_RW == 1
    uint8_t check_BF(void)
    {
        RESET_RS;
        return lcd_read_byte(); //!!!
    }
#endif
static inline void lcd_send_half_byte(uint8_t data)
{
    if(data&(1<<0))
        PORT(LCD_D4_PORT) |= (1<<LCD_D4);
    else 
        PORT(LCD_D4_PORT) &= ~(1<<LCD_D4);

    if(data&(1<<1))
        PORT(LCD_D5_PORT) |= (1<<LCD_D5);
    else 
        PORT(LCD_D5_PORT) &= ~(1<<LCD_D5);

    if(data&(1<<2))
        PORT(LCD_D6_PORT) |= (1<<LCD_D6);
    else 
        PORT(LCD_D6_PORT) &= ~(1<<LCD_D6);

    if(data&(1<<3))
        PORT(LCD_D7_PORT) |= (1<<LCD_D7);
    else 
        PORT(LCD_D7_PORT) &= ~(1<<LCD_D7);
}

static inline void _set_data_dir_out()
{
    DDR(LCD_D7_PORT) |= (1<<LCD_D7);
    DDR(LCD_D6_PORT) |= (1<<LCD_D6);
    DDR(LCD_D5_PORT) |= (1<<LCD_D5);
    DDR(LCD_D4_PORT) |= (1<<LCD_D4);
}

void _lcd_write_byte(unsigned char _data)
{
        _set_data_dir_out();
    #if (USE_RW == 1)
        RESET_RW;
    #endif
        SET_E;
        lcd_send_half_byte(_data>>4);//send older half of byte
        RESET_E;


        SET_E;
        lcd_send_half_byte(_data>>4);//send younger half of byte
        RESET_E;

    #if (USE_RW == 1)
        while(check_BF() & (1<<7));
    #else
        _delay_us(120);
    #endif
}

void lcd_write_cmd(uint8_t cmd)
{
    RESET_RS;
    _lcd_write_byte(cmd);
}
void lcd_write_data(uint8_t data)
{
    SET_RS;
    _lcd_write_byte(data);
}
// //initialize  pins LCD <--> uC
// #if(USE_RW==1)
//     DDR(LCD_RW_PORT) | = (1<<LCD_RW)
// #endif

#endif
