/*
 * app_button.c
 *
 *  Created on: Feb 12, 2023
 *      Author: Bernd Wiegmann
 */

#include <stdbool.h>
#include <stdio.h>

#include "gpio.h"

#include "app_button.h"
#include "app_zdi.h"

static bool button_pressed = false;

void app_button_init()
{
	button_pressed = false;
}

void app_button_loop()
{
	if (button_pressed) {
		button_pressed = false;

		HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);

		app_zdi_connect();
	}
}

void app_button_irq_handler()
{
	button_pressed = true;
}
