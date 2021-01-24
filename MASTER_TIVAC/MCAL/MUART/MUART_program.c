/**************************************************************************/
/* Name:    MUART_program.c                                               */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains UART module logical program            */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include "MCAL/MDIO/MDIO_private.h"
#include "MCAL/MSysTick/MSysTick_interface.h"
#include "MUART_private.h"
#include "MUART_interface.h"


/************************************************************************/
/*                            Global variables                          */
/************************************************************************/
/* Global variable used in timing out operations */
u8_t timeoutVar = 0;

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void MUART1_Init(u16_t baudrate)
{
    /* Enabling clock for UART1 module */
    SET_BIT(SYSCTL_RCGCUART_R, 1);

    /* Enabling clock for PORTC */
    SET_BIT(SYSCTL_RCGCGPIO_R, 2);

    /* Disabling UART1 module before configuration */
    CLEAR_BIT(UART1_CTL_R, 0);

    /* Switching over baud rates */
    switch(baudrate)
    {
        /* In case of 2400 B/s */
        case MUART_2400_BPS:
            UART1_IBRD_R = MUART_2400_BPS;          // Integer Baud-Rate Divisor
            UART1_FBRD_R = MUART_2400_BPS_F;        // Fractional Baud-Rate Divisor
            break;

        /* In case of 4800 bps */
        case MUART_4800_BPS:
            UART1_IBRD_R = MUART_4800_BPS;          // Integer Baud-Rate Divisor
            UART1_FBRD_R = MUART_4800_BPS_F;        // Fractional Baud-Rate Divisor
            break;

        /* In case of 9600 bps */
        case MUART_9600_BPS:
            UART1_IBRD_R = MUART_9600_BPS;          // Integer Baud-Rate Divisor
            UART1_FBRD_R = MUART_9600_BPS_F;        // Fractional Baud-Rate Divisor
            break;

        /* In case of 19200 bps */
        case MUART_19200_BPS:
            UART1_IBRD_R = MUART_19200_BPS;         // Integer Baud-Rate Divisor
            UART1_FBRD_R = MUART_19200_BPS_F;       // Fractional Baud-Rate Divisor
            break;

        /* In case of 115200 bps */
        case MUART_115200_BPS:
            UART1_IBRD_R = MUART_115200_BPS;        // Integer Baud-Rate Divisor
            UART1_FBRD_R = MUART_115200_BPS_F;      // Fractional Baud-Rate Divisor
            break;
    }

    /* Selecting system clock for UART1 module */
    UART1_CC_R = 0;

    /* Disabling FIFOs and parity and enabling 8-bits word length with one stop bit */
    UART1_LCRH_R = 0x60;

    /* Enabling Rx and Tx */
    SET_BIT(UART1_CTL_R, 9);
    SET_BIT(UART1_CTL_R, 8);

    /* Disabling high speed */
    CLEAR_BIT(UART1_CTL_R, 5);

    /* Enabling UART1 module */
    SET_BIT(UART1_CTL_R, 0);

    /* Enabling alternate function for Rx and Tx pins in port */
    GPIO_PORTC_AFSEL_R |= 0x30;

    /* Configuring Rx and Tx pins for UART1 module */
    GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R & 0xFF00FFFF) + 0x00220000;

    /* Enabling digital IO for Rx and Tx pins */
    GPIO_PORTC_DEN_R |= 0x30;

    /* Disabling analog IO for Rx and Tx pins */
    GPIO_PORTC_AMSEL_R &= ~0x30;


	/* Return from this function */
	return;
}

void MUART1_SendByte(u8_t data)
{	
	/* Reset timeout variable */
	timeoutVar = 0;

    /* Waiting until Tx buffer will being empty or timeout happens */
    while(GET_BIT(UART1_FR_R, 5) && timeoutVar < 10000)
    {
        /* Increasing timeout variable */
        timeoutVar++;

        /* Delaying for 1us */
        _delay_us(1);
    }

    /* Transmitting data over Tx pin */
    UART1_DR_R = data;
	
	/* Return from this function */
	return;
}

void MUART1_RecvByte(u8_t* data)
{
    /* Reset timeout variable */
    timeoutVar = 0;

    /* Waiting until Rx buffer will being empty or timeout happens */
    while(GET_BIT(UART1_FR_R, 4) && timeoutVar < 10000)
    {
        /* Increasing timeout variable */
        timeoutVar++;

        /* Delaying for 1us */
        _delay_us(1);
    }

    /* Receiving data over Rx pin */
    *data = UART1_DR_R;

    /* Return from this function */
    return;
}
