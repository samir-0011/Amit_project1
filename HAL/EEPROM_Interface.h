#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

void EEPROM_write(u16 u16_Address, u8 u8_Data);
u8 EEPROM_read(u16 u16_Address);

#endif /* EEPROM_INTERFACE_H_ */


