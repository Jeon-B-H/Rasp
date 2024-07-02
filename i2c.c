#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main(void) {
	// Device handler를 return 받는다.
	// 
	int fd = wiringPiI2CSetup(0x48);
	
	// Device
	wiringPiI2CWrite(fd, 3); // ch03 (VR)
	
	while(1) {
		int val = wiringPiI2CRead(fd);
		float f = val / (float)255 * (float)5;
		
		printf("VR input level = %d (%4.2fV)\n", val, f);
		delay(500);
	}
	
	return 0;
}

