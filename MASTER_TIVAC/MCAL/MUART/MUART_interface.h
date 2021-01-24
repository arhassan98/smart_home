/***************************************************************************/
/* Name:    MUART_interface.h                                              */
/* Author:  Ahmed Hassan                                                   */
/* Version: v1.0                                                           */
/* Description: This file contains interfacing information for UART module */
/***************************************************************************/

/* Header file guard */
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/************************************************************************/
/*                            Interfacing Macros                        */
/************************************************************************/

/* Integer Baud Rates */
#define MUART_2400_BPS		    (416)
#define MUART_4800_BPS		    (208)
#define MUART_9600_BPS		    (104)
#define MUART_19200_BPS		    (52)
#define MUART_115200_BPS	    (8)

/* Float Baud Rates */
#define MUART_2400_BPS_F        (43)
#define MUART_4800_BPS_F        (21)
#define MUART_9600_BPS_F        (11)
#define MUART_19200_BPS_F       (5)
#define MUART_115200_BPS_F      (44)

/* UART Modules */
#define MUART0      0
#define MUART1      1
#define MUART2      2
#define MUART3      3
#define MUART4      4
#define MUART5      5
#define MUART6      6
#define MUART7      7


/************************************************************************/
/*                          Functions' Prototypes                       */
/************************************************************************/

/* This function is responsible for initializing UART1 module */
void MUART1_Init(u16_t baudrate);

/* This function is responsible for sending byte over UART1 data bus */
void MUART1_SendByte(u8_t data);

/* This function is responsible for receiving byte from UART1 data bus */
void MUART1_RecvByte(u8_t* data);

#endif /* UART_INTERFACE_H_ */
