#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
int main() {
    int fd = wiringPiI2CSetup(0x48); 
	   
    int value_x, value_y;
    int x, y;

    while(1) {
        wiringPiI2CWrite(fd, 2);
        
        wiringPiI2CRead(fd);
        value_x = wiringPiI2CRead(fd);
        
        x = 80 * value_x / 255;

        wiringPiI2CWrite(fd, 1);
        
        wiringPiI2CRead(fd);
        value_y = wiringPiI2CRead(fd);
        
        y = 24 * value_y / 255;
        
        printf("\033[2J");
	printf("\033[%d;%dH", x, y); // [x;yH
        delay(500);
    }

    return 0;
}
