/*	auther: Abeer Mohamed Hassan */
/*	Date : 19/10/2020 */
/*	Version : V1 */
/*	Description : */
#include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include "DIO_Private.h"


void DIO_VidSetPinDirection(u8 Copy_U8port,u8 Copy_U8Pin,u8 Copy_U8Direction)
{
	/*check if dir is output*/
	if(Output == Copy_U8Direction)
	{
		switch(Copy_U8port)
		{
		case PortA :	SET_BIT(DDRA,Copy_U8Pin);	break;
		case PortB :	SET_BIT(DDRB,Copy_U8Pin);	break;
		case PortC :	SET_BIT(DDRC,Copy_U8Pin);	break;
		case PortD :	SET_BIT(DDRD,Copy_U8Pin);	break;
		default:									break;
		}
	}
	else if(Input == Copy_U8Direction)	/*check if dir is input*/
	{
		switch(Copy_U8port)
		{
		case PortA :	CLR_BIT(DDRA,Copy_U8Pin);	 break;
		case PortB :	CLR_BIT(DDRB,Copy_U8Pin);	 break;
		case PortC :	CLR_BIT(DDRC,Copy_U8Pin);	 break;
		case PortD :	CLR_BIT(DDRD,Copy_U8Pin);    break;
		default:									 break;
		}
	}
	else
	{
	}
 }


void DIO_VidSetPinValue(u8 Copy_U8port,u8 Copy_U8Pin,u8 Copy_U8Value)
{

	if(High== Copy_U8Value)
	{
		switch(Copy_U8port)
		{
		case PortA :	SET_BIT(PORTA,Copy_U8Pin);	break;
		case PortB :	SET_BIT(PORTB,Copy_U8Pin);	break;
		case PortC :	SET_BIT(PORTC,Copy_U8Pin);	break;
		case PortD :	SET_BIT(PORTD,Copy_U8Pin);	break;
		default:									break;
		}
	}
	else if(Low == Copy_U8Value)
	{
		switch(Copy_U8port)
		{
		case PortA :	CLR_BIT(PORTA,Copy_U8Pin);	 break;
		case PortB :	CLR_BIT(PORTB,Copy_U8Pin);	 break;
		case PortC :	CLR_BIT(PORTC,Copy_U8Pin);	 break;
		case PortD :	CLR_BIT(PORTD,Copy_U8Pin);   break;
		default:									 break;
		}
	}
	else
	{
	}
}


void DIO_VidSetPortDirection(u8 Copy_U8port,u8 Copy_U8Direction)
{

	switch(Copy_U8port)
	{
	case PortA :	DDRA=Copy_U8Direction;	break;
	case PortB :	DDRB=Copy_U8Direction;	break;
	case PortC :	DDRC=Copy_U8Direction;	break;
	case PortD :	DDRD=Copy_U8Direction;	break;
	default:								break;
	}


}


void DIO_VidSetPortValue(u8 Copy_U8port,u8 Copy_U8Value)
{
	switch(Copy_U8port)
	{
	case PortA :	PORTA=Copy_U8Value;	break;
	case PortB :	PORTB=Copy_U8Value;	break;
	case PortC :	PORTC=Copy_U8Value;	break;
	case PortD :	PORTD=Copy_U8Value;	break;
	default:							break;
	}
}


u8 DIO_U8GetPinValue(u8 Copy_U8port,u8 Copy_U8Pin)
{	u8 Local_U8PinValue;
switch(Copy_U8port)
{
case PortA :	Local_U8PinValue=GET_BIT(PINA,Copy_U8Pin);	 break;
case PortB :	Local_U8PinValue=GET_BIT(PINB,Copy_U8Pin);	 break;
case PortC :	Local_U8PinValue=GET_BIT(PINC,Copy_U8Pin);	 break;
case PortD: 	Local_U8PinValue=GET_BIT(PIND,Copy_U8Pin);	 break;
default:													 break;

}
return Local_U8PinValue;
}



void DIO_VidTogglePin(u8 Copy_U8port,u8 Copy_U8Pin)
{
	switch(Copy_U8port)
	{
	case PortA :	TOGGLE_BIT(DDRA,Copy_U8Pin);	break;
	case PortB :	TOGGLE_BIT(DDRB,Copy_U8Pin);	break;
	case PortC :	TOGGLE_BIT(DDRC,Copy_U8Pin);	break;
	case PortD :	TOGGLE_BIT(DDRD,Copy_U8Pin);	break;
	default:										break;
	}
}



void DIO_VidTogglePinValue(u8 Copy_U8port,u8 Copy_U8Pin)
{
	switch(Copy_U8port)
	{
	case PortA :	TOGGLE_BIT(PORTA,Copy_U8Pin);	break;
	case PortB :	TOGGLE_BIT(PORTB,Copy_U8Pin);	break;
	case PortC :	TOGGLE_BIT(PORTC,Copy_U8Pin);	break;
	case PortD :	TOGGLE_BIT(PORTD,Copy_U8Pin);	break;
	default:										break;
	}
}
