/*
 * ADC_Program.c
 *
 *  Created on: Nov 3, 2020
 *      Author: Abeer
 */
#include "../../lib/STD_TYPES.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include"../DIO/DIO_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
void ADC_VidInit()
{
#if ADC_PRESCALER == PRESCALER_2
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_8
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_16
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#elif ADC_PRESCALER == PRESCALER_128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#endif

	//Reference Selection
#if ADC_REF == AREF
	CLR_BIT(ADMUX,7);
	CLR_BIT(ADMUX,6);
#elif ADC_REF == AVCC
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#elif ADC_REF == INTERNAL2_5V
	SET_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
#endif

}

void ADC_VidEnable()
{
	SET_BIT(ADCSRA,ADC_Enable);
}

void ADC_VidDisable()
{
	CLR_BIT(ADCSRA,ADC_Enable);
}

void ADC_VidSelectChannel(u8 Copy_U8Channel)
{
	ADMUX&=0XE0;
	ADMUX|=Copy_U8Channel;

}

void ADC_VidStartConversion()
{
	SET_BIT(ADCSRA,Start_Conversion);
}

void ADC_VidEnableAutoTriggerMode(u8 Copy_U8Mode)
{
	switch(Copy_U8Mode){
	case 0: //free running mode
			CLR_BIT(SFIOR,5);
			CLR_BIT(SFIOR,6);
			CLR_BIT(SFIOR,7);
			break;
	case 1://Analog Comparator
	        SET_BIT(SFIOR,5);
	        CLR_BIT(SFIOR,6);
	        CLR_BIT(SFIOR,7);
	        break;
	case 2://External Interrupt Request 0
			CLR_BIT(SFIOR,5);
			SET_BIT(SFIOR,6);
			CLR_BIT(SFIOR,7);
			break;
	case 3://Timer/Counter0 Compare Match
			SET_BIT(SFIOR,5);
			SET_BIT(SFIOR,6);
			CLR_BIT(SFIOR,7);
			break;
	case 4://Timer/Counter0 Overflow
			CLR_BIT(SFIOR,5);
			CLR_BIT(SFIOR,6);
			SET_BIT(SFIOR,7);
			break;
	case 5://Timer/Counter1 Compare Match B
			SET_BIT(SFIOR,5);
			CLR_BIT(SFIOR,6);
			SET_BIT(SFIOR,7);
			break;
	case 6://Timer/Counter1 Overflow
			CLR_BIT(SFIOR,5);
			SET_BIT(SFIOR,6);
			SET_BIT(SFIOR,7);
			break;
	case 7://Timer/Counter1 Capture Event
			SET_BIT(SFIOR,5);
			SET_BIT(SFIOR,6);
			SET_BIT(SFIOR,7);
			break;
}
}

void ADC_VidEnableInterrupt()
{
	SET_BIT(ADCSRA,ADC_InterruptEnable);
}

void ADC_VidDisableInterrupt()
{
	CLR_BIT(ADCSRA,ADC_InterruptEnable);
}



u16 ADC_VidRead()
{
	while(!GET_BIT( ADCSRA,ADC_InterruptFlag));
	SET_BIT(ADCSRA,ADC_InterruptEnable);		//to clear the flag set it to one
	u16 Copy_PU16ADC_Value = ADC;
 	 return Copy_PU16ADC_Value;
}
