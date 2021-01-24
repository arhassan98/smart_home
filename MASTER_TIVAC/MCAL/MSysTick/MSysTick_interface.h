/************************************************************************************/
/* Name:    MSysTick_interface.h                                                    */
/* Author:  Ahmed Hassan                                                            */
/* Version: v1.0                                                                    */
/* Description: This file contains interfacing information for SysTick timer module */
/************************************************************************************/

/*Header file guard*/
#ifndef MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_


/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function id responsible for delaying time by us */
void _delay_us(u32_t usDelay);

/* This function id responsible for delaying time by ms */
void _delay_ms(u32_t msDelay);


#endif /* MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_ */
