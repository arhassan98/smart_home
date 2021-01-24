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
void MSPI_SlaveInit()
{
	/* Setting MOSI, SCK and SS pins directions as output */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MOSI_PIN|MSPI_SCK_PIN|MSPI_SS_PIN, INPUT_FLOAT);
	
	/* Setting MISO pin direction as input float */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MISO_PIN, OUTPUT);

	/* Enabling slave mode */
	SET_BIT(MSPI_SPCR, 6);
	
	/* Return from this function */
	return;
}

u8_t MSPI_SlaveRcvByte(void)
{
	/* Local Variable used in timing out operations */
	u16_t timeoutVar = 0;

	/* Waiting until data is received or timeout in 10ms */
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeoutVar < 10000)
	{
		/*Increase timeout variable*/
		timeoutVar++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}

	/* Return SPI master data */
	return MSPI_SPDR;
}