/*
 * AVR32_REG.h
 *
 *  Created on: Nov 2, 2020
 *      Author: Abeer
 */

#ifndef LIB_AVR32_REG_H_
#define LIB_AVR32_REG_H_

#define DDRA 	*((u8*)0X3A)
#define DDRB 	*((u8*)0X37)
#define DDRC 	*((u8*)0X34)
#define DDRD 	*((u8*)0X31)



#define PORTA 	*((u8*)0X3B)
#define PORTB 	*((u8*)0X38)
#define PORTC 	*((u8*)0X35)
#define PORTD 	*((u8*)0X32)



#define PINA 	*((volatile u8*)0X39)
#define PINB 	*((volatile u8*)0X36)
#define PINC 	*((volatile u8*)0X33)
#define PIND 	*((volatile u8*)0X30)


//for EXTERNAL INTERRUPT
#define MCUCR  *((u8*)0X55)
#define GICR   *((u8*)0X5B)
#define MCUCSR *((u8*)0X54)
#define EXPORTA 	*((u8*)0X3B)


//for GIE
#define SRIG  *((u8*)0X5F)


//for ADC
#define ADMUX  	 *((volatile u8*)0x27)
#define ADCSRA	 *((volatile u8*)0x26)
#define ADCH 	 *((volatile u8*)0x25)
#define ADCL 	 *((volatile u8*)0x24)
#define  ADC	 *((volatile u16*)0x24)
#define SFIOR 	 *((volatile u8*)0x50)

//for timer 0
#define TCCR0 	*((volatile u8*)0x53)
#define TIMSK	*((volatile u8*)0x59)
#define TCNTO	*((volatile u8*)0x52)
#define TIFR    *((volatile u8*)0x58)
#define OCR0 	*((volatile u8*)0x5C)

//for timer 1
#define TCCR1A *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define ICR *((volatile u16 *)0x46)
#define OCR *((volatile u16 *)0x4A)

//for timer 2
#define TCCR2 	*((volatile u8*)0x45)
#define OCR2 	*((volatile u8*)0x43)
#define TCNT2	*((volatile u8*)0x44)

//for UART
#define UDR		*((volatile u8*)0x2C)
#define UBRRL   *((volatile u8*)0x29)
#define UBRRH	*((volatile u8*)0x40)
#define UCSRC	*((volatile u8*)0x40)
#define UCSRB	*((volatile u8*)0x2A)
#define UCSRA   *((volatile u8*)0x2B)

//for SPI
#define SPDR    *((volatile u8*) 0x2F)
#define SPSR    *((volatile u8*) 0x2E)
#define SPCR    *((volatile u8*) 0x2D)

//for I2C
#define TWDR *((volatile u8*)0x23)
#define TWAR *((volatile u8*)0x22)
#define TWSR *((volatile u8*)0x21)
#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#endif /* LIB_AVR32_REG_H_ */
