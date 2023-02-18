/*
 * zdi.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Bernd Wiegmann
 */

#include "zdi.h"
#include "zdi_driver.h"

void zdi_init(ZDIHandle * pHandle)
{
	pHandle->is_open = false;
	pHandle->is_zdi_active = false;
	pHandle->zdi_status = 0;
	pHandle->pc = 0;

	zdi_driver_init();
}

void zdi_loop()
{
	zdi_driver_loop();
}

ZDIError zdi_close(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;

	if (pHandle->is_open) {
		rc = E_OK;
		pHandle->is_open = false;
	}

	return rc;
}

ZDIError zdi_open(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorAlreadyOpen;

	if (!pHandle->is_open) {
		rc = E_OK;
	}

	if (E_OK == rc) {
		zdi_driver_open(pHandle);

		rc = E_ErrorUnknownTarget;

		if (pHandle->id_h == 0) {
			switch(pHandle->id_l) {
			case 0x07:
				rc = E_OK;
				break;

			default:
				break;
			}
		}
	}

	if (E_OK == rc) {
		zdi_read_status_register(pHandle, &pHandle->zdi_status);

		if ((pHandle->zdi_status & ZDI_STAT_ZDI_ACTIVE) != 0) {
			pHandle->is_zdi_active = true;
		}
	}

	if (E_OK == rc) {
		pHandle->is_open = true;
	}

	return rc;
}

ZDIError zdi_activate_zdi(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;
	uint32_t max_tries = 10;

	if (pHandle->is_open) {
		rc = E_OK;
	}

	if (E_OK == rc) {
		rc = E_ErrorActivateZDI;

		while (!pHandle->is_zdi_active && (max_tries--)) {
			zdi_break_next(pHandle);
			zdi_read_status_register(pHandle, &pHandle->zdi_status);

			if ((pHandle->zdi_status & ZDI_STAT_ZDI_ACTIVE) != 0) {
				pHandle->is_zdi_active = true;

				zdi_read_PC(pHandle, &pHandle->pc);
			}
		}
	}

	return rc;
}

ZDIError zdi_deactivate_zdi(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;
	uint32_t max_tries = 10;

	if (pHandle->is_open) {
		rc = E_OK;
	}

	if (E_OK == rc) {
		rc = E_ErrorDisactivateZDI;

		while (pHandle->is_zdi_active && (max_tries--)) {
			zdi_break_release(pHandle);
			zdi_read_status_register(pHandle, &pHandle->zdi_status);

			if ((pHandle->zdi_status & ZDI_STAT_ZDI_ACTIVE) == 0) {
				pHandle->is_zdi_active = false;

				zdi_write_PC(pHandle, pHandle->pc);;
			}
		}
	}

	return rc;
}

void zdi_reset_hard(ZDIHandle * pHandle)
{
	zdi_driver_reset_target(pHandle);
}

void zdi_reset_soft(ZDIHandle * pHandle)
{
	zdi_driver_write_register(pHandle, ZDI_MASTER_CTL, 0x80);
}

void zdi_break_next(ZDIHandle * pHandle)
{
	zdi_driver_write_register(pHandle, ZDI_BRK_CTL, 0x80);
}

void zdi_break_release(ZDIHandle * pHandle)
{
	zdi_driver_write_register(pHandle, ZDI_BRK_CTL, 0x00);
}

void zdi_read_status_register(ZDIHandle * pHandle, uint8_t * pStatusRegister)
{
	zdi_driver_read_register(pHandle, ZDI_STAT, pStatusRegister);
}

void zdi_read_memory_address_register(ZDIHandle * pHandle, uint8_t ReadCtl, uint32_t * pValue)
{
	uint8_t LowByte;
	uint8_t HighByte;
	uint8_t UpperByte;

	*pValue = 0;

	zdi_driver_write_register(pHandle, ZDI_RW_CTL, ReadCtl);

	zdi_driver_read_register(pHandle, ZDI_RD_L, &LowByte);
	zdi_driver_read_register(pHandle, ZDI_RD_H, &HighByte);
	zdi_driver_read_register(pHandle, ZDI_RD_U, &UpperByte);

	*pValue = UpperByte;
	*pValue = *pValue << 8;

	*pValue += HighByte;
	*pValue = *pValue << 8;

	*pValue += LowByte;
}

void zdi_read_bus_status_register(ZDIHandle * pHandle, uint8_t * pBusStatusRegister)
{
	zdi_driver_read_register(pHandle, ZDI_BUS_STAT, pBusStatusRegister);
}

void zdi_read_memory_data_register(ZDIHandle * pHandle, uint8_t * pMemoryData)
{
	zdi_driver_read_register(pHandle, ZDI_RD_MEM, pMemoryData);
}

void zdi_write_memory_address_register(ZDIHandle * pHandle, uint8_t ReadCtl, uint32_t Value)
{
	uint8_t LowByte;
	uint8_t HighByte;
	uint8_t UpperByte;

	LowByte = (uint8_t)Value;
	Value = Value >> 8;
	HighByte = (uint8_t)Value;
	Value = Value >> 8;
	UpperByte = (uint8_t)Value;

	zdi_driver_write_register(pHandle, ZDI_WR_DATA_L, LowByte);
	zdi_driver_write_register(pHandle, ZDI_WR_DATA_H, HighByte);
	zdi_driver_write_register(pHandle, ZDI_WR_DATA_U, UpperByte);

	zdi_driver_write_register(pHandle, ZDI_RW_CTL, ReadCtl | ZDI_RW_CTL_WEITE_FLAG);
}

void zdi_write_memory_data_register(ZDIHandle * pHandle, uint8_t MemoryData)
{
	zdi_driver_write_register(pHandle, ZDI_WR_MEM, MemoryData);
}

void zdi_read_AF(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_AF, pValue);
}

void zdi_read_BC(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_BC, pValue);
}

void zdi_read_DE(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_DE, pValue);
}

void zdi_read_HL(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_HL, pValue);
}

void zdi_read_IX(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_IX, pValue);
}

void zdi_read_IY(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_IY, pValue);
}

void zdi_read_SP(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_SP, pValue);
}

void zdi_read_PC(ZDIHandle * pHandle, uint32_t * pValue)
{
	zdi_read_memory_address_register(pHandle, ZDI_RW_CTL_PC, pValue);
}

void zdi_write_AF(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_AF, Value);
}

void zdi_write_BC(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_BC, Value);
}

void zdi_write_DE(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_DE, Value);
}

void zdi_write_HL(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_HL, Value);
}

void zdi_write_IX(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_IX, Value);
}

void zdi_write_IY(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_IY, Value);
}

void zdi_write_SP(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_SP, Value);
}

void zdi_write_PC(ZDIHandle * pHandle, uint32_t Value)
{
	zdi_write_memory_address_register(pHandle, ZDI_RW_CTL_PC, Value);
}
