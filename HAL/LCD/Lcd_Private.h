#ifndef _LCD_PRIVATE_H
#define _LCD_PRIVATE_H

#define Four_Bit 0
#define Eight_Bit 1
#define Write 0
#define Read  1
#define Command  0
#define Data 1
#define En_Pin 0
#define Rw_Pin 1
#define Rs_Pin 2
#define Ascii_Zero 48
#define increase 1		//to display English
#define decrease 0		//to display arabic
#define shift 1		//shift to right in arabic and to the left in english

static void LCD_VidLatch(u8 Copy_U8SendData);

#define LCD_8BSetFunc 0x38
#define LCD_8BDisplayControl  0x0e
#define LCD_8BDisplayClear 0x01
#define LCD_8BModeSet 0x03

#define CGRAM_ADDRESS 0x40
#endif
