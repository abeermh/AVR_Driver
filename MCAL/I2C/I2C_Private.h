/*
 * I2C_Private.h
 *
 *  Created on: Nov 16, 2020
 *      Author: Abeer
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_

#define WRITE 		0
#define READ 		1
#define F_CPU 	8000000
#define ACK		6
#define TWGCE	0
#define TWINT 	7
#define TWSTA 	5
#define TWEN 	2
#define TWSTO	4

#define START				0x08
#define PSC_STATUS 			0XF8
#define REPATED_START		0x10
#define TRANS_ACK			0x18
#define REC_ACK				0x40
#define MASTER_TRANS		0x28
#define MASTER_REC			0x50
#define SLAVE_TRANS			0xC8
#define SLAVE_REC			0x80
#define RSLAVE_ADD			0x60
#define TSLAVE_ADD			0XA8
typedef enum{
	PR_1,
	PR_4,
	PR_16,
	PR_64
}I2C_PRE;

u8 Power(int base, int exp);
#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
