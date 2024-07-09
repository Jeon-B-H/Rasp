#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23S

int prescaler = 19;
int range = 100;
int duty = range / 2;

int main(void {
	wiringPiSetup();
	
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	
	// Prescaler : 19
	pwmSetClock(prescaler);
	// 19.2MHz / 19 = almost 1MHz
	
	// Range : top of counter
	pwmSetRange(range);
	
	// Duty ratio : 50%
	// pwmWrite(wPi , Compare register).
	pwmWrite(wPi_PWM1, duty);	

	return 0;
}
