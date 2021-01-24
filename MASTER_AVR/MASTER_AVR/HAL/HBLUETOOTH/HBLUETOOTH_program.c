/**************************************************************************/
/* Name:    HBLUETOOTH_program.c                                          */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains bluetooth module logical program       */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../MCAL/MUART/MUART_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void HBLUETOOTH_Init(void)
{
	/* Initializing UART with baud rate 9600 bps*/
	MUART_Init(MUART_9600_BPS);
	
	/* Return from this function */
	return;
}

u8_t HBLUETOOTH_RcvData(void)
{
	/* Local variable that will contains the received data from UART module */
	u8_t rcvDataFromUART = '0';
	
	/* Receiving data from UART module over Rx line */
	MUART_RecvByte(&rcvDataFromUART);
	
	/* Return from this function */
	return rcvDataFromUART;
}