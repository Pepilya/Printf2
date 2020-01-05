#include "printf.h"

int main() {
	long long int x = -9223372036854775800;
	char *s = "HI I am here";
	printf("%.30llu\n", x);
	ft_printf("%.30llu\n", -9223372036854775800);
	return 0;
}