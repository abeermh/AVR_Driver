#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KPAD_Private.h"
#include"KPAD_Config.h"
u8 Kpadbtn[4][4]=KEY_BOARD;
u8 Rowarr[]={r1,r2,r3,r4};
u8 colarr[]={c1,c2,c3,c4};


void KPAD_VidInit()
{
	DIO_VidSetPortDirection(Key_Port,0xf0);
	DIO_VidSetPortValue(Key_Port,0x0f);//to activate pull up resistance
}

u8 KPAD_U8GetKey(){
	u8 pressed=KEY_NOT_PRESSED;

	for(u8 c=0;c<4;c++){
		DIO_VidSetPinValue(Key_Port,colarr[c],Low);
		for(u8 r=0;r<4;r++){
			if(!DIO_U8GetPinValue(Key_Port,Rowarr[r]))
			{
				pressed=Kpadbtn[r][c];
				while(!DIO_U8GetPinValue(Key_Port,Rowarr[r])){}
				DIO_VidSetPinValue(Key_Port,colarr[c],High);
				return pressed;
			}else{}}
		DIO_VidSetPinValue(Key_Port,colarr[c],High);
	}

return KEY_NOT_PRESSED;
}
