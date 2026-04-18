/* 
 * File:   Segments.h
 * Author: e l m o 7 t a r e f
 *
 * Created on 17 ?????, 2026, 08:37 ?
 */

#ifndef SEGMENTS_H
#define	SEGMENTS_H
#include "STD_TYPES.h"


#define SEVENSEG_COMMON_CATHODE  0
#define SEVENSEG_COMMON_ANODE    1


void SEVENSEG_VidInit(u8 Copy_U8Port);
void SEVENSEG_VidDisplayNumber(u8 Copy_U8Port, u8 Copy_U8Number);



void SevenSeg_Display(u8 port, u8 num, u8 type);


#endif	/* SEGMENTS_H */

