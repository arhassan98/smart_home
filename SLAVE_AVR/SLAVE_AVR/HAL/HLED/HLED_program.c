/**************************************************************************/
/* Name:    HLED_program.c                                                */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains LEDs logical program                   */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "HLED_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void HLED_Init(void)
{
	/* Setting LED1 as an output pin */
	MDIO_SetPinDirection(LED1_PORT, LED1_PIN, OUTPUT);

	/* Setting LED2 as an output pin */
	MDIO_SetPinDirection(LED2_PORT, LED2_PIN, OUTPUT);
}

void HLED_Value(u8_t LED, u8_t value)
{
	/* Switching over LEDs */
	switch(LED)
	{
		/* In case of LED1 */
		case LED1:
		
			/* Switching over LED values */
			switch(value)
			{
				/* In case of HIGH value */
				case HIGH:
					/* Setting LED1 to HIGH value */
					MDIO_SetPinValue(LED1_PORT, LED1_PIN, HIGH);
					break;
			
				/* In case of LOW value */
				case LOW:
					/* Setting LED1 to LOW value */
					MDIO_SetPinValue(LED1_PORT, LED1_PIN, LOW);
					break;
			}
			break;
		
		/* In case of LED2 */
		case LED2:
		
			/* Switching over LED values */
			switch(value)
			{
				/* In case of HIGH value */
				case HIGH:
				/* Setting LED2 to HIGH value */
				MDIO_SetPinValue(LED1_PORT, LED2_PIN, HIGH);
				break;
			
				/* In case of LOW value */
				case LOW:
				/* Setting LED2 to LOW value */
				MDIO_SetPinValue(LED1_PORT, LED2_PIN, LOW);
				break;
			}
			break;
	}
}