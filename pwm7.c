#include <wiringPi.h>

#define wPi_PWM1 23

int prescaler = 19;
int duty = 50;

enum {DO = 0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI};
int pitch[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int ranges[12];
int song[] = {SL, SL, LA, LA, SL, SL, MI, SL, SL, MI, MI, RE,
	          SL, SL, LA, LA, SL, SL, MI, SL, MI, RE, MI, DO};
int rythm[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1,
			   4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 1};
	         

void calcRange() {
	int upper = sizeof(pitch) / sizeof(pitch[0]);
	
	for(int i=0; i<upper; i++)
		ranges[i] = 19200000 / 19 / pitch[i];
}

void playSound(int um) {
	pwmSetClock(prescaler);
	pwmSetRange(ranges[um]);
	pwmWrite(wPi_PWM1, duty);
}

int main(void) {
	wiringPiSetup();
	
	pinMode(wPi_PWM1, PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	
	calcRange();
	
	int upper = sizeof(song) / sizeof(song[0]);
	for(int i=0; i < upper; i++) {
		playSound(song[i]);
	}

	return 0;
}
