/*
 * zdi_types.h
 *
 *  Created on: Feb 4, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_ZDI_TYPES_H_
#define INC_ZDI_TYPES_H_

#include <stdbool.h>

#include "gpio.h"

#define	ZDI_VERSION_DATE		"2022-02-15"

#define	ZDI_VERSION_MAJOR		0
#define	ZDI_VERSION_MINOR		7
#define ZDI_VERSION_PATCH		0

#define	ZDI_BUFFER_SIZE			8192

typedef struct zdi_handle_s {
	bool				is_open;
	bool				is_connected;
	uint8_t 			id_l;
	uint8_t 			id_h;
	uint8_t 			id_rev;
	uint8_t				buffer[ZDI_BUFFER_SIZE];
} ZDIHandle;

typedef enum zdi_error_e {
	E_OK,
	E_ErrorNotOpen,
	E_ErrorNotConnected,
	E_ErrorAlreadyConnected,
	E_ErrorUnknown
} ZDIError;

// Read-Only Register

#define	ZDI_ID_L			0x00			// Product Id Low Byte
#define ZDI_ID_H			0x01			// Product Id High Byte
#define ZDI_ID_REV			0x02			// Product Id Revision
#define	ZDI_STATUS			0x03
#define ZDI_RD_L			0x10
#define ZDI_RD_H			0x11
#define ZDI_RD_U			0x12
#define ZDI_BUS_STAT		0x17
#define ZDI_RD_MEM			0x20

#endif /* INC_ZDI_TYPES_H_ */
