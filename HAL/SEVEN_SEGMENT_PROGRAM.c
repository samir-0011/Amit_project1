#include"STD_TYPES.h"
#include"DIO_I.h"
#include<util/delay.h>


void _7_SEGMENT_INIT(void)
{

	/*Initialization 7_Segment*/
	DIO_u8SetPinDirection(DIO_PIN4,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PIN5,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PIN6,DIO_PORTA,PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PIN7,DIO_PORTA,PIN_OUTPUT);

	/*(Enable_1)E1  7_Segment*/
	DIO_u8SetPinDirection(DIO_PIN1,DIO_PORTB,PIN_OUTPUT);

	/*(Enable_2)E2  7_Segment*/
	DIO_u8SetPinDirection(DIO_PIN3,DIO_PORTB,PIN_OUTPUT);

}

void _7_SEGMENT_READ(u8 Data)
{

	/*Divide the Data to show on E1 and E2 7_Segment*/
	u8 ten = Data/10;
	u8 one = Data%10;

	for(u8 i=0;i<2;i++)
	{

		if(i==0)
		{
			/*Show The Data on E2 7_Segment*/
			DIO_u8SetPinValue(DIO_PIN3,DIO_PORTB,PIN_HIGH);
			DIO_u8Set4MSB_BitsValue(DIO_PORTA,one);
			_delay_ms(5);
			DIO_u8SetPinValue(DIO_PIN3,DIO_PORTB,PIN_LOW);
		}
		else
		{
			/*Show The Data on E1 7_Segment*/
			DIO_u8SetPinValue(DIO_PIN1,DIO_PORTB,PIN_HIGH);
			DIO_u8Set4MSB_BitsValue(DIO_PORTA,ten);
			_delay_ms(5);
			DIO_u8SetPinValue(DIO_PIN1,DIO_PORTB,PIN_LOW);
		}

	}

}
