#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "STD_TYPES.h"

#define MDIO_PORTA      0
#define MDIO_PORTB      1
#define MDIO_PORTC      2
#define MDIO_PORTD      3

#define MDIO_INPUT      0
#define MDIO_OUTPUT     1

#define MDIO_LOW        0
#define MDIO_HIGH       1


void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Direction);
void MDIO_voidSetPinValueOrPullup(u8 Copy_u8Port, u8 Copy_u8Pin,u8 u8Value);
u8 MDIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);
void MDIO_voidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);
void MDIO_voidSetPortValues(u8 Copy_u8Port,u8 u8Value);

#endif
