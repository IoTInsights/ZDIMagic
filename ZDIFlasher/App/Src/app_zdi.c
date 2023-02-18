/*
 * app_zdi.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Bernd Wiegmann
 */

#include <stdio.h>

#include "app_zdi.h"
#include "zdi.h"

static ZDIHandle zdi_handle;

void app_zdi_init()
{
	printf("\n\n\nZDI Flasher %d.%d.%d " ZDI_VERSION_DATE "\n", ZDI_VERSION_MAJOR, ZDI_VERSION_MINOR, ZDI_VERSION_PATCH);

	zdi_init(&zdi_handle);

	ZDIError rc = zdi_open(&zdi_handle);

	if (E_OK != rc) {
		printf("zdi_open: rc=%d\n", rc);
	}
	else {
		printf("CPU Id=              0x%02x%02x Revision=0x%02x\n", zdi_handle.id_h, zdi_handle.id_l, zdi_handle.id_rev);
		printf("ZDI Status =         0x%02x\n", zdi_handle.zdi_status);
	}

	if (E_OK == rc) {
		app_zdi_testing();
	}
}

void app_zdi_loop()
{
	zdi_loop();
}

ZDIError app_zdi_open()
{
	ZDIError rc = zdi_open(&zdi_handle);

	if (rc != E_OK) {
		printf("zdi_open failed rc=%d\n", rc);
	}

	return rc;
}

ZDIError app_zdi_testing()
{
	ZDIError rc = E_OK;
	uint8_t StatusRegister = 0;

	printf("\nZDI Test\n");

	printf("Status Register=     0x%02x\n", zdi_handle.zdi_status);

	StatusRegister = zdi_read_bus_status_register(&zdi_handle);
	printf("Bus Status Register= 0x%02x\n", StatusRegister);

	printf("Activate ZDI\n");
	rc = zdi_activate_zdi(&zdi_handle);

	printf("Status Register=     0x%02x\n", zdi_handle.zdi_status);
	printf("PC=                  0x%lx\n", zdi_handle.pc);

	printf("Deactivate ZDI\n");
	zdi_deactivate_zdi(&zdi_handle);

	printf("Status Register=     0x%02x\n", zdi_handle.zdi_status);

	return rc;
}
