/*
 * Timer_Progoram.c
 *
 *  Created on: Nov 4, 2020
 *      Author: Abeer
 */
#include"../../../lib/STD_Types.h"
#include"../../../lib/BIT_MATH.h"
#include"../../../lib/AVR32_REG.h"
#include"../../DIO/DIO_Interface.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"
#define NULL ((void*)0)

/*
 * Fast BWM Frequencies:
 * */

void (*TIMER0_PVidCallback [2])(void*)={NULL,NULL};
void  *TIMER0_Gptr[2] ={NULL,NULL}   ;


u8 Global_U8Preload,Global_U8Counter;
/***********************************************************************************************
 * 								INITIATE TIME 0
 * *********************************************************************************************/
void Timer0_VidInit(u8 Copy_U8Mode){

	//select mode & oc0 state
	if (Copy_U8Mode == OVER_FLOW){
		CLR_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);
#if TIMER_OC0STATE==OC_DISCONNECT
		TCCR0|=(OC_DISCONNECT<<COM00);
#endif
	}else if (Copy_U8Mode == CTC){
		SET_BIT(TCCR0,WGM01);
		CLR_BIT(TCCR0,WGM00);
#if TIMER_OC0STATE==OC_DISCONNECT
		TCCR0|=(OC_DISCONNECT<<COM00);
#elif TIMER_OC0STATE==OC_TOGGLE
		TCCR0|=(OC_TOGGLE<<COM00);
#elif TIMER_OC0STATE==OC_CLEARTOP
		TCCR0|=(OC_CLEARTOP<<COM00);
#elif TIMER_OC0STATE==OC_SETTOP
		TCCR0|=(OC_SETTOP<<COM00);
#endif
	}else if( Copy_U8Mode == FAST_PWM){
		SET_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
#if TIMER_OC0STATE==OC_CLEARTOP
		TCCR0|=(OC_CLEARTOP<<COM00);
#elif TIMER_OCSTATE==OC_SETTOP
		TCCR0|=(OC_SETTOP<<COM00);
#endif
	}else if( Copy_U8Mode == PWM_PHASE_CORRECT){
		CLR_BIT(TCCR0,WGM01);
		SET_BIT(TCCR0,WGM00);
#if TIMER_OC0STATE==OC_CLEARTOP
		TCCR0|=(OC_CLEARTOP<<COM00);
#elif TIMER_OC0STATE==OC_SETTOP
		TCCR0|=(OC_SETTOP<<COM00);
#endif
		}

	}

void Timer0_VidPrescaller( u8 Copy_U8Prescaller){

	TCCR0&= 0XF8;
	TCCR0 |=Copy_U8Prescaller;

}

void Timer0_VidPreload(u8 Copy_U8PreloadValue)
{
	TCNTO=Copy_U8PreloadValue;
}

void OverFlowTimer0_VidInit( u8 Copy_U8Prescaller,u8 Copy_U8DesireTime_ms)
{
	f32 Local_f32OVT=TOV,Local_f32Counter;
	u8 Local_U8Counts;
	Timer0_VidInit(OVER_FLOW);
	Timer0_VidPrescaller( Copy_U8Prescaller);
	if(Copy_U8Prescaller==PS_8){
		Local_f32OVT*=8;
	}
	else if(Copy_U8Prescaller==PS_64){
		Local_f32OVT*=64;
	}
	else if(Copy_U8Prescaller==PS_256){
		Local_f32OVT*=256;
	}
	else if(Copy_U8Prescaller==PS_1024){
		Local_f32OVT*=1024;
	}
	if(Copy_U8DesireTime_ms>Local_f32OVT){
		Local_f32Counter=(f32)(Copy_U8DesireTime_ms/TOV);
		Global_U8Counter=(u8)Local_f32Counter+1;
		Local_U8Counts=(u8)(T_OVCOUNTS *(f32)(Local_f32Counter-Global_U8Counter));
		Global_U8Preload=T_OVCOUNTS -Local_U8Counts;
		Timer0_VidPreload(Global_U8Preload);
	}

	//enable overflow interrupt
	SET_BIT(TIMSK,TOIE0);

}

void Timer0_VidCTCLimit(u8 Copy_U8Limit)
{
	OCR0=Copy_U8Limit;
}

void CTCTimer0_VidInit( u8 Copy_U8Prescaller,u8 Copy_U8DesireTime)
{
	f32 Local_f32CTCTime=TOV;
	u8 Local_U8Limit;
	Timer0_VidInit(CTC);

	Timer0_VidPrescaller( Copy_U8Prescaller);

	if(Copy_U8Prescaller==PS_8){
		Local_f32CTCTime*=8;
	}
	else if(Copy_U8Prescaller==PS_64){
		Local_f32CTCTime*=64;
	}
	else if(Copy_U8Prescaller==PS_256){
		Local_f32CTCTime*=256;
	}
	else if(Copy_U8Prescaller==PS_1024){
		Local_f32CTCTime*=1024;
	}

	if(Copy_U8DesireTime< Local_f32CTCTime ){
		Local_U8Limit=(Copy_U8DesireTime*255)/Local_f32CTCTime;

	}
	Timer0_VidCTCLimit(Local_f32CTCTime);
	SET_BIT(TIMSK,OCIE0);
}



void Duty_Cycle_PWM( u8 Copy_U8Value)
{


#if TIMER_OC0STATE==OC_CLEARTOP
	OCR0=T_OVCOUNTS *(Copy_U8Value/100);
#elif TIMER_OC0STATE==OC_SETTOP
	OCR0=T_OVCOUNTS-(T_OVCOUNTS *(Copy_U8Value/100));
#endif


}


void Duty_Cycle_PHCO( u8 Copy_U8Value)
{


#if TIMER_OC0STATE==OC_CLEARTOP
	OCR0=T_PHASECORRECT_COUNTS *(Copy_U8Value/2*100);
#elif TIMER_OC0STATE==OC_SETTOP
	OCR0=(T_PHASECORRECT_COUNTS/2)-(T_PHASECORRECT_COUNTS *(Copy_U8Value/2*100));
#endif


}


/*
 * Timer0_PWMFreqs=F_CPU/(256*PRE_Factor)		EX:	PRE_1=31250 HZ 		,PRE_8=3906.25
 * */
void PWMTimer0_VidInit(u8 Copy_U8Prescaller ,u8 Copy_U8percent)
{
	Timer0_VidInit(FAST_PWM);
	Timer0_VidPrescaller(Copy_U8Prescaller);
	Duty_Cycle_PWM( Copy_U8percent);

}

void Phase_CorrectTimer0_VidInit(u8 Copy_U8Prescaller ,u8 Copy_U8percent)
{
	Timer0_VidInit(PWM_PHASE_CORRECT);
	Timer0_VidPrescaller(Copy_U8Prescaller);
	Duty_Cycle_PHCO( Copy_U8percent/2);

}


void OV_VidCallback(void (*Copy_PVidCallback)(void*),void * Copy_VoidPtr)
{
	 TIMER0_PVidCallback[0]=Copy_PVidCallback;
	 TIMER0_Gptr[0]=Copy_VoidPtr;
}

void CTC_VidCallback(void (*Copy_PVidCallback)(void*),void * Copy_VoidPtr)
{
	 TIMER0_PVidCallback[1]=Copy_PVidCallback;
		 TIMER0_Gptr[1]=Copy_VoidPtr;
}

//			TIMER 0 CTC MODE
void __vector_10(void)
{/*
	static u8 counter=0;
	if (counter==30)
	{	DIO_VidTogglePinValue(PortA,0);
	counter=0;
	Timer0_VidPreload(60);
	}
	else
	{
		counter++;

	}*/
	TIMER0_PVidCallback[1](TIMER0_Gptr[1]);
 }

//			TIMER 0 OVERFLOW MODE
void __vector_11(void)
{
	static u8 counter=0;
if (counter==Global_U8Counter)
{	TIMER0_PVidCallback[0](TIMER0_Gptr[0]);
counter=0;
Timer0_VidPreload(Global_U8Preload);
}
else
{
	counter++;

}
}


