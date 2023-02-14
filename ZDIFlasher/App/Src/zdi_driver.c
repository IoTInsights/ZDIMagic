/*
 * zdi_driver.c
 *
 *  Created on: 03.02.2023
 *      Author: Bernd Wiegmann
 */

#include <memory.h>
#include <stdio.h>

#include "zdi_driver.h"
#include "zdi_timing.h"

// #define DEBUG_PIN

void zdi_driver_init()
{
	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ZDI_CLOCK_GPIO_Port, ZDI_CLOCK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ZDI_DATA_GPIO_Port, ZDI_DATA_Pin, GPIO_PIN_SET);
}

void zdi_driver_loop()
{
}

ZDIError zdi_driver_connect(ZDIHandle * pHandle)
{
	ZDIError rc = E_OK;

	uint8_t id_l = 0;
	uint8_t id_h = 0;
	uint8_t id_rev = 0;

	printf("Reading ID Register\n");

	rc = zdi_driver_read_register(pHandle, ZDI_ID_L, &id_l);

#if 0
	if (E_OK == rc) {
		rc = zdi_driver_read_register(pHandle, ZDI_ID_H, &id_h);
	}

	if (E_OK == rc) {
		rc = zdi_driver_read_register(pHandle, ZDI_ID_REV, &id_rev);
	}
#endif

	return rc;
}

ZDIError zdi_driver_reset_target(ZDIHandle * pHandle)
{
	ZDIError rc = E_OK;

	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_SET);

	return rc;
}

#define ZDI_CLOCK_HIGH			*bsrr = ZDI_CLOCK_Pin;
#define	ZDI_CLOCK_LOW			*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;

#define ZDI_DATA_HIGH			*bsrr = ZDI_DATA_Pin;
#define	ZDI_DATA_LOW			*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;

#define	ZDI_DATA_INPUT			*moder &= ~(GPIO_MODER_MODER1);
#define	ZDI_DATA_OUTPUT			*moder |= GPIO_MODER_MODER1_0;

ZDIError zdi_driver_read_register(ZDIHandle * pHandle, uint8_t address, uint8_t * pValue)
{
	ZDIError rc = E_OK;

	__disable_irq();

	uint32_t destdata[16];
	for (int i = 0; i < 16; i++) {
		destdata[i] = 0;
	}

	uint32_t * dest_ptr = destdata;

	__IO uint32_t * idr = & ZDI_DATA_GPIO_Port->IDR;
	__IO uint32_t * bsrr = & ZDI_CLOCK_GPIO_Port->BSRR;
	__IO uint32_t * moder = & ZDI_CLOCK_GPIO_Port->MODER;

//      Base Signal: Clock Low, Data High
/**************************************************************************************/

	ZDI_CLOCK_LOW
	ZDI_DATA_HIGH

//      Start Signal
/**************************************************************************************/
	ZDI_DATA_HIGH

	NOP_CLOCK_20
	ZDI_CLOCK_HIGH
	NOP_CLOCK_10

	ZDI_DATA_LOW
	NOP_CLOCK_10

//      Bit 6
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 5
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 4
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 3
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 2
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 1
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_HIGH						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 0
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Or High, depends
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit R/W
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_HIGH						// Data High = Read
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit Separator
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Read Data
/**************************************************************************************/

//      Bit 7 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 6 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 5 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 4 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 3 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 2 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 1 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit 0 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	// ZDI_DATA_INPUT
	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20

//      Bit End Condition
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_OUTPUT
	ZDI_DATA_HIGH

	NOP_CLOCK_10

	ZDI_CLOCK_HIGH

	NOP_CLOCK_20
	__enable_irq();

//	for (int i = 0; i < 16; i++) {
//		printf("data[%d] = 0x%lx\n", i, destdata[i]);
//	}

	return rc;
}

ZDIError zdi_driver_write_register(ZDIHandle * pHandle, uint8_t address, uint8_t value)
{
	ZDIError rc = E_OK;

	return rc;
}
