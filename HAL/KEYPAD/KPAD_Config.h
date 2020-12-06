/*
 * KPAD_Config.h
 *
 *  Created on: Oct 22, 2020
 *      Author: Abeer
 */

#ifndef KPAD_CONFIG_H_
#define KPAD_CONFIG_H_

#define Key_Port PortB

#define c1		4
#define c2		5
#define c3		6
#define c4		7

#define r1		3
#define r2		2
#define r3		1
#define r4		0

#define KPAD_Vals	{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
//#define KEY_BOARD	{{1,2,3,4},{5,6,7,8},{9,0,'+','-'},{'*','/','=','>'}}
#define KEY_BOARD	{{'9','8','7','/'},{'6','5','4','*'},{'3','2','1','-'},{'1','0','=','+'}}

#endif /* KPAD_CONFIG_H_ */
