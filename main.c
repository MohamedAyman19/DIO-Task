/*
 * DIO_driver.c
 *
 * Created: 22-Jul-21 4:05:55 PM
 * Author : ayman
 */ 

#define F_CPU 8000000UL
#include"Macros.h"
#include"TypeDef.h"
#include"DIO_Int.h"
int main(void)
{
	DIO_sint8_tSetPortDirection(PortA,PORT_OUTPUT);
	DIO_sint8_tSetPortDirection(PortC,PORT_INPUT);

    /* Replace with your application code */
    while (1) 
    {
		if(DIO_sint8_t_tGetPinValue(PortC,PIN0)==PIN_HIGH)
		{
			for(uint32_t i=0;i<72000;i++); ///                           for debouncing 
			if(DIO_sint8_t_tGetPinValue(PortC,0)==PIN_HIGH)
			{
				DIO_sint8_tTogglePin(PortA,PIN0);
				while(DIO_sint8_t_tGetPinValue(PortC,PIN0)==1);
			}

		}
		
			
    }
}

