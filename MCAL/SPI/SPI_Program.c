/*
 * SPI_Program.c
 *
 *  Created on: Nov 15, 2020
 *      Author: Abeer Mohamed Hassan
 */
#include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include"../DIO/DIO_Interface.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Config.h"
 void SPI_VidInitMaster(ClkRate Copy_U8ClkRate )
{
	DIO_VidSetPinDirection(PortB,SS,Output);
	DIO_VidSetPinDirection(PortB,MOSI,Output);
	DIO_VidSetPinDirection(PortB,MISO,Input);
	DIO_VidSetPinDirection(PortB,SCK,Input);

	SPCR=(1<<SPE)|(1<<DORD)|(1<<MSTR);
#if CLOCK_POL==LEADING_RIS
		CLR_BIT(SPCR,CPOL);
#elif CLOCK_POL==LEADING_RIS
		SET_BIT(SPCR,CPOL);
#endif
#if CLOCK_PHA==LEADING_SAMPLE
		CLR_BIT(SPCR,CPH);
#elif CLOCK_PHA==LEADING_SETUP
		SET_BIT(SPCR,CPH);
#endif
	if(Copy_U8ClkRate<DOUBLE_F2){
		SPCR|=Copy_U8ClkRate;
	}else{
		SPCR|=(Copy_U8ClkRate-DOUBLE_F2);
		SET_BIT(SPSR,SPI2X);
	}

}

void SPI_VidInitSlave(ClkRate Copy_U8ClkRate)
{
	DIO_VidSetPinDirection(PortB, SS ,Input);
	DIO_VidSetPinDirection(PortB, MOSI ,Input);
	DIO_VidSetPinDirection(PortB, MISO ,Output);
	DIO_VidSetPinDirection(PortB, SCK  ,Input);

	SPCR=(1<<SPE)|(1<<DORD);
	#if CLOCK_POL==LEADING_RIS
			CLR_BIT(SPCR,CPOL);
	#elif CLOCK_POL==LEADING_RIS
			SET_BIT(SPCR,CPOL);
	#endif
	#if CLOCK_PHA==LEADING_SAMPLE
			CLR_BIT(SPCR,CPH);
	#elif CLOCK_PHA==LEADING_SETUP
			SET_BIT(SPCR,CPH);
	#endif
		if(Copy_U8ClkRate<DOUBLE_F2){
			SPCR|=Copy_U8ClkRate;
		}else{
			SPCR|=(Copy_U8ClkRate-DOUBLE_F2);
			SET_BIT(SPSR,SPI2X);
		}

 }


u8 SPI_VidSend(u8 Copy_U8Data)
{
	SPDR=Copy_U8Data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;

}
u8 SPI_VidReceive()
{
	while(!GET_BIT(SPSR,SPIF));
    return SPDR;
}

