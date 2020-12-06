/*
 * I2C_Program.c
 *
 *  Created on: Nov 16, 2020
 *      Author: Abeer Mohamed Hassan
 */
 #include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include "I2C_Private.h"

u8 Power(int base, int exp)
{
    int result = 1;
    while(exp)
    {
        result = result * base;
        exp--;
    }
    return result;}

void I2C_InitMaster(u16 Copy_U8Freq,I2C_PRE Copy_U8Prescaller,u8 Copy_U8Address)
{

	TWBR= ((F_CPU/Copy_U8Freq)-16)/(2*Power(4,Copy_U8Prescaller));
 	//TWBR=0X02;
	SET_BIT(TWCR,ACK);
	TWSR|=Copy_U8Prescaller;
	TWAR=Copy_U8Address<<1;


}
void I2C_InitSlave(u8 Copy_U8Address)
{
	TWAR=Copy_U8Address<<1;


}


void I2C_VidEnableGeneralCall()
{
	SET_BIT(TWAR,TWGCE);
}

void I2C_VidDisableGeneralCall()
{
	CLR_BIT(TWAR,TWGCE);
}

u8 I2C_Start()
{
	TWCR|= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & PSC_STATUS) != START)
		return 0;
	return 1;
	}

u8 I2C_RepeatedStart()
{
	TWCR|= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	if ((TWSR & PSC_STATUS) != REPATED_START)
		return 0;
	return 1;
	}

u8 I2C_SendAddress(u8 Copy_U8Addresss,u8 Copy_U8RW){
	TWDR=(Copy_U8Addresss<<1)|Copy_U8RW;
	CLR_BIT(TWCR,5);//to clear start bit
	TWCR|=(1<<TWINT);//this start send address
	while (!(TWCR & (1<<7)));
	if(((TWSR&PSC_STATUS)==TRANS_ACK)||((TWSR&0xf8)==REC_ACK))
	{
		return 1;
	}
	return 0;
}

u8 I2C_U8MasterSend(u8 Copy_U8Data){

	TWDR=Copy_U8Data;
	TWCR|=(1<<TWINT);
	while (!(TWCR & (1<<TWINT)));
	if(((TWSR&PSC_STATUS)==MASTER_TRANS))
			{
				return 1;
			}
			return 0;
}
u8 I2C_U8SlaveReceive(u8 *Copy_U8Data){
	TWCR|=(1<<7)|(1<<TWEN)|(1<<ACK);
		while (!(TWCR & (1<<7)));
		if(((TWSR&0xf8)==SLAVE_REC))
				{
					*Copy_U8Data=TWDR;
					return 1;
				}
				return 0;
}
u8 I2C_U8SlaveSend(u8 Copy_U8Data){
	TWDR=Copy_U8Data;
		TWCR=(1<<7);
		while (!(TWCR & (1<<7)));
		if(((TWSR&0xf8)==SLAVE_TRANS))
				{
					return 1;
				}
				return 0;
}

u8 I2C_U8MasterReceive(u8 *Copy_U8Data){
	TWCR|=(1<<7);
		while (!(TWCR & (1<<7)));
		if(((TWSR&0xf8)==MASTER_REC))
				{
					*Copy_U8Data=TWDR;
					return 1;
				}
				return 0;
}



void I2C_VidStop(){
	TWCR|=(1<<TWINT)|(1<<TWSTO);
}



