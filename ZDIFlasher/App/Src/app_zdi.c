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
	printf("ZDI Flasher 0.05 2023-02-12-001\n");

	zdi_init();

	ZDIError rc = zdi_open(&zdi_handle);

	if (E_OK != rc) {
		printf("zdi_open returned %d\n", rc);
	}
}

void app_zdi_loop()
{
	zdi_loop();
}

ZDIError app_zdi_connect()
{
	return zdi_connect(&zdi_handle);
}
