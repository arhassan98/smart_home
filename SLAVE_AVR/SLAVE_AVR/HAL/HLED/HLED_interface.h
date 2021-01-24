/**************************************************************************/
/* Name:    HLED_interface.h                                              */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains interfacing information for LEDs       */
/**************************************************************************/

/* Header file guard */
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

/************************************************************************/
/*                            Interfacing Macros                        */
/************************************************************************/

/* LEDs Macros */
#define LED1              0
#define LED2              1

/* LEDs Ports and Pins */
#define LED1_PORT		  PORTA
#define LED2_PORT		  PORTA
#define LED1_PIN		  PIN0
#define LED2_PIN		  PIN1

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function is responsible for initializing LEDs as output */
void HLED_Init(void);

/* This function is responsible for setting LEDs to HIGH or LOW */
void HLED_Value(u8_t LED, u8_t value);

#endif /* HLED_INTERFACE_H_ */