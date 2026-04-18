#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "Segments.h"


const u8 Segments_Array[] = {
    0x3F, 
    0x06, 
    0x5B, 
    0x4F,
    0x66,
    0x6D,
    0x7D, 
    0x07,
    0x7F, 
    0x6F  
};


void SevenSeg_Display(u8 port, u8 num, u8 type) {
    if (num <= 9) {
        u8 val = Segments_Array[num];
        if (type == SEVENSEG_COMMON_ANODE) {
            val = ~val; 
        }
        GPIO_VidSetPortValue(port, val);
    }
}


void SEVENSEG_VidInit(u8 Copy_U8Port) {
    GPIO_VidSetPortDirection(Copy_U8Port, 0xFF); 
}