/*
 * app_zdi.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Bernd Wiegmann
 */

#include <stdio.h>

#include "app_button.h"
#include "app_commander.h"
#include "app_usb.h"
#include "app_zdi.h"
#include "zdi.h"

static ZDIHandle zdi_handle;
static uint8_t	buffer[16000];

void app_zdi_init()
{
	app_button_init();
	app_commander_init();
	app_usb_init();

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
	app_button_loop();
	app_commander_loop();
	app_usb_loop();
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

	app_zdi_print_dump(0, 0x100);

	printf("Deactivate ZDI\n");
	zdi_deactivate_zdi(&zdi_handle);

	printf("Status Register=     0x%02x\n", zdi_handle.zdi_status);

	return rc;
}

void app_zdi_print_dump(uint32_t address, uint32_t length)
{
	uint32_t real_lenth = length;

	if (length > sizeof(buffer)) {
		real_lenth = sizeof(buffer);
	}

	zdi_read_memory(&zdi_handle, address, buffer, real_lenth);

	for (uint32_t i = 0; i < real_lenth; i++) {
		if ((i % 16) == 0) {
			printf("\n%06lx ", address + i);
		}
		printf("%02x ", buffer[i]);
	}
	printf("\n");
}
