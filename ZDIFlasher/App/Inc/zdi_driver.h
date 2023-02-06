/*
 * zdi_driver.h
 *
 *  Created on: 03.02.2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_ZDI_DRIVER_H_
#define INC_ZDI_DRIVER_H_

#include "zdi_types.h"

void zdi_driver_init();
void zdi_driver_loop();

ZDIError zdi_driver_connect(ZDIHandle * pHandle);

ZDIError zdi_driver_read_register(ZDIHandle * pHandle, uint8_t address, uint8_t * pValue);

ZDIError zdi_driver_write_register(ZDIHandle * pHandle, uint8_t address, uint8_t value);

#endif /* INC_ZDI_DRIVER_H_ */
