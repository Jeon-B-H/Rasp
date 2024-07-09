#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define wPi_Pin 22

int main(int n, char *s[]) {
	// dr : duty ratio
	// drh : high-level duty
	// drl : low-level duty
	int dr,drh, drl, period = 10;
	
	if(n < 2) {
		printf("usage : pwm2 [duty_rate(%%)][[period]]\n\n");
		return 1;
	}
	
	// Get duty rate (%)
	sscanf(s[1], "%d", &dr);
	
	// ex) dr = 35   --->   duty ratio = 35%
	drh = (dr*period)/100;	// Mark Time 
	drl = period - drh;     // Space Time
	
	                              
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
