#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

void LCD_VidSendData(u8 Copy_U8Data);
void LCD_VidSendCommand(u8 Copy_U8Command);
void LCD_VidInit();
void LCD_VidGoToXY(u8 Copy_U8Row,u8 Copy_U8col );
void LCD_VIDPrintString(u8 Copy_U8String[]);
void LCD_VidDraw(u8* Copy_U8Draw , u8 Copy_U8Size );
void LCD_VidPrintIntNumber(u32 Copy_U32Number);
void LCD_VidPrintFloatNumber(f32 Copy_U32FNumber);
void LCD_VidMovingDraw(u8* Copy_U8Draw, u8 Copy_U8Size );
void LCD_VidReadData();
void LCD_VidClearDisplay();

#define MYNAME  { 0x00,0x00,0x07,0x04,0x1F,0x00,0x00,0x00,\
				  0x00,0x00,0x04,0x04,0x1F,0x00,0x04,0x00,\
				  0x00,0x00,0x04,0x04,0x1F,0x00,0x0A,0x00,\
				  0x00,0x00,0x00,0x04,0x07,0x04,0x08,0x10}

#define DRAWMAN {0x0E,0x0A,0x0E,0x04,0x0E,0x15,0x04,0x0A}

#endif
