/**************************************************************************/
/* Name:    MDIO_program.c                                                */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains DIO module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void MDIO_SetPinDirection(u8_t port, u8_t pin, u8_t pinDirection)
{
	/* Switching over DIO ports */
	switch(port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Switching over pin directions */
			switch(pinDirection)
			{
				/* In case of output direction */
				case OUTPUT:
					/* Setting dedicated pins in DDR register */
					MDIO_DDRA |= pin;
					break;
				
				/* In case of input direction */
				case INPUT_FLOAT:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRA &= ~pin;
					break;

				/* In case of input pull-up direction */					
				case INPUT_PULLUP:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRA &= ~pin;
					
					/* Setting dedicated pins in DDR register */
					MDIO_PORTA |= pin;
					break;
			}
			break;

		/* In case of PORTB */
		case PORTB:
			/* Switching over pin directions */
			switch(pinDirection)
			{
				/* In case of output direction */
				case OUTPUT:
					/* Setting dedicated pins in DDR register */
					MDIO_DDRB |= pin;
					break;
				
				/* In case of input direction */
				case INPUT_FLOAT:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRB &= ~pin;
					break;

				/* In case of input pull-up direction */					
				case INPUT_PULLUP:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRB &= ~pin;
					
					/* Setting dedicated pins in DDR register */
					MDIO_PORTB |= pin;
					break;
			}
			break;

		/* In case of PORTC */
		case PORTC:
			/* Switching over pin directions */
			switch(pinDirection)
			{
				/* In case of output direction */
				case OUTPUT:
					/* Setting dedicated pins in DDR register */
					MDIO_DDRC |= pin;
					break;
				
				/* In case of input direction */
				case INPUT_FLOAT:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRC &= ~pin;
					break;

				/* In case of input pull-up direction */					
				case INPUT_PULLUP:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRC &= ~pin;
					
					/* Setting dedicated pins in DDR register */
					MDIO_PORTC |= pin;
					break;
			}
			break;

		/* In case of PORTD */
		case PORTD:
			/* Switching over pin directions */
			switch(pinDirection)
			{
				/* In case of output direction */
				case OUTPUT:
					/* Setting dedicated pins in DDR register */
					MDIO_DDRD |= pin;
					break;
				
				/* In case of input direction */
				case INPUT_FLOAT:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRD &= ~pin;
					break;

				/* In case of input pull-up direction */					
				case INPUT_PULLUP:
					/* Clearing dedicated pins in DDR register */
					MDIO_DDRD &= ~pin;
					
					/* Setting dedicated pins in DDR register */
					MDIO_PORTD |= pin;
					break;
			}
			break;
	}
	
	/* Return from this function */
	return;
}

void MDIO_SetPinValue(u8_t port, u8_t pin, u8_t pinValue)
{
	/* Switching over DIO ports */
	switch(port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Switching over pin values */
			switch(pinValue)
			{
				/* In case of HIGH value */
				case HIGH:
					/* Setting dedicated pins in PORTA register */
					MDIO_PORTA |= pin;
					break;
				
				/* In case of LOW value */
				case LOW:
					/* Clearing dedicated pins in PORTA register */
					MDIO_PORTA &= ~pin;
					break;
			}
			break;

		/* In case of PORTB */
		case PORTB:
			/* Switching over pin values */
			switch(pinValue)
			{
				/* In case of HIGH value */
				case HIGH:
					/* Setting dedicated pins in PORTB register */
					MDIO_PORTB |= pin;
					break;
				
				/* In case of LOW value */
				case LOW:
					/* Clearing dedicated pins in PORTB register */
					MDIO_PORTB &= ~pin;
					break;
			}
			break;

		/* In case of PORTC */
		case PORTC:
			/* Switching over pin values */
			switch(pinValue)
			{
				/* In case of HIGH value */
				case HIGH:
					/* Setting dedicated pins in PORTC register */
					MDIO_PORTC |= pin;
					break;
				
				/* In case of LOW value */
				case LOW:
					/* Clearing dedicated pins in PORTC register */
					MDIO_PORTC &= ~pin;
					break;
			}
			break;

		/* In case of PORTD */
		case PORTD:
			/* Switching over pin values */
			switch(pinValue)
			{
				/* In case of HIGH value */
				case HIGH:
					/* Setting dedicated pins in PORTD register */
					MDIO_PORTD |= pin;
					break;
				
				/* In case of LOW value */
				case LOW:
					/* Clearing dedicated pins in PORTD register */
					MDIO_PORTD &= ~pin;
					break;
			}
			break;
	}
	
	/* Return from this function */
	return;
}

void MDIO_TogglePinValue(u8_t port, u8_t pin)
{
	/* Switching over DIO ports */
	switch(port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Toggling dedicated pins values */
			MDIO_PORTA ^= pin;
			break;

		/* In case of PORTB */
		case PORTB:
			/* Toggling dedicated pins values */
			MDIO_PORTB ^= pin;
			break;

		/* In case of PORTC */
		case PORTC:
			/* Toggling dedicated pins values */
			MDIO_PORTC ^= pin;
			break;

		/* In case of PORTD */
		case PORTD:
			/* Toggling dedicated pins values */
			MDIO_PORTD ^= pin;
			break;
	}
	
	/* Return from this function */
	return;	
}

u8_t MDIO_GetPinValue(u8_t port, u8_t pin)
{
	/* Local variable used to get a dedicated pin value */
	u8_t pinValue = 0;
	
	/* Switching over DIO ports */
	switch(port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Anding PIN register value with pin number */
			if(MDIO_PINA & pin)
			{
				/* If any other value than zero then pin value is HIGH */
				pinValue = HIGH;
			}
			else
			{
				/* If any other value than zero then pin value is LOW */
				pinValue = LOW;
			}
			break;

		/* In case of PORTB */
		case PORTB:
			/* Anding PIN register value with pin number */
			if(MDIO_PINB & pin)
			{
				/* If any other value than zero then pin value is HIGH */
				pinValue = HIGH;
			}
			else
			{
				/* If any other value than zero then pin value is LOW */
				pinValue = LOW;
			}
			break;

		/* In case of PORTC */
		case PORTC:
			/* Anding PIN register value with pin number */
			if(MDIO_PINC & pin)
			{
				/* If any other value than zero then pin value is HIGH */
				pinValue = HIGH;
			}
			else
			{
				/* If any other value than zero then pin value is LOW */
				pinValue = LOW;
			}
			break;

		/* In case of PORTD */
		case PORTD:
			/* Anding PIN register value with pin number */
			if(MDIO_PIND & pin)
			{
				/* If any other value than zero then pin value is HIGH */
				pinValue = HIGH;
			}
			else
			{
				/* If any other value than zero then pin value is LOW */
				pinValue = LOW;
			}
			break;
	}
	
	/* Return the real value of the pin */
	return pinValue;
}