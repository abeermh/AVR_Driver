#ifndef _EX_PRIVATE_H
#define _EX_PRIVATE_H


/*
#define FALLING 0
#define RISING 1
#define LOWLEVEL 2
#define ONCHANGE 3
*/
#define EX_INT0	6
#define EX_INT1	7
#define EX_INT2	5
#define ISC10	2
#define ISC2	6

typedef enum{
	ONCH ,
	LOW,
	FALLIN,
     RISIN
}SenseControl ;

typedef enum{

	FALL,
     RIS
}Int2_SenseControl ;

void __vector_1()__attribute__((signal));
//to prevent compiler from deleting it using attribute keyword and signal for using













#endif
