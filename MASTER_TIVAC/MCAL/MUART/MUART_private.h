/************************************************************************/
/* Name:    MUART_private.h                                             */
/* Author:  Ahmed Hassan                                                */
/* Version: v1.0                                                        */
/* Description: This file contains private information for UART module  */
/************************************************************************/

/* Header file guard */
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LSTD_TYPES.h"

/************************************************************************/
/*                            UART1 Registers                           */
/************************************************************************/
#define SYSCTL_RCGCUART_R       (*((volatile u32_t *)0x400FE618))
#define UART1_DR_R              (*((volatile u32_t *)0x4000D000))
#define UART1_FR_R              (*((volatile u32_t *)0x4000D018))
#define UART1_IBRD_R            (*((volatile u32_t *)0x4000D024))
#define UART1_FBRD_R            (*((volatile u32_t *)0x4000D028))
#define UART1_LCRH_R            (*((volatile u32_t *)0x4000D02C))
#define UART1_CTL_R             (*((volatile u32_t *)0x4000D030))
#define UART1_CC_R              (*((volatile u32_t *)0x4000DFC8))

#endif /* UART_PRIVATE_H_ */
