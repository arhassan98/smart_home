/********************************************************************************/
/* Name:    main.c															    */
/* Author:  Ahmed Hassan													    */
/* Version: v1.0															    */
/* Description: This file contains the MASTER which is the AVR MCU main program */
/********************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LBIT_MATH.h"
#include "LIB/LSTD_TYPES.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MSPI/MSPI_interface.h"
#include "HAL/HBLUETOOTH/HBLUETOOTH_interface.h"

/************************************************************************/
/*                               Main Program                           */
/************************************************************************/
int main(void)
{
	/* Local variable that will contains the received data from bluetooth module */
	u8_t rcvData = '0';
	
	/* Initializing SPI module */
	MSPI_MasterInit(MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_64);
	
	/* Initializing bluetooth module */
	HBLUETOOTH_Init();
	
	/* Infinite loop */
	while(1)
	{
		/* Receiving data from bluetooth module */
		rcvData = HBLUETOOTH_RcvData();
		
		if(rcvData != '0')
		{
			/* Sending data to slave over SPI specific line (MOSI) */
			MSPI_MasterSendByte(rcvData);
			
			/* Reseting  received variable */
			rcvData = '0';
		}
	}
	
	/* Return from main function */
	return 0;
}