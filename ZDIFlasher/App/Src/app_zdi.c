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
	printf("ZDI Flasher %d.%d.%d " ZDI_VERSION_DATE "\n", ZDI_VERSION_MAJOR, ZDI_VERSION_MINOR, ZDI_VERSION_PATCH);

	zdi_init();

	ZDIError rc = zdi_open(&zdi_handle);

	if (E_OK != rc) {
		printf("zdi_open: rc=%d\n", rc);
	}
}

void app_zdi_loop()
{
	zdi_loop();
}

ZDIError app_zdi_connect()
{
	ZDIError rc = zdi_connect(&zdi_handle);

	printf("zdi_connect rc=%d id=0x%02x%02x rev=0x%02x\n", rc, zdi_handle.id_h, zdi_handle.id_l, zdi_handle.id_rev);

	return rc;
}
