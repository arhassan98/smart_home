/**************************************************************************/
/* Name:    MSPI_program.c                                                */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains SPI module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MDIO/MDIO_private.h"
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void MSPI1_MasterInit(u8_t clkPrescaler)
{
    /* Enabling clock to SPI1 */
    SET_BIT(SYSCTL_RCGCSSI_R, 1);

    /* Enabling clock to PORTD */
    SET_BIT(SYSCTL_RCGCGPIO_R, 3);

    /* Enabling clock to PORTF for SS */
    SET_BIT(SYSCTL_RCGCGPIO_R, 5);

    /* Disabling analog function for clock (CLK), Rx and Tx at pins 0, 2 and 3 in PORTD respectively */
    GPIO_PORTD_AMSEL_R &= ~0x0D;

    /* Enabling digital function for clock (CLK), Rx and Tx */
    GPIO_PORTD_DEN_R |= 0x0D;

    /* Enabling alternate function for clock (CLK), Rx and Tx */
    GPIO_PORTD_AFSEL_R |= 0x0D;

    /* Selecting SPI module for pins */
    GPIO_PORTD_PCTL_R &= ~0x0000FF0F;
    GPIO_PORTD_PCTL_R |= 0x00002202;

    /* Setting PIN3 in PORTF as SS with digital output and keeping it high */
    SET_BIT(GPIO_PORTF_DEN_R, 3);
    SET_BIT(GPIO_PORTF_DIR_R, 3);
    SET_BIT(GPIO_PORTF_DATA_R, 3);

    /* Selecting SPI as a master with POL = 0, PHA = 0, clock = 4MH and 8-bits length */
    /* Disabling SPI */
    SSI1_CR1_R = 0;

    /* Enabling system clock */
    SSI1_CC_R = 0;

    /* Selecting prescaler */
    SSI1_CPSR_R = clkPrescaler;

    /* Selecting 8 bit data */
    SSI1_CR0_R = 0x00007;

    /* Enabling SPI */
    SET_BIT(SSI1_CR1_R, 1);
	
	/* Return from this function */
	return;
}

void MSPI1_MasterSendByte(u8_t data)
{
    /* Local variable used to save the data received from slave */
    u8_t flushBuffer = 0;

    /* Variable used in timing out operations */
    u16_t timeout_var = 0;

    /* Setting SS to low */
    CLEAR_BIT(GPIO_PORTF_DATA_R, 3);

    /* Waiting until Tx FIFO is not full or timeout in 10ms */
    while((GET_BIT(SSI1_SR_R, 2) == 0) && timeout_var < 10000)
    {
        /*Increase timeout variable*/
        timeout_var++;

        /*Delay for 1us*/
        _delay_us(1);
    }

    /* Reseting time out variable */
    timeout_var = 0;

    /* Transmitting data over Tx line */
    SSI1_DR_R = data;

    /* Waiting until data will be transmitted or timeout in 10ms */
    while((GET_BIT(SSI1_SR_R, 4)) && timeout_var < 10000)
    {
        /*Increase timeout variable*/
        timeout_var++;

        /* Delaying for 1us */
        _delay_us(1);
    }

    /* Setting SS to high */
    SET_BIT(GPIO_PORTF_DATA_R, 3);

    /* Saving the data received from slave */
    flushBuffer = SSI1_DR_R;

	/* Return from this function */
	return;
}
