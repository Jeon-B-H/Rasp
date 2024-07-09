#include <stdio.h>
#include <wiringPi.h>

// Substitute constant of wiring Pin number.
#define TRIG 8
#define ECHO 9
#define SOUND 23

// Function prototype.
extern double Dist();
extern void calcRange();
extern void playMusic();

// Main method.
int main(int argc, char **argv)
{
	// Define wiring Pin number.
	wiringPiSetup(); // Pin numbering method : wPi
	
	// set pin mode.
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	pinMode(SOUND, PWM_OUTPUT);
	
	// set PWM mode.
    pwmSetMode(PWM_MODE_MS);
    
    // compute ranges.
    calcRange();
    
	while(1) {
		
		double distance = Dist();
		
		printf("raszer distance = %.2lf(cm)\n", distance);
		
		// if(distance < 20.0) {
		//	if(distance < 4) 
		//		digitalWrite(SOUND, 1);
		//	else {
		//		digitalWrite(SOUND, 1);
		//		delay(5 * distance);
		//		digitalWrite(SOUND, 0);
		//		delay(5 * distance);
		//	}
		//}
		
		if(distance < 7.0)
			playMusic(1);
		else if(distance < 12.0)
			playMusic(3);
		else if(distance < 15.0) 
			playMusic(5);
		
		delay(500);
	}
	
	return 0;
}

