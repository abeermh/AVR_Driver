#ifndef _EX_INTERFACE_H
#define _EX_INTERFACE_H


typedef enum{
	ONCHANGE,
	LOWLEVEL,
	FALLING,
     RISING
}SenseControl ;

typedef enum{

	Falling,
     Rising
}Int2_SenseControl ;


void ExIt_VidInit0(SenseControl Copy_SenseControl);
void ExIt_VidInit1(SenseControl Copy_SenseControl);
void ExIt_VidInit2(Int2_SenseControl Copy_SenseControl);

void ExIt_VidEnable();
void ExIt_VidDisable();


//void EXIT_VidCallback(void (*Copy_PVidCallback)(void));


void EXIT_VidCallback(void (*Copy_PVidCallback)(void),void * Copy_VoidPtr);







#endif
