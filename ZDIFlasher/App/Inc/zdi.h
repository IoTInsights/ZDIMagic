/*
 * zdi.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_ZDI_H_
#define INC_ZDI_H_

#include "zdi_types.h"

void zdi_init();
void zdi_loop();

ZDIError zdi_open(ZDIHandle * pHandle, TIM_HandleTypeDef * pTimer);
ZDIError zdi_close(ZDIHandle * pHandle);

ZDIError zdi_connect(ZDIHandle * pHandle);

#endif /* INC_ZDI_H_ */
