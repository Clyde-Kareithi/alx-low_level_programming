#include "main.h"

void print_binary(unsigned long int n){
	int bit = sizeof(n) * 8 - 1;
	int flag = 0;

	if (n == 0){
		_putchar('0');
	return;
	}

	while (bit >= 0){
	if ((n >> bit) & 1){
		_putchar('1');
		flag = 1;
	}
	else if (flag == 1 || bit == 0){
		_putchar('0');
		}
	bit--;
	}
}

