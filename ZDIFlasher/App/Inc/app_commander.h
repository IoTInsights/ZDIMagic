/*
 * app_commander.h
 *
 *  Created on: Feb 24, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_APP_COMMANDER_H_
#define INC_APP_COMMANDER_H_

#include <stdint.h>

void app_commander_init();
void app_commander_loop();

void app_commander_receive_message(const uint8_t * pData, uint32_t length);

#endif /* INC_APP_COMMANDER_H_ */
