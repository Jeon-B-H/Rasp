#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>

int main(void) {
	wiringPiSetup();
	
	pinMode(11, INPUT);
	pinMode(13, INPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	
	for(uint8_t i=0; i<10; i++) {
		digitalWrite(7, HIGH);
		digitalWrite(8, 1);
		digitalWrite(9, HIGH);
		delay(1000);
		
		digitalWrite(7, LOW);
		digitalWrite(8, 0);
		digitalWrite(9, LOW);
		delay(1000);
	}
	
	
	return 0;
}
