#include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include"../DIO/DIO_Interface.h"
#include "Ex_It_private.h"
 #define NULL 0

static void (*PVidCallback)(void*)=NULL;
 void*Gptr=NULL;

void EXIT_VidCallback(void (*Copy_PVidCallback)(void*),void * Copy_VoidPtr)
{
	 PVidCallback=Copy_PVidCallback;
	 Gptr=Copy_VoidPtr;
}


void ExIt_VidInit0(SenseControl Copy_SenseControl){

	MCUCR|=(Copy_SenseControl);
 }

void ExIt_VidInit1(SenseControl Copy_U8SenseControl){

	MCUCR|=(Copy_U8SenseControl<<ISC10);
}

void ExIt_VidInit2(Int2_SenseControl Copy_SenseControl){
	if (Copy_SenseControl==FALL){
		CLR_BIT(MCUCSR,ISC2);}
	else if (Copy_SenseControl==RIS){
		SET_BIT(MCUCSR,ISC2);}


}

void ExIt_VidEnable(u8 Copy_U8IntNum){
	if(Copy_U8IntNum==0){
	SET_BIT(GICR,EX_INT0);}
	else if(Copy_U8IntNum==0){
		SET_BIT(GICR,EX_INT1);}
	else if(Copy_U8IntNum==0){
		SET_BIT(GICR,EX_INT2);}

}

void ExIt_VidDisable(u8 Copy_U8IntNum){
	if(Copy_U8IntNum==0){
	CLR_BIT(GICR,EX_INT0);}
	else if(Copy_U8IntNum==0){
		CLR_BIT(GICR,EX_INT1);}
	else if(Copy_U8IntNum==0){
		CLR_BIT(GICR,EX_INT2);}
}

//ISR for int0 ID=1 for led
void __vector_1(void)
{	  if(PVidCallback!=NULL)
{
	PVidCallback(Gptr);}
 }

