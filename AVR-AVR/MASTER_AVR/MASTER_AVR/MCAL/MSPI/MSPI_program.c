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

void MSPI_MasterInit()
{
	/* Setting MOSI, SCK and SS pins directions as output */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MOSI_PIN|MSPI_SCK_PIN|MSPI_SS_PIN, OUTPUT);
	
	/* Setting MISO pin direction as input float */
	MDIO_SetPinDirection(MSPI_PORT, MSPI_MISO_PIN, INPUT_FLOAT);

	/* Setting SS pin to HIGH value */
	MDIO_SetPinValue(MSPI_PORT, MSPI_SS_PIN, HIGH);
	
	/*Enable master mode with Fosc/16*/
	MSPI_SPCR = 0x51;
	
	/* Disabling speed doubler */
	 CLEAR_BIT(MSPI_SPSR, 0);
	 
	/* Return from this function */
	return;
}

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

void MSPI_SendByte(u8_t data)
{
	u8_t flushBuffer = 0;
	
	/* Variable used in timing out operations */
	u16_t timeoutVar = 0;
	
	/* Send master data */
	MSPI_SPDR = data;
	
	/* Wait until data is transmitted or timeout in 10ms */
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeoutVar < 10000)
	{
		/*Increase timeout variable*/
		timeoutVar++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}
	
	flushBuffer = MSPI_SPDR;
	
	/*Return SPI master/slave data*/
	return;
}

void MSPI_SendStream(u8_t* data, u8_t dataSize)
{	
	/*A variable used in looping operations*/
	u8_t loopingVar = 0;
	
	/*Sending data stream*/
	for(loopingVar = 0 ; loopingVar < dataSize ; loopingVar++)
	{
		MSPI_SendByte(data[loopingVar]);
	}
	
	/*Return from this function*/
	return;	
}

u8_t MSPI_RcvByte()
{
	/*Variable used in timing out operations*/
	u16_t timeoutVar = 0;
	
	/* Dummy data to SPDR */
	MSPI_SPDR = 0xFF;
	
	/*Wait until data is received or timeout in 10ms*/
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeoutVar < 10000)
	{
		/*Increase timeout variable*/
		timeoutVar++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}
	
	/*Return SPI master/slave data*/
	return MSPI_SPDR;
}

u8_t MSPI_SlaveRcvByte()
{
	/*Variable used in timing out operations*/
	u16_t timeoutVar = 0;
	
	/*Wait until data is received or timeout in 10ms*/
	while( (GET_BIT(MSPI_SPSR, 7) == 0) && timeoutVar < 10000)
	{
		/*Increase timeout variable*/
		timeoutVar++;
		
		/*Delay for 1us*/
		_delay_us(1);
	}
	
	/*Return SPI master/slave data*/
	return MSPI_SPDR;
}