#include <stdio.h>
#include <wiringPi.h>

// Substitute constant of wiring Pin number.
#define TRIG 8
#define ECHO 9
#define SOUND 7

// Function prototype.
extern double Dist();

// Main method.
int main(int argc, char **argv)
{
	// Define wiring Pin number.
	wiringPiSetup(); // Pin numbering method : wPi
	pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);

	
	while(1) {
		digitalWrite(SOUND, 0);
		
		double distance = Dist();
		
		printf("Sound distance = %.2lf(cm)\n", distance);
		delay(500);
	}
	
	return 0;
}
