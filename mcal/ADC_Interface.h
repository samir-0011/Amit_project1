#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);
u16 ADC_u16StartConversion(u8 Copy_u8Channel);
void ADC_voidInit_Interrupt(void);
void ADC_u16StartConversion_Interrupt(u8 Copy_u8Channel);
u16 ADC_u16DigitalRead(void);

#endif /* ADC_INTERFACE_H_ */
