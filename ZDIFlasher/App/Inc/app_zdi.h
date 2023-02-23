/*
 * app_zdi.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_APP_ZDI_H_
#define INC_APP_ZDI_H_

#include "zdi.h"

void app_zdi_init();
void app_zdi_loop();

ZDIError app_zdi_open();
ZDIError app_zdi_testing();
void app_zdi_print_dump(uint32_t address, uint32_t length);

#endif /* INC_APP_ZDI_H_ */
