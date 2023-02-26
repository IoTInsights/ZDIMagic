/*
 * app_usb.c
 *
 *  Created on: Feb 23, 2023
 *      Author: Bernd Wiegmann
 */

#include "usbd_cdc_if.h"

#include "app_commander.h"
#include "app_usb.h"
#include "zdi_constants.h"

static uint8_t receive_buffer[ZDI_APP_USB_RECEIVE_BUFFER_SIZE];
static uint32_t write_pos = 0;
static uint32_t level = 0;

void app_usb_init()
{
	write_pos = 0;
	level = 0;
}

void app_usb_loop()
{
}

void app_usb_receive_buffer(const uint8_t * pData, uint32_t length)
{
	for (uint32_t i = 0; ((i < length) && (write_pos < ZDI_APP_USB_RECEIVE_BUFFER_SIZE)); i++) {
		if ((write_pos > 0) || ('{' == pData[i])) {
			receive_buffer[write_pos++] = pData[i];
			if ('{' == pData[i]) {
				level += 1;
			}
			else if ('}' == pData[i]) {
				level -= 1;
				if (0 == level) {
					app_commander_receive_message(receive_buffer, write_pos);
					write_pos = 0;
				}
			}
		}
	}

	if (write_pos >= ZDI_APP_USB_RECEIVE_BUFFER_SIZE) {
		write_pos = 0;
		level = 0;
	}
}
