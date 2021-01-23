/**************************************************************************/
/* Name:    MDIO_interface.h                                              */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains interfacing information for DIO module */
/**************************************************************************/

/*Header file guard*/
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/************************************************************************/
/*                            Interfacing Macros                        */
/************************************************************************/

/* DIO Ports */
#define PORTA         0
#define PORTB         1
#define PORTC         2
#define PORTD         3

/* Port Pins */
#define PIN0          0x01 /*0b00000001*/
#define PIN1          0x02 /*0b00000010*/
#define PIN2          0x04 /*0b00000100*/
#define PIN3          0x08 /*0b00001000*/
#define PIN4          0x10 /*0b00010000*/
#define PIN5          0x20 /*0b00100000*/
#define PIN6          0x40 /*0b01000000*/
#define PIN7          0x80 /*0b10000000*/

/* Pin Status */
#define OUTPUT        0
#define INPUT_FLOAT   1
#define INPUT_PULLUP  2

/* Pin Output Value */
#define LOW           0
#define HIGH          1

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function is responsible for setting the status a pin or pins for a dedicated port */
void MDIO_SetPinDirection(u8_t port, u8_t pin, u8_t pinDirection);

/* This function is responsible for setting a dedicated value for a pin or pins */
void MDIO_SetPinValue(u8_t port, u8_t pin, u8_t pinValue);

/* This function is responsible for toggling a dedicated pin or pins values */
void MDIO_TogglePinValue(u8_t port, u8_t pin);

/* This function is responsible for getting a dedicated pin value */
u8_t MDIO_GetPinValue(u8_t port, u8_t pin);

#endif /* MDIO_INTERFACE_H_ */