#include <stdio.h>
#include <wiringPi.h>

#define wPi_PWM1 23

int prescaler = 19;
int range = 100;
int duty = 50;

int list[8] = {261,294,329,349,393,440,493,523};
int nums[] = {2,2,2,2,2,2,2,4,0,1,2,3,3,3,3,3,2,2,2,2,1,1,0,1,4,2,2,2,2,2,2,2,4,0,1,2,3,3,3,3,3,2,2,2,4,4,3,2,0};

int calcPrescaler(int freq) {
	return 19200000/19/freq;
}

int main(void) {
	wiringPiSetup();
	
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	
	int upper = sizeof(nums)/sizeof(nums[0]);
	
	for(int i=0; i<upper; i++) {
		pwmSetClock(calcPrescaler(list[nums[i]]));
	
		pwmSetRange(range);
	
		pwmWrite(wPi_PWM1, duty);	
	}

	return 0;
}
