/********************************************************************************/
/* Name:    main.c															    */
/* Author:  Ahmed Hassan													    */
/* Version: v1.0															    */
/* Description: This file contains the SLAVE which is the AVR MCU main program  */
/********************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LBIT_MATH.h"
#include "LIB/LSTD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MSPI/MSPI_interface.h"
#include "HAL/HLED/HLED_interface.h"
/************************************************************************/
/*                               Main Program                           */
/************************************************************************/
int main(void)
{
	/* Local variable that will contains the received data from SPI module */
	u8_t rcvData = '0';
	
	/* Initializing SPI module */
	MSPI_SlaveInit();
	
	/* Initializing LEDs */
	HLED_Init();
	
	/* Infinite loop */
	while(1)
	{
		/* Receiving data from SPI module over specific pin (MISO)*/
		rcvData = MSPI_SlaveRcvByte();
		
		/* Switching over possible values */
		switch(rcvData)
		{
			/* In case of "1" value */
			case '1':
				/* Setting LED1 to LOW */
				HLED_Value(LED1, LOW);
				break;
				
			/* In case of "2" value */
			case '2':
				/* Setting LED1 to HIGH */
				HLED_Value(LED1, HIGH);
				break;
				
			/* In case of "3" value */
			case '3':
				/* Setting LED2 to LOW */
				HLED_Value(LED2, LOW);
				break;
				
			/* In case of "4" value */
			case '4':
				/* Setting LED2 to HIGH */
				HLED_Value(LED2, HIGH);
				break;	
		}
		
		/* Reseting received variable */
		rcvData = '0';
	}
	
	/* Return from main function */
	return 0;
}

