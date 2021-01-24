/**************************************************************************/
/* Name:    MSPI_program.c                                                */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains SPI module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "../../LIB/LBIT_MATH.h"
#include "../../LIB/LSTD_TYPES.h"
#include "../MDIO/MDIO_interface.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

#define  F_CPU   16000000UL
#include "util/delay.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void MSPI_MasterInit(u8_t dataMode, u8_t clkPrescaler)
{
	/* Enabling master mode, Sending MSB first and Setting data mode */
	MSPI_SPCR = (0x10) | (dataMode << 2);
	
	/* Checking if the prescaler value is dividable by two or not */
	if( (dataMode % 2) == 0)
	{
		/* Enabling SPI double speed */
		SET_BIT(MSPI_SPSR, 0);
	}
	else
	{
		/* Do nothing */
	}
	
	/* Setting SPI clock */
	MSPI_SPCR |= (clkPrescaler/2);
	
	/* Setting MOSI, SCK and SS pins directions as output */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MOSI_PIN|MSPI_SCK_PIN|MSPI_SS_PIN, OUTPUT);
	
	/* Setting MISO pin direction as input float */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MISO_PIN, INPUT_FLOAT);
	
	/*Return from this function*/
	return;
}

void MSPI_MasterSendByte(u8_t data)
{
	/* Local variable used to save received data from slave */
	u8_t flushBuffer = 0;
	
	/* Variable used in timing out operations */
	u16_t timeoutVar = 0;
	
	/* Enabling SPI module */
	SET_BIT(MSPI_SPCR, 6);
	
	/* Sending master data */
	MSPI_SPDR = data;
	
	/* Waiting until data is transmitted or timeout in 10ms */
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeoutVar < 10000)
	{
		/* Increasing timeout variable */
		timeoutVar++;
		
		/* Delay for 1us */
		_delay_us(1);
	}
	
	/* Assigning the data received from slave */
	flushBuffer = MSPI_SPDR;
	
	/* Disabling SPI module */
	CLEAR_BIT(MSPI_SPCR, 6);

	/* Return from this function */
	return;
}