#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER_Private.h"
#include"TIMER_Config.h"

void TIMER0_voidInit(void)
{
#if TIMER0_MODE==TIMER0_NORMAL_MODE
	/*Set Normal Timer mode*/
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*OVERFLOW INTERRUPT ENABLE*/
	SET_BIT(TIMSK,0);

#elif TIMER0_MODE==TIMER0_CTC_MODE
	/*Set CTC Timer mode*/
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/*CTC INTERRUPT ENABLE*/
	SET_BIT(TIMSK,1);

#elif TIMER0_MODE==TIMER0_PWM_PHASECORRECT_MODE
	/*Set CTC Timer mode*/
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

#elif TIMER0_MODE==TIMER0_PWM_FAST_MODE
	/*Set CTC Timer mode*/
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
#else
	#error"You have error in set TIMER0 MODE"
#endif
	/*Set Prescaler*/
	TCCR0&=TIMER0_BITMASK_PRESCALER;
	TCCR0|=TIMER0_PRESCALER;
}
void TIMER0_voidSetPreloadValue(u8 Copy_u8Preload)
{
	TCNT0=Copy_u8Preload;
}
