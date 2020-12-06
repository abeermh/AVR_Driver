/*
 * Timer_Interface.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Abeer
 */

#ifndef TIMER_TIMER0_INTERFACE_H_
#define TIMER_TIMER0_INTERFACE_H_

void Timer0_Vidinit();
void Timer1_Vidinit();
void Timer2_Vidinit();

void OverFlowTimer0_VidInit( u8 Copy_U8Prescaller,u8 Copy_U8DesireTime_ms)void CTCTimer0_VidInit();

void PWMTimer0_VidInit(u8 Copy_U8Prescaller ,u8 Copy_U8percent)

void Phase_CorrectTimer0_VidInit(u8 Copy_U8Prescaller ,u8 Copy_U8percent)

void Timer0_VidPreload(u8 Copy_U8PreloadValue);

void CTCTimer0_VidInit( u8 Copy_U8Prescaller,u8 Copy_U8DesireTime);
void Timer0_VidCTCLimit(u8 Copy_U8Limit);

void Timer_VidPrescaller(u8 Copy_U8Timer);

void Duty_Cycle_PWM( u8 Copy_U8Value);
void Duty_Cycle_PHCO( u8 Copy_U8Value);

void OV_VidCallback(void (*Copy_PVidCallback)(void*),void * Copy_VoidPtr);
void CTC_VidCallback(void (*Copy_PVidCallback)(void*),void * Copy_VoidPtr);

#define	NO_PS 	0
#define PS_1 	1
#define PS_8 	2
#define PS_64 	3
#define PS_256 	4
#define PS_1024 	5
#define PS_EXFALLING 	6
#define PS_EXRISING 	7
#endif /* TIMER_TIMER0_INTERFACE_H_ */
