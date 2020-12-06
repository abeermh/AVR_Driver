/*
 * ADC_Interface.h
 *
 *  Created on: Nov 3, 2020
 *      Author: Abeer
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

void ADC_VidInit();

void ADC_VidEnable();

void ADC_VidDisable();

void ADC_VidSelectChannel(u8 Copy_U8Channel);

void ADC_VidStartConversion();

void ADC_VidEnableAutoTriggerMode(u8 Copy_U8Mode);

void ADC_VidEnableInterrupt();

void ADC_VidDisableInterrupt();

void ADC_VidPolling();

u16 ADC_VidRead();


#endif /* ADC_ADC_INTERFACE_H_ */
