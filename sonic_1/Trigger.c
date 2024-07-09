#include <stdio.h>
#include <wiringPi.h>

// Substitute constant of wiring Pin number.
#define TRIG 8

// Compute distance.
void Trigger() {
	    // Supply pulse signal having high level during 10us
		digitalWrite(TRIG, 1);
		delayMicroseconds(10); // 10us delay
		digitalWrite(TRIG, 0);
		delayMicroseconds(200); 
	}

