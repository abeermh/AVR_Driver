/*
 * UART_Intereface.h
 *
 *  Created on: Nov 12, 2020
 *      Author: Abeer
 */

#ifndef UART_UART_INTEREFACE_H_
#define UART_UART_INTEREFACE_H_



typedef enum{
	ASYNC_NORM_BAUD,
	ASYNC_DOUBLE_BAUD,
	SYNC_MASTER

}OP_MODE;

typedef enum{
	BR0_2400 =2400,
	BR0_4800=4800 ,
	BR0_9600=9600 ,
	BR0_14_4K=14400 ,
	BR0_19_2K=19200 	,
	BR0_28_8K=28800 	,
	BR0_38_4k=38400	,
	BR0_57_6K=47600	,
	BR0_76_8K=76800	,
	BR0_115_22K=155220 ,
	BR0_230_4K=230400 	,
	BR0_250K=250000	,
	BR0_0_5M=500000
}BAUD;
void UART_VidInit(OP_MODE Copy_mode,BAUD Copy_BaudRate);
void UART_VidSend();
u16 UART_VidReceive();
#endif /* UART_UART_INTEREFACE_H_ */
