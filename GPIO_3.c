#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

// Global varible.
static unsigned int time = 500;

// GPIO ISR (Interrupt Service Routine)
void GPIO_ISR() {
	time += 100;
			
	if(time>=1500) time = 500;
	printf("GPIO interrupt occured!\n");
	printf("Current delay time : %d\n", time);
}

// Main Method
int main(void) {
	// Set wPi System
	wiringPiSetup();
	
	// Array of Output PIN, Input PIN.
	uint8_t list_of_Output[] = {8, 9, 7};
	uint8_t list_of_Input[] = {2};
	uint8_t size_of_list_Output = sizeof(list_of_Output)/sizeof(list_of_Output[0]);
	uint8_t size_of_list_Input = sizeof(list_of_Input)/sizeof(list_of_Input[0]);
	
	// Set up Interrupt
	wiringPiISR(list_of_Input[0], INT_EDGE_RISING, GPIO_ISR);
	
	// Set Input, Output PIN 
	for(uint8_t i=0; i<size_of_list_Output; i++)
		pinMode(list_of_Output[i], OUTPUT);
		
	for(uint8_t i=0; i<size_of_list_Input; i++)
		pinMode(list_of_Input[i], INPUT);
		
	
	
	// Print The LED.
	while(1) {
		for(uint8_t i=0; i<size_of_list_Output; i++) {
			digitalWrite(list_of_Output[i], HIGH);
			delay(time);
		}
		
		for(uint8_t i=0; i<size_of_list_Output; i++) {
			digitalWrite(list_of_Output[i], 0);
			delay(time);
		}
	}
	
	return 0;
}
