/*
 * main.c
 *
 *  Created on: Oct 22, 2020
 *      Author: Abeer
 */

#include"../lib/STD_Types.h"
#include "../lib/BIT_MATH.h"
#include "../lib/AVR32_REG.h"
#include<util/delay.h>
#include"../MCAL/DIO/DIO_Interface.h"

#define DrawMan 0
#define KeyPad  1
#define LightLed  2
#define DcMotorPlay  3
#define Adc  4
#define TimerOverflow  5
#define TimerCtc  6
#define TimerPwm  7
#define Piano  8
 #define Uart	9
#define SPI_Master	10
#define SPI_Slave  11
#define led_brightness 12

#define FUNC_TO_EXEC	DrawMan

#if FUNC_TO_EXEC==DrawMan
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/KEYPAD/KPAD_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
void main() {
	LCD_VidInit();
	KPAD_VidInit();
	u8 drawman[] = DRAWMAN;
	LCD_VidDraw(drawman, 4);
	LCD_VidMovingDraw(drawman, 4);
	while (1) {
	}
}
#elif FUNC_TO_EXEC==KeyPad
 #include"HAL/KEYPAD/KPAD_Interface.h"
#include "HAL/LCD/Lcd_Interface.h"

void main() {

	u8 keyval;
	LCD_VidInit();
	KPAD_VidInit();
	while (1) {
		keyval = KPAD_U8GetKey();
		if (keyval != KEY_NOT_PRESSED) {
			LCD_VidPrintIntNumber(keyval);
		}

	}
}
#elif FUNC_TO_EXEC==LightLed
 #include "../MCAL/Extern//Ex_It_interface.h"
#include"../MCAL/GIE/GIE_interface.h"

void callbackfunc() {
	DIO_VidSetPinValue(PortA, 0, 1);
}

void main() {
	//LED  light with interrupt from push button

	DIO_VidSetPinDirection(PortA, 0, Output);
	DIO_VidSetPinDirection(PortD, 0, Input);
	DIO_VidSetPinValue(PortD, 0, 1);
	ExIt_VidInit0();
	ExIt_VidEnable();
	EXIT_VidCallback(&callbackfunc);
	GIE_VidEnable();
}

#elif FUNC_TO_EXEC==DcMotorPlay

void main() {
	DIO_VidSetPinDirection(PortA, DIO_Pin0, Output);
	while (1) {
		DIO_VidTogglePinValue(PortA, DIO_Pin0);
		_delay_ms(1000);
	}
}
#elif FUNC_TO_EXEC==Adc
#include "../MCAL/ADC/ADC_Interface.h"

 void main()
 {
 DIO_VidSetPinDirection(PortA,1,1);
 ADC_VidInit();
 ADC_VidSelectChannel(0);
 ADC_VidEnable();
 u16 DigitalValue;
 u16 AnalogValue;
 while(1){
 ADC_VidStartConversion();
 DigitalValue=ADC_VidRead();
 AnalogValue=((DigitalValue)*5000UL)/1024;
 if(AnalogValue>=2000 && AnalogValue<3000 )
 {
 DIO_VidSetPinValue(PortA,1,1);
 _delay_ms(10);
 }else{DIO_VidSetPinValue(PortA,1,0);
 _delay_ms(10);}
 }

 }

#elif FUNC_TO_EXEC==TimerOverflow
#include"../MCAL/TIMER/TIMER0/Timer0_Interface.h"

void main() {
	DIO_VidSetPinDirection(PortA, 0, 1);
	OverFlowTimer0_VidInit(PS_256,2000);
	GIE_VidEnable();
	while (1) {
	}

}
#elif FUNC_TO_EXEC==TimerCtc
#include"../MCAL/TIMER/TIMER0/Timer0_Interface.h"

void main() {
	DIO_VidSetPinDirection(PortA, 0, 1);
	CTCTimer0_VidInit(PS_256,4000);
	GIE_VidEnable();
	while (1) {
	}

}
#elif FUNC_TO_EXEC==TimerPwm
#include"../MCAL/TIMER/TIMER0/Timer0_Interface.h"

void main() {
	u8 max = 100;
	DIO_VidSetPinDirection(PortB, 3, 1);
	PWMTimer0_VidInit(PS_256,max);
	Duty_Cycle_PWM( max);

	while (max >= 0) {

		max /= 2;
		Duty_Cycle_PWM( max);
		_delay_ms(1000);
	}
}
#elif FUNC_TO_EXEC==Piano
#include"../HAL/KEYPAD/KPAD_Interface.h"
#include"../MCAL/TIMER/TIMER0/Timer0_Interface.h"


void main() {
	PWMTimer0_VidInit(PS_256,100);
	KPAD_VidInit();
	while (1) {
		switch (KPAD_U8GetKey()) {
		case 1:
			Duty_Cycle( 100);
			break;
		case 2:
			Duty_Cycle( 75);
			break;
		case 3:
			Duty_Cycle( 50);
			break;
		case 4:
			Duty_Cycle( 25);
			break;
		default:
			Duty_Cycle( 0);
		}
	}
}
#elif FUNC_TO_EXEC==led_brightness
#include"../MCAL/TIMER/TIMER0/Timer0_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"

void main() {
	DIO_VidSetPinDirection(PortB, 3, 1);
	PWMTimer0_VidInit(PS_256,100);
	ADC_VidInit();
	ADC_VidSelectChannel(0);
	ADC_VidEnable();
	u16 DigitalValue;
	u16 AnalogValue;
	while (1) {
		ADC_VidStartConversion();
		DigitalValue = ADC_VidRead();
		AnalogValue = ((DigitalValue) * 5000UL) / 1024;
		Duty_Cycle(0, DigitalValue);

	}
}

#elif FUNC_TO_EXEC==Uart

#include "../MCAL/UART/UART_Intereface.h"
void main() {
	u8 x = 0;
	DIO_VidSetPortDirection(PORTD, 0x02);
	UART_VidInit();
	while (1) {
		x = UART_VidReceive();
		if (x != 13) {	//ASCI for enter press
			UART_VidSend(x);
		}
	}
}
#elif FUNC_TO_EXEC==SPI_Master
#include"../MCAL/SPI/SPI_Interface.h"

void main() {
	SPI_VidInitMaster(F128);
	DIO_VidSetPinValue(1, 4, 0);	//select slave
	SPI_VidSend('A');
	while (1) {

	}
}
#elif FUNC_TO_EXEC==SPI_Slave
#include"../MCAL/SPI/SPI_Interface.h"

void main() {
	DIO_VidSetPinDirection(1, 0, 1);
	SPI_VidInitSlave(F128);
	u8 t = SPI_VidReceive();
	LCD_VidInit();
	if (t == 'A') {
		DIO_VidSetPinValue(1, 0, 1);
 	} else {
		DIO_VidSetPinValue(1, 0, 0);
	}
	while (1)
		;
}
#endif
