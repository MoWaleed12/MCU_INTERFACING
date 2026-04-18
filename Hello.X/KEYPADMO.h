/* 
 * File:   KEYPADMO.h
 * Author: e l m o 7 t a r e f
 *
 * Created on 17 ?????, 2026, 06:59 ?
 */

#ifndef KEYPADMO_H
#define	KEYPADMO_H

#define F_CPU 16000000UL
#ifndef F_CPU 
#endif
#include "STD_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_DDR DDRC
#define KEYPAD_PORT PORTC
#define KEYPAD_PIN PINC
extern const u8 Keypad[4][4]; 

void Keypad_init(void);
u8 Get_Pressed_Key(void);




#endif	/* KEYPADMO_H */

