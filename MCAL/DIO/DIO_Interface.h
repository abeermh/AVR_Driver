#ifndef _DIO_INTEERFACE_H_
#define	_DIO_INTEERFACE_H_

void DIO_VidSetPortDirection(u8 Copy_U8port,u8 Copy_U8Direction);

void DIO_VidSetPinDirection(u8 Copy_U8port,u8 Copy_U8Pin,u8 Copy_U8Direction);

void DIO_VidSetPinValue(u8 Copy_U8port,u8 Copy_U8Pin,u8 Copy_U8Value);

void DIO_VidSetPortValue(u8 Copy_U8port,u8 Copy_U8Value);

void DIO_VidTogglePin(u8 Copy_U8port,u8 Copy_U8Pin);

void DIO_VidTogglePinValue(u8 Copy_U8port,u8 Copy_U8Pin);

u8 DIO_U8GetPinValue(u8 Copy_U8port,u8 Copy_U8Pin);

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define DIO_Pin0 0
#define DIO_Pin1 1
#define DIO_Pin2 2
#define DIO_Pin3 3
#define DIO_Pin4 4
#define DIO_Pin5 5
#define DIO_Pin6 6
#define DIO_Pin7 7

#define High 	1

#define Low		0

#define Output  1

#define Input   0

#endif
