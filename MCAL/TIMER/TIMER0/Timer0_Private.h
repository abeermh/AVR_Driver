/*
 * Timer_Private.h
 *
 *  Created on: Nov 4, 2020
 *      Author: Abeer
 */

#ifndef TIMER_TIMER0_PRIVATE_H_
#define TIMER_TIMER0_PRIVATE_H_

#define OVER_FLOW 				0
#define CTC		  				1
#define FAST_PWM 			    2
#define PWM_PHASE_CORRECT		3

// 		OC PIN MODE FOR  TIMERS
#define OC_DISCONNECT 	0
#define OC_TOGGLE 		1
#define OC_CLEARTOP 	2
#define OC_SETTOP 		3
#define TOV				0.000032

#define T_OVCOUNTS 				256
#define T_PHASECORRECT_COUNTS		510

#define WGM00	6
#define WGM01	3
#define	COM00	4
#define cs00	0

#define	NO_PS 	0
#define PS_1 	1
#define PS_8 	2
#define PS_64 	3
#define PS_256 	4
#define PS_1024 	5
#define PS_EXFALLING 	6
#define PS_EXRISING 	7


#define TOIE0		0
#define OCIE0		1

#define T2_OVERFLOW_INTERRUPT_BIT		6
#define T2_CTC_INTERRUPT_BIT		7
void __vector_11()__attribute__((signal));
void __vector_10()__attribute__((signal));
#endif /* TIMER_TIMER0_PRIVATE_H_ */
