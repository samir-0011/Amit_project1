#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0  *((volatile u8*)0x53)
#define TIMSK  *((volatile u8*)0x59)
#define TCNT0  *((volatile u8*)0x52)

#define TIMER0_NORMAL_MODE           0
#define TIMER0_CTC_MODE              1
#define TIMER0_PWM_PHASECORRECT_MODE 2
#define TIMER0_PWM_FAST_MODE         3

#define TIMER0_BITMASK_PRESCALER    0xF8

#define TIMER0_NO_PRESCALER     1
#define TIMER0_8_PRESCALER      2
#define TIMER0_64_PRESCALER     3
#define TIMER0_256_PRESCALER    4
#define TIMER0_1024_PRESCALER   5

#define TIMER0_EXTERNAL_SOURCE_FALLING     6
#define TIMER0_EXTERNAL_SOURCE_RISING      7

#endif /* TIMER_PRIVATE_H_ */
