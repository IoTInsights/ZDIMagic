/*
 * zdi.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_ZDI_H_
#define INC_ZDI_H_

#include "zdi_types.h"

void zdi_init(ZDIHandle * pHandle);
void zdi_loop();

ZDIError zdi_open(ZDIHandle * pHandle);
ZDIError zdi_close(ZDIHandle * pHandle);

ZDIError zdi_activate_zdi(ZDIHandle * pHandle);
ZDIError zdi_deactivate_zdi(ZDIHandle * pHandle);

void zdi_reset_hard(ZDIHandle * pHandle);
void zdi_reset_soft(ZDIHandle * pHandle);

void zdi_break_next(ZDIHandle * pHandle);
void zdi_break_release(ZDIHandle * pHandle);

uint8_t zdi_read_status_register(ZDIHandle * pHandle);
uint8_t zdi_read_bus_status_register(ZDIHandle * pHandle);

uint32_t zdi_read_memory_address_register(ZDIHandle * pHandle, uint8_t ReadCtl);
uint8_t zdi_read_memory_data_register(ZDIHandle * pHandle);

void zdi_write_memory_address_register(ZDIHandle * pHandle, uint8_t ReadCtl, uint32_t Value);
void zdi_write_memory_data_register(ZDIHandle * pHandle, uint8_t MemoryData);

uint32_t zdi_read_AF(ZDIHandle * pHandle);
uint32_t zdi_read_BC(ZDIHandle * pHandle);
uint32_t zdi_read_DE(ZDIHandle * pHandle);
uint32_t zdi_read_HL(ZDIHandle * pHandle);
uint32_t zdi_read_IX(ZDIHandle * pHandle);
uint32_t zdi_read_IY(ZDIHandle * pHandle);
uint32_t zdi_read_SP(ZDIHandle * pHandle);
uint32_t zdi_read_PC(ZDIHandle * pHandle);

void zdi_write_AF(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_BC(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_DE(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_HL(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_IX(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_IY(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_SP(ZDIHandle * pHandle, uint32_t Value);
void zdi_write_PC(ZDIHandle * pHandle, uint32_t Value);

#endif /* INC_ZDI_H_ */
