#include <stdio.h>
#include <wiringPi.h>

#define wpi_22 	22

int main(int n, char *s[]) {
	// dr : duty ratio
	// drh : high-level duty
	// drl : low-level duty
	int dr,drh, drl, period = 10;
	int count = 50;
	
	if(n < 2) {
		printf("usage : pwm1 [duty_rate(%)]\n\n");
		return 1;
	}
	
	// duty rate 값을 받기.
	sscanf(s[1], "%d", &dr);
	
	// period를 입력받았으면 해당 값을 period로 설정하기
	if(n >= 3) sscanf(s[2], "%d", &period);
	
	// get the number of turn on the light.
	if(n >= 4) sscanf(s[3], "%d", &count);

	
	// period를 10이라고 보았을 떄, dr은 duty ratio를 퍼센트로 표현
	// ex) dr = 35   --->   duty ratio = 35%
	drh = (dr*period)/100;
	drl = period - drh;
	
	                              
	wiringPiSetup(); // wPi Pin number
	
	// 22번핀을 출력으로 설정
	pinMode(wpi_22, OUTPUT);
	
	for(int i=0; i<count; i++) {
		// 22번핀에 1을 출력
		digitalWrite(wpi_22, 1);
	
		delay(drh);
	
		// 22번핀에 0을 출
		digitalWrite(wpi_22, 0);
	
		delay(drl);
	}
	
	
	return 0;
}
