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
/*                            Interfacing macros                        */
/************************************************************************/
/* SPI Port and Pins */
#define MSPI_PORT			PORTB
#define MSPI_SS_PIN			PIN4
#define MSPI_MOSI_PIN		PIN5
#define MSPI_MISO_PIN		PIN6
#define MSPI_SCK_PIN		PIN7

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function is responsible for initializing SPI peripheral as a slave */
void MSPI_SlaveInit(void);

/* This function is responsible for getting data over or from SPI bus */
u8_t MSPI_SlaveRcvByte(void);


#endif /* MSPI_INTERFACE_H_ */