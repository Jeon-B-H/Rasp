#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23

int main(void) {
	wiringPiSetup();
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmWrite(wPi_PWM1, 500);
	
	return 0;
}
