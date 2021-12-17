#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"TIMER2_Private.h"
#include"TIMER2_Config.h"

void TIMER2_voidInit(void)
{
#if TIMER2_MODE==TIMER2_NORMAL_MODE
	/*Set Normal Timer mode*/
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	/*OVERFLOW INTERRUPT ENABLE*/
	SET_BIT(TIMSK,0);

#elif TIMER2_MODE==TIMER2_CTC_MODE
	/*Set CTC Timer mode*/
	SET_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	/*CTC INTERRUPT ENABLE*/
	SET_BIT(TIMSK,1);

#elif TIMER2_MODE==TIMER2_PWM_PHASECORRECT_MODE
	/*Set CTC Timer mode*/
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

#elif TIMER2_MODE==TIMER2_PWM_FAST_MODE
	/*Set CTC Timer mode*/
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
#else
	#error"You have error in set TIMER2 MODE"
#endif
	/*Set Prescaler*/
	TCCR2&=TIMER2_BITMASK_PRESCALER;
	TCCR2|=TIMER2_PRESCALER;
}
void TIMER2_voidSetPreloadValue(u8 Copy_u8Preload)
{
	TCNT2=Copy_u8Preload;
}
