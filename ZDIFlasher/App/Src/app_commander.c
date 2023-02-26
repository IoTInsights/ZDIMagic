/*
 * app_commander.c
 *
 *  Created on: Feb 24, 2023
 *      Author: Bernd Wiegmann
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

#include "app_commander.h"

void app_commander_init()
{
}

void app_commander_loop()
{
}

void app_commander_receive_message(const uint8_t * pData, uint32_t length)
{
	printf("Received Message over USB length=%ld\n", length);

	cJSON *json = cJSON_ParseWithLength((const char *)pData, length);

	char * str = cJSON_Print(json);

	if (0 != str) {
		printf(str);
		printf("\n");
		free(str);
	}
	else {
		printf("Was not able to print json\n");
	}

	cJSON_Delete(json);

	const char * send_str = "{\"command\": \"info\"}";

	CDC_Transmit_FS(send_str, strlen(send_str));
}
