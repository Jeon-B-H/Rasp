#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define MAX_X 80
#define MAX_Y 24

int main() {
    int fd = wiringPiI2CSetup(0x48); 
    int value_x, value_y;
    
    // 초기 설정
    // 처음 화면에서 커서가 중앙에 위치하도록 설정
    int x = MAX_X / 2, y = MAX_Y / 2; 

    printf("\033[2J");  // 화면 지우기
    printf("\033[?25l");  // 커서 지우

    while(1) {
        wiringPiI2CWrite(fd, 2);  
        wiringPiI2CRead(fd);  
        value_x = wiringPiI2CRead(fd);

        wiringPiI2CWrite(fd, 1); 
        wiringPiI2CRead(fd);  
        value_y = wiringPiI2CRead(fd);

        //x = 80 * value_x / 255;
        //y = 24 * value_y / 255;
        
        // value_x 가 100 미만이면 확실이 왼쪽으로 이동
        // value_x 가 150 초과이면 확실히 오른쪽으로 이동
        
        // value_y 가 100 미만이면 확실이 아래쪽으로 이동
        // value_y 가 150 초과이면 확실히 쪽으로 이동
        if (value_x < 100) x--;
        else if (value_x > 150) x++;
        if (value_y < 100) y--;
        else if (value_y > 150) y++;

        // Set Bound 
        // 조이스틱에 따라 x, y 값이 변하는데,
        // x, y 값이 화면 밖으로 벗어 날려고 하면
        // 조건문을 통해 밖으로 벗어나는 것을 방지
        if (x < 1) x = 1;
        if (x > MAX_X) x = MAX_X;
        if (y < 1) y = 1;
        if (y > MAX_Y) y = MAX_Y;

        printf("\033[%d;%dH*", y, x);  // 현재 커서 출력
        fflush(stdout); 

        delay(50);  // Delay 50ms
    }

    // Show Cursor
    printf("\033[?25h"); 
    return 0;
}
