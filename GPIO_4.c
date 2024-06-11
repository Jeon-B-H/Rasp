#include <stdio.h>
#include <stdint.h>
#include <wiringPi.h>

// Global variable.
static uint8_t flag_break = 0;
static uint8_t pins_state[40];
static unsigned int time = 500;

static uint8_t output_pins[] = {8, 9, 7};
static uint8_t input_pins[] = {2, 3};

static uint8_t size_output_pins = sizeof(output_pins)/sizeof(output_pins[0]);
static uint8_t size_input_pins = sizeof(input_pins)/sizeof(input_pins[0]);

// GPIO_ISR
void GPIO_ISR() {
	time += 100;
	
	if(time>=1500) time = 500;
	
	printf("Interrupt!\n");
	printf("Delay time = %d\n", time);
}

// STOP GPIO_ISR
void STOP_ISR() {	
	for(uint8_t i=0; i<size_output_pins; i++)
		digitalWrite(output_pins[i], 0);
	
	flag_break = 1;
}

// Function prototype.
void Toggle(uint8_t pin);

// Main method.
int main(void) {
	// Set up PIN System (wPi System)
	wiringPiSetup();
	
	// Set Inupt/Output PIN.
	for(uint8_t i=0; i<size_output_pins; i++)
		pinMode(output_pins[i], OUTPUT);
		
	for(uint8_t i=0; i<size_input_pins; i++)
		pinMode(input_pins[i], INPUT);
		
	// Set up Interrupt.
	wiringPiISR(input_pins[0], INT_EDGE_FALLING, GPIO_ISR);
	wiringPiISR(input_pins[1], INT_EDGE_RISING, STOP_ISR); 	
	
	// Print The LED.
	while(1) {
		for(uint8_t i=0; i<size_output_pins; i++) {
			if(flag_break) break;
			Toggle(output_pins[i]);
			delay(time);
		}	
		
		if(flag_break) break;
	}	
	
	return 0;
}

// Toggle method.
void Toggle(uint8_t pin) {
	pins_state[pin] = ~pins_state[pin];
	
	digitalWrite(pin, pins_state[pin]);
}
