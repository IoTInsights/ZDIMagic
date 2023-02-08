/*
 * zdi_driver.c
 *
 *  Created on: 03.02.2023
 *      Author: Bernd Wiegmann
 */

#include <memory.h>

#include "zdi_driver.h"

// #define DEBUG_PIN

void zdi_driver_init()
{

}

void zdi_driver_loop()
{

}

ZDIError zdi_driver_connect(ZDIHandle * pHandle)
{
	ZDIError rc = E_OK;

	uint8_t id_l = 0;
	uint8_t id_h = 0;
	uint8_t id_rev = 0;

	rc = zdi_driver_read_register(pHandle, ZDI_ID_L, &id_l);

	if (E_OK == rc) {
		rc = zdi_driver_read_register(pHandle, ZDI_ID_H, &id_h);
	}

	if (E_OK == rc) {
		rc = zdi_driver_read_register(pHandle, ZDI_ID_REV, &id_rev);
	}

	return rc;
}

ZDIError zdi_driver_read_register(ZDIHandle * pHandle, uint8_t address, uint8_t * pValue)
{
	ZDIError rc = E_OK;

	__IO uint32_t * bsrr = & ZDI_CLOCK_GPIO_Port->BSRR;

	while (1) {
//      Base Signal: Clock Low, Data High
/**************************************************************************************/

		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		*bsrr = ZDI_DATA_Pin;

//      Start Signal
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

//      Bit 6
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

//      Bit 5
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

//      Bit 4
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

//      Bit 3
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);


//      Bit 2
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);


//      Bit 1
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);


//      Bit 0
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_DATA_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);


//      Bit R/W
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_DATA_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_DATA_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

//      Read Data
/**************************************************************************************/

		ZDI_DATA_GPIO_Port->MODER &= ~(GPIO_MODER_MODER1);	// Pin to Input

		for (int i = 0; i < 9; i++) {
			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);
			*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);

			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);

			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);
			*bsrr = ZDI_CLOCK_Pin;
			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);

			asm(
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP\n\t"
				"NOP"
			);
		}

		ZDI_DATA_GPIO_Port->MODER |= GPIO_MODER_MODER1_0;


//      Bit End Condition
/**************************************************************************************/
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		*bsrr = ZDI_DATA_Pin;

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = ZDI_CLOCK_Pin;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);
		*bsrr = (uint32_t)ZDI_CLOCK_Pin << 16U;
		asm(
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP\n\t"
			"NOP"
		);

		HAL_Delay(1);
	}

	return rc;
}

#if 0
ZDIError zdi_driver_read_register(ZDIHandle * pHandle, uint8_t address, uint8_t * pValue)
{
	ZDIError rc = E_OK;

	GPIO_InitTypeDef GPIO_InitStruct = {0};

	while (1) {
		uint32_t start_config_clock;
		uint32_t toggle_config_clock;

		uint32_t start_config_data;
		uint32_t force_low_config_data;

		__disable_irq();

#ifdef DEBUG_PIN
		HAL_GPIO_WritePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin, GPIO_PIN_RESET);
#endif

		start_config_clock = pHandle->pTimer->Instance->CCMR1;
		toggle_config_clock = (start_config_clock & ~TIM_CCMR1_OC1M) | TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1;

		start_config_data = toggle_config_clock;
		force_low_config_data = (start_config_data & ~TIM_CCMR1_OC2M)  | TIM_CCMR1_OC2M_1;

		pHandle->pTimer->Instance->CCMR1 = toggle_config_clock;

//      Sync to Clock Signal
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// W0
			;
		}
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W0
			;
		}

//      Start Bit
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// W1
			;
		}
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif

/**************************************************************************************/

//      Bit 6
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// A1
			;
		}
		pHandle->pTimer->Instance->CCMR1 = start_config_data;
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// W2
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W2
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 5
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A3
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W3
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 4
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A4
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W4
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 3
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A5
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W5
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 2
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A6
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W6
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 1
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A7
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W7
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit 0
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// A8
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// W8
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

//      Bit R/W
/**************************************************************************************/
		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// A9
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
		pHandle->pTimer->Instance->CCMR1 = start_config_data;

		while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// W9
			;
		}
#ifdef DEBUG_PIN
		HAL_GPIO_TogglePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin);
#endif
/**************************************************************************************/

		pHandle->pTimer->Instance->CCMR1 = force_low_config_data;

	    GPIO_InitStruct.Pin = T2_DATA_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = 0;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

#ifdef DEBUG_PIN
		HAL_GPIO_WritePin(T2_DEBUG_GPIO_Port, T2_DEBUG_Pin, GPIO_PIN_RESET);
#endif



		for (int i = 0; i < 10; i++) {
			while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) != 0) {		// E1
				;
			}
			while ((T2_CLOCK_GPIO_Port->IDR & T2_CLOCK_Pin) == 0) {		// E2
				;
			}
		}

		pHandle->pTimer->Instance->CCMR1 = start_config_clock;

		__enable_irq();

	    GPIO_InitStruct.Pin = T2_DATA_Pin;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	    GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		HAL_Delay(1);
	}

	return rc;
}

#endif

ZDIError zdi_driver_write_register(ZDIHandle * pHandle, uint8_t address, uint8_t value)
{
	ZDIError rc = E_OK;

	return rc;
}
