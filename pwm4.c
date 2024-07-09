#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 7

int main(int n, char *s[]) {
	if(n < 2) {
		printf("usage : pwm2 [duty_rate(%%)][[period]]\n\n");
		printf("        period = 10 ms if empty\n\n");
		printf("        default value : period = 10ms, DR = 50%%\n\n");
		// return 1;
	}
	
	// dr : duty ratio
	// drh : high-level duty
	// drl : low-level duty
	int dr = 50,drh, period = 10;
	// Get duty rate (%)
	if(n>1) sscanf(s[1], "%d", &dr);
	if(n>2) sscanf(s[2], "%d", &period);
	
	drh = (dr*period)/100;	// Mark Time 
	// drl = period - drh;     // Space Time
	                              
	wiringPiSetup(); // wPi Pin number
	
	// Set output pin 22
	pinMode(wPi_Pin, OUTPUT);
	
	// PWM MODE : PWM_MODE_MS
	pwmSetMode(PWM_MODE_MS);
	
	// 1'st arguemnt : Output signal Pin
	// 2'nd argument : High-level duty rate (ms)
	// 3'rd argument : Period (ms)
	softPwmCreate(wPi_Pin, drh, period);
	
	delay(5000);
	softPwmStop(wPi_Pin);
	
	return 0;
}
