#ifndef Timer0_INTERFACE_H	
#define Timer0_INTERFACE_H


#define freq_3906			0
#define freq_1960			1
#define freq_488			2
#define freq_245			3
#define freq_61				4
#define freq_31				5
#define freq_15				6
#define freq_8				7
#define freq_4				8
#define freq_2				9








void TIMER0_init(void);
void TIMER0_SetFrequency(int f_PWM);
void TIMER0_Set_PWM_DutyCycle(int chA_dutyCycle, int chB_dutyCycle);



#endif 
