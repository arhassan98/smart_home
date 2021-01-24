/**************************************************************************/
/* Name:    MUART_program.c                                               */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains UART module logical program            */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "MUART_private.h"
#include "MUART_interface.h"


#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                            Global variables                          */
/************************************************************************/
/* Global variable used in timing out operations */
u8_t timeoutVar = 0;

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void MUART_Init(u16_t baudrate)
{
	/* Clearing UART status register */
	MUART_UCSRA = 0;
	
	/* Enabling Rx and Tx */
	SET_BIT(MUART_UCSRB, 4);
	SET_BIT(MUART_UCSRB, 3);
	
	/* Choosing Asynchronous mode, Disable parity, Data length is 8-bits */
	MUART_UCSRC = (0x80) | (0x06);
	
	/* Setting low baudrate register */
	MUART_UBRRL = (u8_t)(baudrate);
	
	/* Setting high baudrate register */
	MUART_UBRRH = (u8_t)(baudrate >> 8);
	
	/* Return from this function */
	return;
}

void MUART_SendByte(u8_t data)
{	
	/* Reset timeout variable */
	timeoutVar = 0;
	
	/* Checking if UDR register is empty or not */
	if(GET_BIT(MUART_UCSRA, 5))
	{
		/* Transmitting data over Tx pin */
		MUART_UDR = data;
		
		/* Making sure that the data has been transmitted or timeout happens */
		while((GET_BIT(MUART_UCSRA, 6) == 0) && timeoutVar < 10)
		{
			/*Increase timeout variable*/
			timeoutVar++;
			
			/*Delay for 1ms*/
			_delay_ms(1);
		}
		
		/* Clearing Tx flag */
		//SET_BIT(MUART_UCSRA, 6);		
	}
	else
	{
		/* Report Error */
	}
	
	/* Return from this function */
	return;
}

void MUART_RecvByte(u8_t* data)
{
	/* Checking that there's a new data or not */
	if(GET_BIT(MUART_UCSRA, 7))
	{
		/* Reading the new data */
		*data = MUART_UDR;
	}
	else
	{
		/* Report Error */
	}
	
	/* Return from this function */
	return;
}

void MUART_SendStream(u8_t* dataStream, u8_t dataSize)
{
	/* Sending stream of data according to their size */
	while(dataSize--)
	{
		/* Send one byte at a time */
		MUART_SendByte(*dataStream);
		
		/* Increasing data pointer */
		dataStream++;	
	}
	
	/* Return from this function */
	return;	
}

/************************************************************************/
/*                             UART ISR                                 */
/************************************************************************/