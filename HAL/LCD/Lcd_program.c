
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include<util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Lcd_Private.h"
#include "Lcd_Config.h"



void LCD_VidSendData(u8 Copy_U8Data){
	DIO_VidSetPinValue(PortC,Rs_Pin,Data);
	LCD_VidLatch(Copy_U8Data);
}

void LCD_VidSendCommand(u8 Copy_U8Command){
	DIO_VidSetPinValue(PortC,Rs_Pin,Command);
	LCD_VidLatch(Copy_U8Command);
}

static void LCD_VidLatch(u8 Copy_U8SendData){
	DIO_VidSetPinValue(PortC,Rw_Pin,Write);
	DIO_VidSetPortValue(PortD,Copy_U8SendData);
	DIO_VidSetPinValue(PortC,En_Pin,High);
	_delay_ms(1);
	DIO_VidSetPinValue(PortC,En_Pin,Low);
	_delay_ms(50);
}

void LCD_VidReadData()
{
	LCD_VidGoToXY(1,0);//go to DDRAM
	DIO_VidSetPinValue(PortC,Rs_Pin,Data);
	DIO_VidSetPinValue(PortC,Rw_Pin,Read);


}
void LCD_VIDPrintString(u8 Copy_U8String[]){

	for(int i=0;Copy_U8String[i]!='\0';i++)
	{
		LCD_VidSendData(Copy_U8String[i]);
	}
}

void LCD_VidInit(){
	DIO_VidSetPinDirection(PortC,En_Pin,Output);
	DIO_VidSetPinValue(PortC,En_Pin,Low);//to make the pulse from low
	DIO_VidSetPinDirection(PortC,Rw_Pin,Output);
	DIO_VidSetPinDirection(PortC,Rs_Pin,Output);
	DIO_VidSetPortDirection(PortD,0xff);

#if LCD_Mode==Eight_Bit
	_delay_ms(50);
	LCD_VidSendCommand(LCD_8BSetFunc);
	_delay_ms(1);
	LCD_VidSendCommand(LCD_8BDisplayControl);
	_delay_ms(1);
	LCD_VidSendCommand(LCD_8BDisplayClear);
	_delay_ms(2);
	LCD_VidSendCommand(LCD_8BModeSet);
	_delay_ms(2);



#elif LCD_Mode==Four_Bit
	_delay_ms(50);
	LCD_VidSendCommand(0x20);
	LCD_VidSendCommand(0x20);
	LCD_VidSendCommand(0xc0);
	_delay_ms(1);
	LCD_VidSendCommand(0x00);
	LCD_VidSendCommand(0xf0);
	_delay_ms(1);
	LCD_VidSendCommand(0x00);
	LCD_VidSendCommand(0x10);
	_delay_ms(2);
	LCD_VidSendCommand(0x00);
	LCD_VidSendCommand(0x70);

#else
#error "wrong mode"
#endif
}

void LCD_VidGoToXY(u8 Copy_U8Row,u8 Copy_U8col ){
	if(Copy_U8Row==0)
	{
		LCD_VidSendCommand(128+Copy_U8col);
	}
	else if(Copy_U8Row==1)
	{
		LCD_VidSendCommand(128+64+Copy_U8col);
	}	}


void LCD_VidDraw(u8* Copy_U8Draw , u8 Copy_U8Size ){

	LCD_VidSendCommand(CGRAM_ADDRESS);//set CGRAM address

	for(int Local_U8Iterator=0;Local_U8Iterator<Copy_U8Size*8;Local_U8Iterator++){
		LCD_VidSendData(Copy_U8Draw[Local_U8Iterator]);
	}

	LCD_VidSendCommand(0x04);//set entry mode
 	LCD_VidGoToXY(POS_X,POS_Y);
	for(int Local_U8Iterator=0;Local_U8Iterator<Copy_U8Size;Local_U8Iterator++){
		LCD_VidSendData(Local_U8Iterator);
	}
}

void LCD_VidClearDisplay()
{
	LCD_VidSendCommand(LCD_8BDisplayClear);
}

void LCD_VidMovingDraw(u8* Copy_U8Draw, u8 Copy_U8Size ){
	//LCD_VidSendCommand(LCD_8BDisplayClear);
	u8 i=0,j=0;
	//LCD_VidSendCommand(0x04+decrease);
	while(j<2){
	while(i+POS_Y<16){
		LCD_VidSendCommand(LCD_8BDisplayClear);
		LCD_VidGoToXY(POS_X+j,POS_Y+i);
		i+=Copy_U8Size;
		for(int Local_U8Iterator=0;Local_U8Iterator<Copy_U8Size;Local_U8Iterator++){
				LCD_VidSendData(Copy_U8Size-1-Local_U8Iterator);
			}
		_delay_ms(3000);
	}
	j++;
	i=0;}
}
void LCD_VidPrintIntNumber(u32 Copy_U32Number){
	u8 Local_U8Digit;
	u32 Local_U32Reminder=Copy_U32Number,Local_U32Reverse=0;
	for(Local_U8Digit=0;Local_U32Reminder;Local_U8Digit++){
		Local_U32Reverse=(Local_U32Reverse*10)+(Local_U32Reminder%10);
		Local_U32Reminder/=10;}
	for(Local_U8Digit=0;Local_U32Reverse;Local_U8Digit++){
		LCD_VidSendData(Ascii_Zero+(Local_U32Reverse%10));
		Local_U32Reverse/=10;
	}}

void LCD_VidPrintFloatNumber(f32 Copy_U32FNumber){
	u32 Local_U32IntNum=(u32)Copy_U32FNumber;
	u32 Local_U32FractionalNum=(Copy_U32FNumber-Local_U32IntNum)*10000;//to get five numbers after point
	LCD_VidPrintIntNumber(Local_U32IntNum);
	LCD_VidSendData('.');
	LCD_VidPrintIntNumber(Local_U32FractionalNum);
}

