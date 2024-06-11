#include <stdio.h>
#include <wiringPi.h>
#include <stdint.h>

// Substitute Constant.
#define TIME 1000

// Global variable.
uint8_t pin_state[40]; // Raspi has 40 pins.
					   // Pin_state array has state of each pin.


// Toogle Function
void Toggle(uint8_t pin) {
	pin_state[pin] = !pin_state[pin];
	
	digitalWrite(pin, pin_state[pin]);
}

// Main method
int main(void) {
	// Set Pin System (wPi System)
	wiringPiSetup();

	// Output Pin array
	uint8_t pin_out_list[] = {8, 9, 7};
	uint8_t pin_in_list[] = {2};

	// Set PORT
	// Set Output port 
	for(uint8_t i=0; i<sizeof(pin_out_list)/sizeof(pin_out_list[0]); i++)
		pinMode(pin_out_list[i], OUTPUT);
		
	// Set Input port
	for(uint8_t i=0; i<sizeof(pin_in_list)/sizeof(pin_in_list[0]); i++)
		pinMode(pin_in_list[i], INPUT);
	
	// Pull-up Switch circuit
	int mode = 0;
	
	while(1) {
		uint8_t upper = sizeof(pin_out_list)/sizeof(pin_out_list[0]);
		
		mode = (digitalRead(2)==0)? !mode:mode;
		
		// digitalRead 함수는 입력 포트의 값을 읽는 함수이다.
		// Switch Push
		if(mode == 0) {
			for(int i=0; i<upper; i++) {
			   Toggle(pin_out_list[i]);
			   delay(TIME);
		    }
		}else {
			for(int i=upper-1; i>=0; i--) {
			   Toggle(pin_out_list[i]);
			   delay(TIME);
		    }
		}
	 }
}
