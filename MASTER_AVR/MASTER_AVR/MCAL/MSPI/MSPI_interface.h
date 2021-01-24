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

/* SPI Data Mode */
#define MSPI_SAMPLE_R_SETUP_F  (0)
#define MSPI_SETUP_R_SAMPLE_F  (1)
#define MSPI_SAMPLE_F_SETUP_R  (2)
#define MSPI_SETUP_F_SAMPLE_R  (3)

/* SPI Clock Prescaler */
#define MSPI_PRE_2             (0)
#define MSPI_PRE_4             (1)
#define MSPI_PRE_8             (2)
#define MSPI_PRE_16            (3)
#define MSPI_PRE_32            (4)
#define MSPI_PRE_64            (5)
#define MSPI_PRE_128           (7)

/************************************************************************/
/*                          Functions' prototypes                       */
/************************************************************************/

/* This function is responsible for initializing SPI peripheral as a master */
void MSPI_MasterInit(u8_t data_mode, u8_t clk_prescaler);

/* This function is responsible for sending data over or from SPI bus */
void MSPI_MasterSendByte(u8_t data);

#endif /* MSPI_INTERFACE_H_ */