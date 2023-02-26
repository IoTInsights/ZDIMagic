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
#include "zdi_constants.h"

typedef struct zdi_handle_s {
	bool				is_open;
	bool				is_zdi_active;
	uint8_t 			id_l;
	uint8_t 			id_h;
	uint8_t 			id_rev;
	uint8_t				zdi_status;
	uint32_t			pc;
} ZDIHandle;

typedef enum zdi_error_e {
	E_OK,
	E_ErrorNotOpen,
	E_ErrorAlreadyOpen,
	E_ErrorUnknownTarget,
	E_ErrorActivateZDI,
	E_ErrorDisactivateZDI,
	E_ErrorUnknown
} ZDIError;

// Read-Only Register

#define	ZDI_ID_L				0x00			// Product Id Low Byte
#define ZDI_ID_H				0x01			// Product Id High Byte
#define ZDI_ID_REV				0x02			// Product Id Revision
#define	ZDI_STAT				0x03
#define ZDI_RD_L				0x10
#define ZDI_RD_H				0x11
#define ZDI_RD_U				0x12
#define ZDI_BUS_STAT			0x17
#define ZDI_RD_MEM				0x20

// Write Only Register

#define ZDI_ADDR0_L				0x00
#define ZDI_ADDR0_H				0x01
#define ZDI_ADDR0_U				0x02
#define ZDI_ADDR1_L				0x04
#define ZDI_ADDR1_H				0x05
#define ZDI_ADDR1_U				0x06
#define ZDI_ADDR2_L				0x08
#define ZDI_ADDR2_H				0x09
#define ZDI_ADDR2_U				0x0A
#define ZDI_ADDR3_L				0x0C
#define ZDI_ADDR3_H				0x0D
#define ZDI_ADDR3_U				0x0E
#define ZDI_BRK_CTL				0x10
#define ZDI_MASTER_CTL			0x11
#define ZDI_WR_DATA_L			0x13
#define ZDI_WR_DATA_H			0x14
#define ZDI_WR_DATA_U			0x15
#define ZDI_RW_CTL				0x16
#define ZDI_BUS_CTL				0x17
#define ZDI_IS4					0x21
#define ZDI_IS3					0x22
#define ZDI_IS2					0x23
#define ZDI_IS1					0x24
#define ZDI_IS0					0x25
#define ZDI_WR_MEM				0x30

// Register Flags

#define	ZDI_STAT_ZDI_ACTIVE		0x80
#define	ZDI_STAT_HALT_SLP		0x20
#define	ZDI_STAT_ADL			0x10
#define	ZDI_STAT_MADL			0x80
#define	ZDI_STAT_IEF1			0x40

#define	ZDI_RW_CTL_AF			0x00
#define	ZDI_RW_CTL_BC			0x01
#define	ZDI_RW_CTL_DE			0x02
#define	ZDI_RW_CTL_HL			0x03
#define	ZDI_RW_CTL_IX			0x04
#define	ZDI_RW_CTL_IY			0x05
#define	ZDI_RW_CTL_SP			0x06
#define	ZDI_RW_CTL_PC			0x07
#define	ZDI_RW_CTL_SET_ADL		0x08
#define	ZDI_RW_CTL_RESET_ADL	0x09
#define	ZDI_RW_CTL_EXCHANGE		0x0A
#define	ZDI_RW_CTL_MEM_PC		0x0B
#define	ZDI_RW_CTL_WEITE_FLAG	0x80

#endif /* INC_ZDI_TYPES_H_ */
