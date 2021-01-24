/**************************************************************************/
/* Name:    MSPI_interface.h                                              */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains interfacing information for SPI module */
/**************************************************************************/

/*Header file guard*/
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/************************************************************************/
/*                            Interfacing Macros                        */
/************************************************************************/
 
/* SPI Clock Prescaler */
#define MSPI_PRE_2             (2)
#define MSPI_PRE_4             (4)
#define MSPI_PRE_8             (8)
#define MSPI_PRE_16            (16)
#define MSPI_PRE_32            (32)
#define MSPI_PRE_64            (64)
#define MSPI_PRE_128           (128)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function is responsible for initializing SPI peripheral as master*/
void MSPI1_MasterInit(u8_t clkPrescaler);

/* This function is responsible for sending data over SPI bus */
void MSPI1_MasterSendByte(u8_t data);

#endif /* MSPI_INTERFACE_H_ */
