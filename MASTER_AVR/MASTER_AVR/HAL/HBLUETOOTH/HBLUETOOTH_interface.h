/********************************************************************************/
/* Name:    HBLUETOOTH_interface.h                                              */
/* Author:  Ahmed Hassan                                                        */
/* Version: v1.0															    */
/* Description: This file contains interfacing information for bluetooth module */
/********************************************************************************/

/* Header file guard */
#ifndef HBLUETOOTH_INTERFACE_H_
#define HBLUETOOTH_INTERFACE_H_

/************************************************************************/
/*                          Function prototype                          */
/************************************************************************/
/* This function is responsible for initializing bluetooth module */
void HBLUETOOTH_Init(void);

/* This function is responsible for receiving data from UART module */
u8_t HBLUETOOTH_RcvData(void);

#endif /* HBLUETOOTH_INTERFACE_H_ */