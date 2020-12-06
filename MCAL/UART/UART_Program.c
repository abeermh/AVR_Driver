#include"../../lib/STD_Types.h"
#include"../../lib/BIT_MATH.h"
#include"../../lib/AVR32_REG.h"
#include "UART_Config.h"
#include "UART_Private.h"
 void UART_VidInit(OP_MODE Copy_mode,BAUD Copy_BaudRate)
{
	u8 EMP_Reg;
	u16 Local_UBRR;
	if(Copy_mode==ASYNC_NORM_BD){
		Local_UBRR=(F_CPU/(16*Copy_BaudRate))-1;
	}
	else if(Copy_mode==ASYNC_NORM_BD){
		Local_UBRR=(F_CPU/(8*Copy_BaudRate))-1;
	}
	else if(Copy_mode==SYNC_MTR){
		Local_UBRR=(F_CPU/(2*Copy_BaudRate))-1;
	}



	/* Set baud rate first 8 bits in UBRRL & the last 4 bits in UBRRH*/
	UBRRH = Local_UBRR>>8;
	UBRRL = Local_UBRR;


	/* Enable receiver and transmitter and set char size*/
	//UCSRB = (EN<<RXEN)|(EN<<TXEN)|((CHAR_SiZE>>2)<<UCSZ2);
#if RXC_INT==EN
	SET_BIT(UCSRB,RXCIE);
#elif RXC_INT==DISABLE
	CLR_BIT(UCSRB,RXCIE);
#endif
#if TXC_INT==EN
	SET_BIT(UCSRB,TXCIE);
#elif TXC_INT==DISABLE
	CLR_BIT(UCSRB,TXCIE);
#endif
#if R_EN==EN
	SET_BIT(UCSRB,RXEN);
#elif R_EN==DISABLE
	CLR_BIT(UCSRB,RXEN);
#endif
#if T_EN==EN
	SET_BIT(UCSRB,TXEN);
#elif T_EN==DISABLE
	CLR_BIT(UCSRB,TXEN);
#endif
	UCSRB|=((CHAR_SiZE>>2)<<UCSZ2);

	/* Set frame format: 8data, 1stop bit,char size */
	//	TO WRITE ON  UCSRC
	SET_BIT(EMP_Reg,URSEL);
	//select mode
#if MODE_SEL==SYNC
	SET_BIT(EMP_Reg,UMSEL);
#if CLOCK_POL==RISTX_FALLRX
	CLR_BIT(EMP_Reg,UCPOL);
#elif CLOCK_POL==FALLTX_RISRX
	SET_BIT(EMP_Reg,UCPOL);
#endif
#elif MODE_SEL==ASYNC
	CLR_BIT(EMP_Reg,UMSEL);
#endif
	// SET PARITY MODE
	EMP_Reg|=(PARITY_MODE<<UPM0);
#if STOP_BIT==TWO_BIT
	SET_BIT(EMP_Reg,USBS);
#elif STOP_BIT==ONE_BIT
	CLR_BIT(EMP_Reg,USBS);
#endif
	EMP_Reg|=((CHAR_SiZE&SEL2BITS)<<UCSZ0);
	UCSRC=EMP_Reg;
	//UCSRC = (1<<REG_SEL_BIT)|((CHAR_SiZE&3)<<UCSZ0);
}



void UART_VidSend(u16 Copy_U8Data)
{
#if CHAR_SiZE==CH_S_9BIT
	UCSRB|=(((Copy_U8Data>>8)&1)<<TXB8);
#endif
	while(!GET_BIT(UCSRA,UDRE));
	UDR=Copy_U8Data;
}
u16 UART_VidReceive()
{	u16 Local_U8Value=0;
#if CHAR_SiZE==CH_S_9BIT
Local_U8Value|=(GET_BIT(UCSRB,RXB8)<<8);
#endif
while(!GET_BIT(UCSRA,RXC));
Local_U8Value|=UDR;
return Local_U8Value;
}
