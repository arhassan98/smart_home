/********************************************************************************/
/* Name:    main.c															    */
/* Author:  Ahmed Hassan													    */
/* Version: v1.0															    */
/* Description: This file contains the MASTER which is the AVR MCU main program */
/********************************************************************************/
#include "LIB/LBIT_MATH.h"
#include "LIB/LSTD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MSPI/MSPI_interface.h"
#include "HAL/HBLUETOOTH/HBLUETOOTH_interface.h"

int main(void)
{
	/* Local variable that will contains the received data from bluetooth module */
	u8_t rcvData = '0';
	
	/* Initializing SPI module */
	MSPI_MasterInit();
	
	/* Initializing bluetooth module */
	MUART_Init(MUART_9600_BPS);
	
	/* Infinite loop */
	while(1)
	{
		/* Receiving data from UART module over Rx line and saved this data in "rcvDataFromUART" variable */
		MUART_RecvByte(&rcvDataFromUART);
		
		/* Sending the d */
		MSPI_SendByte(rcvDataFromUART);
	}
	
    
	/* Return from main function */
	return 0;
}

