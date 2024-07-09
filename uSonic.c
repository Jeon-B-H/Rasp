#include <stdio.h>
#include <wiringPi.h>

// Substitute constant of wiring Pin number.
#define TRIG 8
#define ECHO 9

// Function prototype.
double Dist();

// Main method.
int main(int argc, char **argv)
{
	// Define wiring Pin number.
	wiringPiSetup(); // Pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
	
	while(1) {
		printf("Distance = %.2lf(cm)\n", Dist());
		delay(500);
	}
	
	return 0;
}

// Compute distance.
double Dist() {
	    // Supply pulse signal having high level during 10us
		digitalWrite(TRIG, 1);
		delayMicroseconds(10); // 10us delay
		digitalWrite(TRIG, 0);
		delayMicroseconds(200); 
    
		// TRIG Module (Sonic burst) generate 8 pulse signal having 25us (25us * 8 = 200us)
		// so, Trigger input signal have delay time during 200us.
	
		// Waiting forStart of generating burst signal.
		// while(digitalRead(ECHO) != 0); // Wait for burst Start.
		
		// Waiting for ECHO Signal.
		// Waiting for End of generating burst signal.
		while(digitalRead(ECHO) != 1); // Wait for burst End.
	
		int t1 = micros(); // Get start time. (in micro-second)
	
		// When ECHO Moudle get reflecting signal,
		// ECHO signal change level from high to low.

		while(digitalRead(ECHO) != 0); // Wait for burst End.
	
		int t2 = micros(); // Get end time. (in micro-second)
	
		double dist = (t2 - t1) * 0.017;
}

