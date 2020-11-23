#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


u8 MDIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
     if ( Copy_u8Pin > 7)
        return;
     switch(Copy_u8Port)
    {
        case MDIO_PORTA:
            return GET_BIT(PORTA,Copy_u8Pin);
        break;
        case MDIO_PORTB:
           return GET_BIT(PORTB,Copy_u8Pin);
        break;
        case MDIO_PORTC:
           return GET_BIT(PORTC,Copy_u8Pin);
        break;
        case MDIO_PORTD:
           return GET_BIT(PORTD,Copy_u8Pin);
        break;
        default:
        break;
        }
}

void MDIO_voidSetPortValues(u8 Copy_u8Port,u8 u8Value){

}



void MDIO_voidSetPortDirection(u8 Copy_u8Port,Copy_u8Direction){
    switch(Copy_u8Port)
    {
        case MDIO_PORTA:
            DDRA = Copy_u8Direction; 
        break;
        case MDIO_PORTB:
           DDRB = Copy_u8Direction;
        break;
        case MDIO_PORTC:
           DDRC = Copy_u8Direction;
        break;
        case MDIO_PORTD:
           DDRD = Copy_u8Direction;
        break;
        default:
        break;
        }
}
void MDIO_voidSetPinValueOrPullup(u8 Copy_u8Port, u8 Copy_u8Pin,u8 u8Value,u8 v/p)
{
     if ( Copy_u8Pin > 7 || u8Value > 1)
        return;
    switch(Copy_u8Port)
    {
        case MDIO_PORTA:
            if (u8Value == MDIO_HIGH)
                SET_BIT(PORTA,Copy_u8Pin);
            else
                CLR_BIT(PORTA,Copy_u8Pin);
        break;
        case MDIO_PORTB:
           if (u8Value == MDIO_HIGH)
                SET_BIT(PORTB,Copy_u8Pin);
            else
                CLR_BIT(PORTB,Copy_u8Pin);
        break;
        case MDIO_PORTC:
           if (u8Value == MDIO_HIGH)
                SET_BIT(PORTC,Copy_u8Pin);
            else
                CLR_BIT(PORTC,Copy_u8Pin);
        break;
        case MDIO_PORTD:
           if (u8Value == MDIO_HIGH)
                SET_BIT(PORTD,Copy_u8Pin);
            else
                CLR_BIT(PORTD,Copy_u8Pin);
        break;
        default:
        break;
        }
        
}

void MDIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Direction)
{
    if (Copy_u8Pin > 7 || Copy_u8Direction > 1)
        return;
    switch(Copy_u8Port)
    {
        case MDIO_PORTA:
            if (Copy_u8Direction == MDIO_OUTPUT)
                SET_BIT(DDRA,Copy_u8Pin);
            else
                CLR_BIT(DDRA,Copy_u8Pin);
        break;
        case MDIO_PORTB:
            if (Copy_u8Direction == MDIO_OUTPUT)
                SET_BIT(DDRB,Copy_u8Pin);
            else
                CLR_BIT(DDRB,Copy_u8Pin);
        break;
        case MDIO_PORTC:
            if (Copy_u8Direction == MDIO_OUTPUT)
                SET_BIT(DDRC,Copy_u8Pin);
            else
                CLR_BIT(DDRC,Copy_u8Pin);
        break;
        case MDIO_PORTD:
            if (Copy_u8Direction == MDIO_OUTPUT)
                SET_BIT(DDRD,Copy_u8Pin);
            else
                CLR_BIT(DDRD,Copy_u8Pin);
        break;
        default:
        break;
        
    }
}
