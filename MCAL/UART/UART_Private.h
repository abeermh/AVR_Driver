/*
 * UART_Private.h
 *
 *  Created on: Nov 12, 2020
 *      Author: Abeer
 */

#ifndef UART_UART_PRIVATE_H_
#define UART_UART_PRIVATE_H_

#define F_CPU 	8000000

#define EN 			1
#define DISABLE		0

//					UCSRA BITS
#define RXC 		7
#define TXC			6
#define UDRE		5
#define U2X			1

//					UCSRB BITS
#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0

//					UCSRC BITS
#define URSEL		7
#define UMSEL		6
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0

#define EV_PARITY			2
#define OD_PARITY			3

#define ASYNC 		0
#define SYNC		1

#define ONE_BIT 	0
#define TWO_BIT		1
#define SEL1BITS		1
#define SEL2BITS		3
#define RISTX_FALLRX	0
#define FALLTX_RISRX	1

#define CH_S_5BIT		0
#define CH_S_6BIT		1
#define CH_S_7BIT		2
#define CH_S_8BIT		3
#define CH_S_9BIT		7


typedef enum{
	ASYNC_NORM_BD,
	ASYNC_DOUBLE_BD,
	SYNC_MTR

}OP_MODE;

typedef enum{
	BR_2400 =2400,
	BR_4800=4800 ,
	BR_9600=9600 ,
	BR_14_4K=14400 ,
	BR_19_2K=19200 	,
	BR_28_8K=28800 	,
	BR_38_4k=38400	,
	BR_57_6K=47600	,
	BR_76_8K=76800	,
	BR_115_22K=155220 ,
	BR_230_4K=230400 	,
	BR_250K=250000	,
	BR_0_5M=500000
}BAUD;
#endif /* UART_UART_PRIVATE_H_ */
