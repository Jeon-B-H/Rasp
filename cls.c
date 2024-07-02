#include <stdio.h>

int main(void) {
	printf("\033[2J");
	printf("\033[1;1H"); // [x;yH
	
	return 0;
}
