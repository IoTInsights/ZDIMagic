/*
 * app_usb.h
 *
 *  Created on: Feb 23, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_APP_USB_H_
#define INC_APP_USB_H_

#include <stdint.h>

void app_usb_init();
void app_usb_loop();

void app_usb_receive_buffer(const uint8_t * pData, uint32_t length);

#endif /* INC_APP_USB_H_ */
