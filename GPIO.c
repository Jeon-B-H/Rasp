#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>

int main(void){
	// 어떤 핀 체계를 사용할지를 초기 설정
	wiringPiSetup(); // Pin number use case (Using wPi system)
	
	// wPi 체계 기준으로 PIN number로 8, 9, 7, 2 을 사용
	// PIN Number : 8, 9, 7 은 LED로 연결, 2번은 스위치 연결
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(2, INPUT);
	// PIN Number가 헷갈리면 물리적 핀 넘버와 비교를 통해 알아보기.
	
	for(uint8_t i=0; i<5; i++) {
		// 16bit 데이터를 출력하는 함수
		// ATmega128에서 PORT와 유사한 기능
		digitalWrite(8, HIGH);
		digitalWrite(9, 1);
		digitalWrite(7, HIGH);
		delay(1000);
		// HIGH == 1 이미 상수로 치환된 상태
	
		digitalWrite(8, LOW);
		digitalWrite(9, 0);
		digitalWrite(7, LOW);
		delay(1000);
		// LOW == 0 이미 상수로 치환된 상태 
    }
	
	return 0;
}
