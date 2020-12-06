/*
 * SPI_Interface.h
 *
 *  Created on: Nov 15, 2020
 *      Author: Abeer
 */

#ifndef SPI_SPI_INTERFACE_H_
#define SPI_SPI_INTERFACE_H_
typedef enum {
	F4	,
	F16	,
	F64 ,
	F128 ,
	DOUBLE_F2 	,
	DOUBLE_F8	,
	DOUBLE_F32 ,
	DOUBLE_F64

}ClkRate;

void SPI_VidInitMaster(ClkRate Copy_U8ClkRate);
void SPI_VidInitSlave(ClkRate Copy_U8ClkRate);
u8 SPI_VidReceive();
u8 SPI_VidSend(u8 Copy_U8Data);


#endif /* SPI_SPI_INTERFACE_H_ */
