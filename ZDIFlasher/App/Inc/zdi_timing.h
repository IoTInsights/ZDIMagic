/*
 * zdi_timing.h
 *
 *  Created on: Feb 12, 2023
 *      Author: Bernd Wiegmann
 */

#ifndef INC_ZDI_TIMING_H_
#define INC_ZDI_TIMING_H_

#define NOP_CLOCK_1		\
		asm(			\
			"NOP"		\
		);

#define NOP_CLOCK_2		\
		asm(			\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_3		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_4		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_5		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_5		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_6		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_7		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_8		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_9		\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_10	\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#define NOP_CLOCK_20	\
		asm(			\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP\n\t"	\
			"NOP"		\
		);

#endif /* INC_ZDI_TIMING_H_ */
