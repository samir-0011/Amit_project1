#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define OCR2   *((volatile u8*)0x43)
#define TCNT2  *((volatile u8*)0x44)
#define TCCR2  *((volatile u8*)0x45)
#define SFIOR  *((volatile u8*)0x50)
#define TIFR   *((volatile u8*)0x58)
#define TIMSK  *((volatile u8*)0x59)


#define TIMER2_NORMAL_MODE           0
#define TIMER2_CTC_MODE              1
#define TIMER2_PWM_PHASECORRECT_MODE 2
#define TIMER2_PWM_FAST_MODE         3

#define TIMER2_BITMASK_PRESCALER    0xF8

#define TIMER2_NO_PRESCALER     1
#define TIMER2_8_PRESCALER      2
#define TIMER2_64_PRESCALER     3
#define TIMER2_256_PRESCALER    4
#define TIMER2_1024_PRESCALER   5

#define TIMER2_EXTERNAL_SOURCE_FALLING     6
#define TIMER2_EXTERNAL_SOURCE_RISING      7

#endif /* TIMER2_PRIVATE_H_ */
