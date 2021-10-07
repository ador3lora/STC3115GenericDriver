/**
 * *****************************************************************************
 * @file	stc3115_I2C.h
 *
 * *****************************************************************************
 */

/* Define to prevent recursive inclusion */
#ifndef __STC3115_I2C_H
#define __STC3115_I2C_H

#define STC3115_SLAVE_ADDRESS_7BIT			0x70
#define STC3115_SLAVE_ADDRESS_8BIT_WRITE	0xE0
#define STC3115_SLAVE_ADDRESS_8BIT_READ		0xE1

int I2C_Write(int NumberOfBytes, int RegAddress, unsigned char *TxBuffer);
int I2C_Read(int NumberOfBytes, int RegAddress, unsigned char *RxBuffer);

#endif	/* __STC3115_I2C_H */
