#include <stdio.h>
#include <wiringPi.h>

int main(void) {
	// 출
	wiringPiSetup();
	
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	
	int pin_list[] = {8, 9, 7};
	
	while(1) {
		for(char i=0; i<3; i++) {
			digitalWrite(pin_list[i], HIGH);
			delay(500);
		}
	
		for(char i=0; i<3; i++) {
			digitalWrite(pin_list[i], LOW);
			delay(500);
		}
	}
	
	return 0;
}
