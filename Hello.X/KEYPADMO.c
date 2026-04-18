
#include "KEYPADMO.h"

const u8 Keypad[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'0', '.', '=', '+'}
};


void Keypad_init(void){
    KEYPAD_DDR = 0X00;
    KEYPAD_PORT |=1<<0|1<<1|1<<2|1<<3;
}

u8 Get_Pressed_Key(void){
    
    u8 row,colm;
    
    for(colm = 0; colm <= 3; colm++){
        _delay_ms(10);
        KEYPAD_DDR &=~(1<<4|1<<5|1<<6|1<<7);
        KEYPAD_DDR |=1<<(colm+4);
        KEYPAD_PORT &=~1<<(colm+4);
        
        for(row = 0; row <= 3; row++){
            if((KEYPAD_PIN & 1<<row) == 0){
                return (Keypad[row][colm]);
            }
        }
    }
    return 0XFF;
}