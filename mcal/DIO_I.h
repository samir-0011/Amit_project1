#ifndef DIO_I_H_
#define DIO_I_H_

#define PIN_INPUT	0
#define PIN_OUTPUT 	1

/* for user input port
 * can use enum */

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define PIN_LOW		0
#define PIN_HIGH	1

#define PORT_LOW	0
#define PORT_HIGH	255

#define PORT_INPUT	0
#define PORT_OUTPUT	255


enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}Pin_Number;

u8 DIO_u8SetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber , u8 Copy_u8PinDirection);
u8 DIO_u8SetPinValue	 (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber , u8 Copy_u8PinValue);
u8 DIO_u8GetPinValue	 (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber , u8* Copy_u8PinValue);
u8 DIO_u8TogglePinValue	 (u8 Copy_u8PinNumber, u8 Copy_u8PortNumber );

u8 DIO_u8SetPortDirection(u8 Copy_u8PortNumber , u8 Copy_u8PortDirection);
u8 DIO_u8SetPortValue	 (u8 Copy_u8PortNumber , u8 Copy_u8PortValue);
void DIO_u8Set4MSB_BitsValue(u8 Copy_u8PortNumber,u8 Copy_u8PortValue);

#endif /* DIO_I_H_ */
