/*
 * zdi.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Bernd Wiegmann
 */

#include "zdi.h"
#include "zdi_driver.h"

void zdi_init()
{
	zdi_driver_init();
}

void zdi_loop()
{
	zdi_driver_loop();
}

ZDIError zdi_open(ZDIHandle * pHandle)
{
	ZDIError rc = E_OK;

	pHandle->is_open = true;
	pHandle->is_connected = false;

	return rc;
}

ZDIError zdi_close(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;

	if (pHandle->is_open) {
		rc = E_OK;
		pHandle->is_open = false;
	}

	return rc;
}

ZDIError zdi_connect(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;

	if (pHandle->is_open) {
		rc = E_OK;
	}

	if ((E_OK == rc) && (pHandle->is_connected)) {
		rc = E_ErrorAlreadyConnected;
	}

	if ((E_OK == rc) && (pHandle->is_open)) {
		rc = zdi_driver_connect(pHandle);
	}

	return rc;
}

ZDIError zdi_reset(ZDIHandle * pHandle)
{
	ZDIError rc = E_ErrorNotOpen;

	if (pHandle->is_open) {
		rc = E_OK;
	}

	if ((E_OK == rc) && (pHandle->is_open)) {
		rc = zdi_driver_reset_target(pHandle);
	}

	return rc;
}
