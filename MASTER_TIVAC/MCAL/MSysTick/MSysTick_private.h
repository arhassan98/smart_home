/**********************************************************************************/
/* Name:    MSysTick_private.h                                                    */
/* Author:  Ahmed Hassan                                                          */
/* Version: v1.0                                                                  */
/* Description: This file contains private information for SysTick timer module   */
/**********************************************************************************/

/* Header file guard */
#ifndef MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LSTD_TYPES.h"

/************************************************************************/
/*                          SysTick Registers (NVIC)                    */
/************************************************************************/
#define NVIC_ST_CTRL_R          (*((volatile u32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile u32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile u32_t *)0xE000E018))


#endif /* MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_ */
