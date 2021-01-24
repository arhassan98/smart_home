/**************************************************************************/
/* Name:    MDIO_program.c                                                */
/* Author:  Ahmed Hassan                                                  */
/* Version: v1.0                                                          */
/* Description: This file contains DIO module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/
#include "LIB/LSTD_TYPES.h"
#include "LIB/LBIT_MATH.h"
#include "MCAL/MDIO/MDIO_interface.h"
#include "MCAL/MDIO/MDIO_private.h"

/************************************************************************/
/*                         Functions' Definitions                       */
/************************************************************************/

void MDIO_SetPinDirection(u8_t port, u8_t pin, u8_t pinDirection)
{
    static u8_t checkUsedArr[6] = {0};

    /* Switching over ports */
    switch (port) {
        /* In case of PORTA */
        case PORTA:
            /* Checking if the port is used before or not */
            if(checkUsedArr[0]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x01;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[0]++;

            /* Unlocking port */
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTA */
            GPIO_PORTA_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTA */
                    GPIO_PORTA_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTA */
                    GPIO_PORTA_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTA */
                    GPIO_PORTA_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTA */
                    GPIO_PORTA_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTA */
                    GPIO_PORTA_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTA */
                    GPIO_PORTA_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTA */
                    GPIO_PORTA_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTA */
            GPIO_PORTA_DEN_R |= pin;
            break;

        /* In case of PORTB */
        case PORTB:
            /* Checking if the port is used before or not */
            if(checkUsedArr[1]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x02;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[1]++;

            /* Unlocking port */
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTB */
            GPIO_PORTB_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTB */
                    GPIO_PORTB_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTB */
                    GPIO_PORTB_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTB */
                    GPIO_PORTB_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTB */
                    GPIO_PORTB_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTB */
                    GPIO_PORTB_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTB */
                    GPIO_PORTB_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTB */
                    GPIO_PORTB_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTB */
            GPIO_PORTB_DEN_R |= pin;
            break;

        /* In case of PORTC */
        case PORTC:
            /* Checking if the port is used before or not */
            if(checkUsedArr[2]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x04;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[2]++;

            /* Unlocking port */
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTC */
            GPIO_PORTC_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTC */
                    GPIO_PORTC_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTC */
                    GPIO_PORTC_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTC */
                    GPIO_PORTC_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTC */
                    GPIO_PORTC_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTC */
                    GPIO_PORTC_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTC */
                    GPIO_PORTC_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTC */
                    GPIO_PORTC_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTC */
            GPIO_PORTC_DEN_R |= pin;
            break;

        /* In case of PORTD */
        case PORTD:
            /* Checking if the port is used before or not */
            if(checkUsedArr[3]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x08;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[3]++;

            /* Unlocking port */
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTD */
            GPIO_PORTD_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTD */
                    GPIO_PORTD_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTD */
                    GPIO_PORTD_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTD */
                    GPIO_PORTD_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTD */
                    GPIO_PORTD_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTD */
                    GPIO_PORTD_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTD */
                    GPIO_PORTD_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTD */
                    GPIO_PORTD_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTD */
            GPIO_PORTD_DEN_R |= pin;
            break;

        /* In case of PORTE */
        case PORTE:
            /* Checking if the port is used before or not */
            if(checkUsedArr[4]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x10;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[4]++;

            /* Unlocking port */
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTE */
            GPIO_PORTE_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTE */
                    GPIO_PORTE_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTE */
                    GPIO_PORTE_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTE */
                    GPIO_PORTE_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTE */
                    GPIO_PORTE_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTE */
                    GPIO_PORTE_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTE */
                    GPIO_PORTE_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTE */
                    GPIO_PORTE_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTE */
            GPIO_PORTE_DEN_R |= pin;
            break;

        /* In case of PORTF */
        case PORTF:
            /* Checking if the port is used before or not */
            if(checkUsedArr[5]==0)
            {
            /* Enabling the clock of the port */
            SYSCTL_RCGCGPIO_R |= 0x20;

            /* Incrementing the variable to skip these steps in the next time */
            checkUsedArr[5]++;

            /* Unlocking port */
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            }

            /* Setting dedicated pins in CR register of PORTF */
            GPIO_PORTF_CR_R |= pin;

            /* Switching over pin directions */
            switch(pinDirection)
            {
                /* In case of OUTPUT direction */
                case OUTPUT:
                    /* Setting dedicated pins in DIR register of PORTF */
                    GPIO_PORTF_DIR_R |= pin;
                    break;

                /* In case of INPUT pull up direction */
                case INPUT_PULLUP:
                    /* Setting dedicated pins in PUR register of PORTF */
                    GPIO_PORTF_PUR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTF */
                    GPIO_PORTF_DIR_R &= ~pin;
                    break;

                /* In case of INPUT pull down direction */
                case INPUT_PULLDOWN:
                    /* Setting dedicated pins in PDR register of PORTF */
                    GPIO_PORTF_PDR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTF */
                    GPIO_PORTF_DIR_R &= ~pin;
                    break;

                /* In case of INPUT open drain direction */
                case INPUT_OPEN_DRAIN:
                    /* Setting dedicated pins in ODR register of PORTF */
                    GPIO_PORTF_ODR_R |= pin;

                    /* Clearing dedicated pins in DIR register of PORTF */
                    GPIO_PORTF_DIR_R &= ~pin;
                    break;
            }

            /* Setting dedicated pins in DEN register of PORTF */
            GPIO_PORTF_DEN_R |= pin;
            break;
    }
}

/* ==================================================================== */

void MDIO_SetPinValue(u8_t port, u8_t pin, u8_t pinValue)
{
    /* Switching over ports */
    switch (port)
    {
        /* In case of PORTA */
        case PORTA:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTA */
                    GPIO_PORTA_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTA */
                    GPIO_PORTA_DATA_R &= ~pin;
                    break;
            }
            break;

        /* In case of PORTB */
        case PORTB:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTB */
                    GPIO_PORTB_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTB */
                    GPIO_PORTB_DATA_R &= ~pin;
                    break;
            }
            break;

        /* In case of PORTC */
        case PORTC:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTC */
                    GPIO_PORTC_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTC */
                    GPIO_PORTC_DATA_R &= ~pin;
                    break;
            }
            break;

        /* In case of PORTD */
        case PORTD:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTD */
                    GPIO_PORTD_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTD */
                    GPIO_PORTD_DATA_R &= ~pin;
                    break;
            }
            break;

        /* In case of PORTE */
        case PORTE:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTE */
                    GPIO_PORTE_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTE */
                    GPIO_PORTE_DATA_R &= ~pin;
                    break;
            }
            break;

        /* In case of PORTF */
        case PORTF:

            /* Switching over pin values (HIGH/LOW) */
            switch(pinValue)
            {

                /* In case of HIGH value */
                case HIGH:
                    /* Setting dedicated pins in DATA register of PORTF */
                    GPIO_PORTF_DATA_R |= pin;
                    break;

                /* In case of LOW value */
                case LOW:
                    /* Clearing dedicated pins in DATA register of PORTF */
                    GPIO_PORTF_DATA_R &= ~pin;
                    break;
            }
            break;
    }
}

/*This function is responsible for getting a dedicated pin value*/
u8_t MDIO_GetPinValue(u8_t port, u8_t pin)
{
    /* Local variable used to get a dedicated pin value */
        u8_t pinValue = 0;

        /* Switching over DIO ports */
        switch(port)
        {
            /* In case of PORTA */
            case PORTA:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTA_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;

            /* In case of PORTB */
            case PORTB:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTB_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;

            /* In case of PORTC */
            case PORTC:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTC_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;

            /* In case of PORTD */
            case PORTD:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTD_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;
                /* In case of PORTE */
            case PORTE:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTE_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;
                /* In case of PORTF */
            case PORTF:
                /* Anding PIN register value with pin number */
                if(GPIO_PORTF_DATA_R & pin)
                {
                    /* If any other value than zero then pin value is HIGH */
                    pinValue = HIGH;
                }
                else
                {
                    /* If any other value than zero then pin value is LOW */
                    pinValue = LOW;
                }
                break;
        }

        /* Return the real value of the pin */
        return pinValue;
}


