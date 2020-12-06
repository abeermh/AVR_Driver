#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_



/*typedef enum DIO
{
	DIO_PIN0,	DIO_PIN1,	DIO_PIN2,	DIO_PIN3,
	DIO_PIN4,	DIO_PIN5,	DIO_PIN6,	DIO_PIN7,
	DIO_PIN8,	DIO_PIN9,	DIO_PIN10,	DIO_PIN11,
	DIO_PIN12,	DIO_PIN13,	DIO_PIN14,	DIO_PIN15,
	DIO_PIN16,	DIO_PIN17,	DIO_PIN18,	DIO_PIN19,
	DIO_PIN20,	DIO_PIN21,	DIO_PIN22,	DIO_PIN23,
	DIO_PIN24,	DIO_PIN25,	DIO_PIN26,	DIO_PIN27,
	DIO_PIN28,	DIO_PIN29,	DIO_PIN30,	DIO_PIN31

} ;
*/

#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3

#define High 	1

#define Low		0

#define Output  1

#define Input   0






#define PORTA_DIRECTION		CONC_DDR_HELP2(DIO_PIN0)








#endif
