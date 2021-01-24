/************************************************************************/
/* Name:    MSPI_private.h                                              */
/* Author:  Ahmed Hassan                                                */
/* Version: v1.0                                                        */
/* Description: This file contains private information for SPI module   */
/************************************************************************/

/*Header file guard*/
#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LSTD_TYPES.h"

/************************************************************************/
/*                            SSI Registers                             */
/************************************************************************/

#define SYSCTL_RCGCSSI_R        (*((volatile u32_t *)0x400FE61C))
#define SSI1_CR0_R              (*((volatile u32_t *)0x40009000))
#define SSI1_CR1_R              (*((volatile u32_t *)0x40009004))
#define SSI1_DR_R               (*((volatile u32_t *)0x40009008))
#define SSI1_SR_R               (*((volatile u32_t *)0x4000900C))
#define SSI1_CPSR_R             (*((volatile u32_t *)0x40009010))
#define SSI1_CC_R               (*((volatile u32_t *)0x40009FC8))

#endif /* MSPI_PRIVATE_H_ */
