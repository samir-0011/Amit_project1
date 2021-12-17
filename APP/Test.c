#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_I.h"
#include"ADC_Interface.h"
#include"SEVEN_SEGMENT_INTERFACE.h"
#include"EEPROM_Interface.h"
#include"Timer_Interface.h"
#include"TIMER2_Interface.h"
#include"GIE_Interface.h"
#include"EXTI_Interface.h"
#include"Timer_Config.h"
#include"TIMER2_Config.h"



u8 Turn_Bottom = 0;
u8 UP_Heater_Bottom = 0;
u8 DOWN_Cooling_Bottom = 0;
u8 SET_Temperature = 60;
u16 Temperature = 0;
u32 Seven_Segment_Flag = 0;
u8 Tnterrupt_Flag = 5;
u8 LED_Flag = 0;
u8 LED_Count = 0;

u16 ADC_Temperature()

{
	u16 ADC_Digital;
	u16 ADC_Analog ;
	unsigned int average = 0;
	static unsigned char i = 0;
	static unsigned int Temperatuer_Value[10]={0};
	ADC_Digital=ADC_u16StartConversion(0);
	ADC_Analog = (ADC_Digital*5000UL) /1024;
	ADC_Analog/=10;
	Temperatuer_Value[i]=ADC_Analog;
	if(i==9)
	{
		i=0;
	}
	else
	{
		i++;
	}
	for(unsigned char j=0 ; j<10 ; j++)
	{
		average+=Temperatuer_Value[j];
	}
	average/=10;

	return average;
}


int main(void)

{
	/* Bottom of Turn */
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTD,PIN_INPUT);
	DIO_u8SetPinValue(DIO_PIN2,DIO_PORTD,PIN_HIGH);
	/* Bottom of Heater (UP) */
	DIO_u8SetPinDirection(DIO_PIN3,DIO_PORTD,PIN_INPUT);
	DIO_u8SetPinValue(DIO_PIN3,DIO_PORTD,PIN_HIGH);
	/* Bottom of Cooler (DOWN)*/
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTB,PIN_INPUT);
	DIO_u8SetPinValue(DIO_PIN2,DIO_PORTB,PIN_HIGH);

	DIO_u8SetPinDirection(DIO_PIN1,DIO_PORTC,PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PIN3,DIO_PORTC,PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PIN4,DIO_PORTC,PIN_OUTPUT);

	/* Record of EEPROM */
	u8 SET_TEMP=0;
	SET_TEMP=EEPROM_read(0);
	if(SET_TEMP!=0xFF)
	{
		Temperature=SET_TEMP;
	}

	ADC_voidInit();
	_7_SEGMENT_INIT();

	EXTI_voidINT0_Init();
	EXTI_voidINT1_Init();
	EXTI_voidINT2_Init();

	TIMER0_voidInit();
	TIMER2_voidInit();

	GIE_voidEnable();

	TIMER0_voidSetPreloadValue(TIMER0_PRELOAD);
	TIMER2_voidSetPreloadValue(TIMER2_PRELOAD);

	while (1)
	{
		if(Turn_Bottom==0)
		{
			/* Turn off Display */
			DIO_u8SetPinValue(DIO_PIN4,DIO_PORTC,PIN_LOW);
			DIO_u8SetPinValue(DIO_PIN3,DIO_PORTC,PIN_LOW);
			DIO_u8SetPinValue(DIO_PIN1,DIO_PORTC,PIN_LOW);
			/* Turn of 7_Segment */
			DIO_u8SetPinValue(DIO_PIN1,DIO_PORTB,PIN_LOW);
			DIO_u8SetPinValue(DIO_PIN3,DIO_PORTB,PIN_LOW);
		}
		else
		{
			if(Tnterrupt_Flag>5)
			{
				DIO_u8SetPinValue(DIO_PIN4,DIO_PORTC,PIN_LOW);
				DIO_u8SetPinValue(DIO_PIN3,DIO_PORTC,PIN_LOW);
				DIO_u8SetPinValue(DIO_PIN1,DIO_PORTC,PIN_LOW);

				if(LED_Flag == 0)
				{

					_7_SEGMENT_READ(SET_Temperature);
				}
				else
				{
					/* Nothing */
				}

				if(Tnterrupt_Flag>6)
				{

					/*BOTTOM 2 (UP_Heater_Bottom)*/
					if(UP_Heater_Bottom==1 )
					{
						if (SET_Temperature!=75)
						{
							SET_Temperature+=5;
						}
						UP_Heater_Bottom=0;
					}
					/*BOTTOM 3 (DOWN_Heater_Bottom)*/
					if (DOWN_Cooling_Bottom==1)
					{
						if(SET_Temperature!=35)
						{
							SET_Temperature-=5;
						}
						DOWN_Cooling_Bottom=0;
					}
					EEPROM_write(0,SET_Temperature);
				}
			}
			else
			{
				Tnterrupt_Flag = 5;
				Seven_Segment_Flag = 0;
				Temperature = ADC_Temperature();
				_7_SEGMENT_READ(Temperature);

				if (SET_Temperature<=(Temperature-5))
				{

					DIO_u8SetPinValue(DIO_PIN4,DIO_PORTC,PIN_LOW);
					DIO_u8SetPinValue(DIO_PIN3,DIO_PORTC,PIN_HIGH);
					DIO_u8SetPinValue(DIO_PIN1,DIO_PORTC,PIN_HIGH);
				}
				if (SET_Temperature>=(Temperature+5))
				{
					DIO_u8SetPinValue(DIO_PIN3,DIO_PORTC,PIN_LOW);
					DIO_u8SetPinValue(DIO_PIN4,DIO_PORTC,PIN_HIGH);

					if(LED_Flag==0)
					{
						DIO_u8SetPinValue(DIO_PIN1,DIO_PORTC,PIN_HIGH);
					}
					else
					{
						DIO_u8SetPinValue(DIO_PIN1,DIO_PORTC,PIN_LOW);
					}
				}
			}
		}
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(Turn_Bottom==0)
	{
		Turn_Bottom = 1;
	}
	else
	{
		Turn_Bottom = 0;
	}
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	UP_Heater_Bottom = 1;
	Tnterrupt_Flag++;
	Seven_Segment_Flag = 0;
	LED_Flag = 0;
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	DOWN_Cooling_Bottom = 1;
	Tnterrupt_Flag++;
	Seven_Segment_Flag = 0;
	LED_Flag = 0;

}

void __vector_11(void)  __attribute__((signal));
void __vector_11(void)
{

	Seven_Segment_Flag++;

	if (Seven_Segment_Flag==310)
	{
		Tnterrupt_Flag=5;
	}

	LED_Count++;
	if(LED_Count==61)
	{
		if(LED_Flag==0)
		{
			LED_Flag=1;
		}
		else
		{
			LED_Flag=0;
		}

		LED_Count=0;
	}
	else
	{
		/* Nothing */
	}

}

