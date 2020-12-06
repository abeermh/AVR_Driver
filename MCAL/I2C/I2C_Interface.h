/*
 * I2C_Interface.h
 *
 *  Created on: Nov 16, 2020
 *      Author: Abeer
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

typedef enum{
	PRE_1,
	PRE_4,
	PRE_16,
	PRE_64
}I2C_PRE;


void I2C_InitMaster(u16 Copy_U8Freq,I2C_PRE Copy_U8Prescaller,u8 Copy_U8Address);
void I2C_InitSlave(u8 Copy_U8Address);
void I2C_Start();
u8 I2C_RepeatedStart();
u8 I2C_SendAddress(u8 Copy_U8Addresss,u8 Copy_U8RW);
u8 I2C_U8SlaveCheckAddress();
u8 I2C_U8MasterSend(u8 Copy_U8Data);
u8 I2C_U8SlaveReceive(u8 *Copy_U8Data);
u8 I2C_U8SlaveSend(u8 Copy_U8Data);
u8 I2C_U8MasterReceive(u8 *Copy_U8Data);
void I2C_VidStop();

#define WRITE 		0
#define READ 		1
#define PRESCALLER_1	0
#define PRESCALLER_4	1
#define PRESCALLER_16	2
#define PRESCALLER_64	3
#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
