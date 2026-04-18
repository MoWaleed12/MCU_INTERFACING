#include "STD_TYPES.h"   
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "Segments.h"
#include "KEYPADMO.h"


#define F_CPU 16000000UL  
#include <avr/io.h>
#include <util/delay.h>



int main(void) {
    u8 key = 0;
    u8 num1 = 0, num2 = 0, result = 0;
    u8 operator = 0;
    u8 step = 1; 

    SEVENSEG_VidInit(GPIO_PORTD);
    Keypad_init();
    
   
    GPIO_VidSetPortDirection(GPIO_PORTD, GPIO_PORT_OUTPUT);

    while(1) {
       
        key = Get_Pressed_Key(); 

        if (key != 0) { 
           
            if (key >= '0' && key <= '9') {
                u8 currentDigit = key - '0'; 
               SevenSeg_Display(GPIO_PORTD, currentDigit, SEVENSEG_COMMON_CATHODE);
                
                if (step == 1) {
                    num1 = currentDigit;
                    step = 2; 
                } else if (step == 3) {
                    num2 = currentDigit;
                    step = 4; 
                }
            }
            
            
            else if (key == '+' || key == '-' || key == '*' || key == '/') {
                if (step == 2) {
                    operator = key;
                    step = 3; 
                }
            }
            
            
            else if (key == '=') {
                if (step == 4) {
                    if      (operator == '+') result = num1 + num2;
                    else if (operator == '-') result = (num1 >= num2) ? (num1 - num2) : 0;
                    else if (operator == '*') result = num1 * num2;
                    else if (operator == '/' && num2 != 0) result = num1 / num2;

                    
                    if (result <= 9) {
                        SevenSeg_Display(GPIO_PORTD, result, SEVENSEG_COMMON_CATHODE);
                    } else {
                        
                        GPIO_VidSetPortValue(GPIO_PORTD, 0x79); 
                    }
                    
                    
                    step = 1; 
                }
            }
            
           
            else if (key == '.') {
                step = 1;
                    GPIO_VidSetPortValue(GPIO_PORTD, 0x00); 
            }
        }
    }
}