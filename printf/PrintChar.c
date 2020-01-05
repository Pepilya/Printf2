#include "printf.h"

void printChar(t_spec *sp, char c) {
	int i;
	int side;

	side = 0;
	if (ft_strchr(sp->flags, '-'))
		side = 1;
	ft_putstr(sp->text);
	if (side) {
		ft_putchar(c);
		i = 0;
		while (i < sp->width - 1) {
			ft_putchar(32);
			i++;
		}
	} else {
		i = 0;
		while (i < sp->width - 1) {
			ft_putchar(32);
			i++;
		}
		ft_putchar(c);
	}
}