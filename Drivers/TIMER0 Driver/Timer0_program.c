#include "Timer0_interface.h"
#include "Timer0_config.h"
#include "Timer0_private.h"
#include "avr/io.h"


void TIMER0_init(void)
{
	TCCR0A |= (PWM_MODE_SELECT1 << COM0A1) | (PWM_MODE_SELECT2 << COM0A0) | (PWM_MODE_SELECT1 << COM0B1) | (PWM_MODE_SELECT2 << COM0B0) | (TIMER0_MODE_SELECT1 << WGM01) | (TIMER0_MODE_SELECT2 << WGM00);
	TCCR0B |= (1 << CS00);
	OCR0A = 0;
	OCR0B = 0;
}



void TIMER0_Set_PWM_DutyCycle(int ch, int dutyCycle)
{
	switch(ch){
		case ch_A:
			OCR0A = dutyCycle;
			break;
		case ch_B:
			OCR0B = dutyCycle;
		break;
		default:
			return;
				}
}

void TIMER0_SetFrequency(int f_PWM){
	TCCR0B =0;
	if (TIMER0_MODE_SELECT1 == 0)
	{
		switch(f_PWM){
			case freq_1960:
				TCCR0B = ( 1 << CS00);
			break;
			case freq_245:
				TCCR0B = (1 << CS01);
			break;
			case freq_31:
				TCCR0B = (1 << CS01) | (1 << CS00);
			break;
			case freq_8:
				TCCR0B =(1 << CS02);
			break;
			case freq_2:
				TCCR0B = (1 << CS02) | (1 << CS00);
			break;
			default:
				return;
					}
	}
	if (TIMER0_MODE_SELECT1 == 1)
	{
		switch(f_PWM){
			case freq_3906:
				TCCR0B = ( 1 << CS00);
			break;
			case freq_488:
				TCCR0B = (1 << CS01);
			break;
			case freq_61:
				TCCR0B = (1 << CS01) | (1 << CS00);
			break;
			case freq_15:
				TCCR0B =(1 << CS02);
			break;
			case freq_4:
				TCCR0B = (1 << CS02) | (1 << CS00);
			break;
			default:
				return;
					}
	}
}


