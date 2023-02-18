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

#define ZDI_CLOCK_HIGH			*bsrr = ZDI_CLOCK_Pin;
#define	ZDI_CLOCK_LOW			*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;

#define ZDI_DATA_HIGH			*bsrr = ZDI_DATA_Pin;
#define	ZDI_DATA_LOW			*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;

#define	ZDI_DATA_INPUT			*moder &= ~(GPIO_MODER_MODER1);
#define	ZDI_DATA_OUTPUT			*moder |= GPIO_MODER_MODER1_0;

void zdi_driver_init()
{
	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ZDI_CLOCK_GPIO_Port, ZDI_CLOCK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(ZDI_DATA_GPIO_Port, ZDI_DATA_Pin, GPIO_PIN_SET);
}

void zdi_driver_loop()
{
}

void zdi_driver_open(ZDIHandle * pHandle)
{
	zdi_driver_read_register(pHandle, ZDI_ID_L, &pHandle->id_l);
	zdi_driver_read_register(pHandle, ZDI_ID_H, &pHandle->id_h);
	zdi_driver_read_register(pHandle, ZDI_ID_REV, &pHandle->id_rev);
}

void zdi_driver_reset_target(ZDIHandle * pHandle)
{
	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(ZDI_RESET_GPIO_Port, ZDI_RESET_Pin, GPIO_PIN_SET);
}

void zdi_driver_read_register(ZDIHandle * pHandle, uint8_t address, uint8_t * pValue)
{
	__disable_irq();

	uint8_t bit_mask = 0x40;
	uint8_t result = 0;

	__IO uint32_t * idr = & ZDI_DATA_GPIO_Port->IDR;
	__IO uint32_t * bsrr = & ZDI_CLOCK_GPIO_Port->BSRR;
	__IO uint32_t * moder = & ZDI_CLOCK_GPIO_Port->MODER;

//      Base Signal: Clock Low, Data High
/**************************************************************************************/

	ZDI_CLOCK_HIGH
	ZDI_DATA_HIGH

//      Start Signal
/**************************************************************************************/
	ZDI_DATA_LOW
	NOP_CLOCK_20

//      Bit 6
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 5
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 4
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 3
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 2
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 1
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 0
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

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
	ZDI_DATA_INPUT
	NOP_CLOCK_9
	bit_mask = 0x80;

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 6 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 5 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 4 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 3 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 2 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 1 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 0 Read
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	//ZDI_DATA_INPUT
	if ((*idr & ZDI_DATA_Pin) != 0) {
		result |= bit_mask;
	}
	else {
		NOP_CLOCK_1
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

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

	*pValue = result;
}

void zdi_driver_write_register(ZDIHandle * pHandle, uint8_t address, uint8_t value)
{
	__disable_irq();

	uint8_t bit_mask = 0x40;

	__IO uint32_t * bsrr = & ZDI_CLOCK_GPIO_Port->BSRR;
	__IO uint32_t * moder = & ZDI_CLOCK_GPIO_Port->MODER;

//      Base Signal: Clock Low, Data High
/**************************************************************************************/

	ZDI_CLOCK_HIGH
	ZDI_DATA_HIGH

//      Start Signal
/**************************************************************************************/
	ZDI_DATA_LOW
	NOP_CLOCK_20

//      Bit 6
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 5
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 4
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 3
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 2
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 1
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 0
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (address & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit R/W
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	ZDI_DATA_LOW						// Data Low = Write
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

//      Bit 7 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10
	bit_mask = 0x80;

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 6 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 5 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 4 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 3 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 2 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 1 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

	ZDI_CLOCK_HIGH
	NOP_CLOCK_20

//      Bit 0 Write
/**************************************************************************************/
	ZDI_CLOCK_LOW
	NOP_CLOCK_10

	if (value & bit_mask) {
		ZDI_DATA_HIGH
	}
	else {
		ZDI_DATA_LOW
	}
	bit_mask = bit_mask >> 1;

	NOP_CLOCK_6

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
}
