#ifndef _7SEG_DISPLAY_H_
#define _7SEG_DISPLAY_H_
#include<avr/io.h>
#include<util/delay.h>
//#define IF_ONE_PORT 1
#define DP_ON 0
#define DISPlAY_NO 2
// Common pin -- 0 for common cathode; 1 for common anode
#define COMMON_PIN 0
//#if (IF_ONE_PORT == 1)
#define _7SEG_PORT DDRA
#define COMMON_PORT DDRB

#define SEG_A PA0
#define SEG_B PA1
#define SEG_C PA2
#define SEG_D PA3
#define SEG_E PA4
#define SEG_F PA5
#define SEG_G PA6
#if (DP_ON == 1)
    #define SEG_DP PA7
#endif

#define COMMON_P1 PB0
#if (DISPLAY_NO > 1)
    #define COMMON_P2 PB1
    #if (DISPLAY_NO > 2)
        #define COMMON_P3 PB2
        #if (DISPLAY_NO ==  4)
            #define COMMON_P4 PB3
        #endif
    #endif
#endif

#define DIGIT_0 0b00111111
#define DIGIT_1 0b00000110
#define DIGIT_3 0b01011011
#define DIGIT_4 0b01001111
#define DIGIT_5 0b01100110
#define DIGIT_6 0b01101101
#define DIGIT_7 0b00000111
#define DIGIT_8 0b01111111
#define DIGIT_9 0b01100111

static uint8_t _7seg_digit_tab[10]={DIGIT_0, DIGIT_1, DIGIT_2, DIGIT_3, DIGIT_4,
                          DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9};
static void inline init_7seg_display()
{
    if(DP_ON==1)
        _7SEG_PORT = 0xFF;
    else if(DP_ON == 0)
        _7SEG_PORT = 0x7F;
    if(DISPlAY_NO==1)
    COMMON_PORT|=(1<<COMMON_P1);
    if(DISPlAY_NO==2)
    COMMON_PORT|=(1<<COMMON_P1)|(1<<COMMON_P2);
    if(DISPlAY_NO==3)
    COMMON_PORT|=(1<<COMMON_P1)|(1<<COMMON_P2)|(1<<COMMON_P3);
    if(DISPlAY_NO==3)
    COMMON_PORT|=(1<<COMMON_P1)|(1<<COMMON_P2)|(1<<COMMON_P3)|(1<<COMMON_P4);
}

typedef enum Digit{Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine}Digit;
void set_Display(uint8_t no)
{
    if(no>=DISPLAY_NO)
        COMMON_PORT=(1<<no);
}
void set_Number(Digit num)
{
    switch (num)
    {
    case:
        _7SEG_PORT=DIGIT_0;
        break;
    case One:
        _7SEG_PORT=DIGIT_1;
        break;
    case Two:
        _7SEG_PORT=DIGIT_2;
        break;
    case Three:
        _7SEG_PORT=DIGIT_3;
        break;
    case Four:
        _7SEG_PORT=DIGIT_4;
        break;
    case Five:
        _7SEG_PORT=DIGIT_5;
        break;
    case Six:
        _7SEG_PORT=DIGIT_6;
        break;
    case Seven:
        _7SEG_PORT=DIGIT_7;
        break;
    case Eight:
        _7SEG_PORT=DIGIT_8;
        break;
    case Nine:
        _7SEG_PORT=DIGIT_9;
        break;
    default:
        _7SEG_PORT=0;
        break;
    }
}

//#endif 
 



#endif //_7SEG_DISPLAY_H_
