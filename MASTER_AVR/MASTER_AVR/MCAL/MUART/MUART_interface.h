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

#define MUART_2400_BPS		(416)
#define MUART_4800_BPS		(207)
#define MUART_9600_BPS		(103)
#define MUART_19200_BPS		(51)
#define MUART_115200_BPS	(8)

/************************************************************************/
/*                          Functions' Prototypes                       */
/************************************************************************/

/* This function is responsible for initializing UART module */
void MUART_Init(u16_t baudrate);

/* This function is responsible for sending byte over UART data bus */
void MUART_SendByte(u8_t data);

/* This function is responsible for receiving byte from UART data bus */
void MUART_RecvByte(u8_t* data);

/* This function is responsible for sending stream of data over UART data bus */
void MUART_SendStream(u8_t* dataStream, u8_t dataSize);

#endif /* UART_INTERFACE_H_ */