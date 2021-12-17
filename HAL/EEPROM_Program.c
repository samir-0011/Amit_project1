#include"STD_TYPES.h"
#include"DIO_I.h"
#include"EEPROM_Private.h"
#include<util/delay.h>

void EEPROM_write(u16 u16_Address, u8 u8_Data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = u16_Address;
	EEDR = u8_Data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start EEprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

u8 EEPROM_read(u16 u16_Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address register */
	EEAR = u16_Address;
	/* Start EEprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}

