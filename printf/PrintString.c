#include "printf.h"

void printString(t_spec *sp, char *s) {
	int i;
	int side;
	int size;

	size = ft_strlen(s);
	side = 0;
	if (ft_strchr(sp->flags, '-'))
		side = 1;
	ft_putstr(sp->text);
	if (side) {
		ft_putstr(s);
		i = 0;
		while (i < sp->width - size) {
			ft_putchar(32);
			i++;
		}
	} else {
		i = 0;
		while (i < sp->width - size) {
			ft_putchar(32);
			i++;
		}
		ft_putstr(s);
	}
}