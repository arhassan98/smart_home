/**************************************************************************/
/* Name:    MSysTick_program.c                                            */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains SysTick timer module logical program   */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include "MSysTick_private.h"
#include "MSysTick_interface.h"

/************************************************************************/
/*                         Functions' Definitions                       */
/************************************************************************/

/* This function id responsible for delaying time by us */
void _delay_us(u32_t usDelay)
{
    /* To convert from 62.5ns to 1us */
    u32_t delay = usDelay * 16;

    /* Disabling SysTick during setup */
    NVIC_ST_CTRL_R = 0;

    /* Number of counts to wait */
    NVIC_ST_RELOAD_R = delay-1;

    /* Any value written to CURRENT clears */
    NVIC_ST_CURRENT_R = 0;

    /* Enabling SysTick with core clock */
    NVIC_ST_CTRL_R |= 0x05;

    /* Waiting for COUNT flag */
    while(GET_BIT(NVIC_ST_CTRL_R, 4) == 0);
}

/* This function id responsible for delaying time by ms */
void _delay_ms(u32_t msDelay)
{
    /* Delaying 1000 us = 1ms */
    _delay_us(msDelay * 1000);
}
