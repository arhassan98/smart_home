/*
 * HBLUETOOTH_interface.h
 *
 * Created: 1/23/2021 11:35:03 PM
 *  Author: ahmed
 */ 


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