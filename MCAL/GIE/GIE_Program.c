#include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include "GIE_private.h"
 void GIE_VidEnable(){

	SET_BIT(SRIG,GLOBALINT);
}
void GIE_VidDisable(){
	CLR_BIT(SRIG,GLOBALINT);
}
