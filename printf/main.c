#include "printf.h"

int main() {
	double x = 24.4567234234235234234235232383838383838427394827349827394872398472983430569304958209385;
	char *s = "OMNOMNOM";
	long long int b = 90231241242342;
	printf("%+-f\n %.40lli\n hello my darling\n %-040c\n", x, b, 'c');
	ft_printf("%+-f\n %.40lli\n hello my darling\n %-040c\n", x, b, 'c');
	return 0;
}