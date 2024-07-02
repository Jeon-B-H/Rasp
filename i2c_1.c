#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
int main() {
    int fd = wiringPiI2CSetup(0x48); 
	   
    int value1, value2, value3;

    while(1) {
        wiringPiI2CWrite(fd, 0);
        wiringPiI2CRead(fd);

        value1 = wiringPiI2CRead(fd);
        float fl1 = (float)(value1/255.0) / 5.0;

        wiringPiI2CWrite(fd, 2);
        wiringPiI2CRead(fd);

        value2 = wiringPiI2CRead(fd);
        float fl2 = (float)(value2/255.0) / 5.0;

        wiringPiI2CWrite(fd, 3);
        wiringPiI2CRead(fd);

        value3 = wiringPiI2CRead(fd);
        float fl3 = (float)(value3/255.0) / 5.0;

        printf("ADC value = %d %d %d\n", value1, value2, value3);
        delay(500);
    }

    return 0;
}
