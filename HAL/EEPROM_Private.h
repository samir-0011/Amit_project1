#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEPROM_FIXED_ADDRESS   0b1010000

#define EEPROM_SIZE 1023
#define EEAR	*((volatile u16*)0x3E)
#define SPMCR	*((volatile u8*)0x57)
#define EECR	*((volatile u8*)0x3C)
#define EEDR	*((volatile u8*)0x3D)

#define EEWE     1
#define EEMWE    2
#define EERE     0



#endif /* EEPROM_PRIVATE_H_ */
