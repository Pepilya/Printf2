#include "printf.h"

void printWidthChar(t_spec *sp) {
	int i;

	if (ft_strchr(sp->flags, '-')) {
		i = 0;
		while (++i < (sp->width - 1) + 1)
			ft_putchar(' ');
	} else {
		i = 0;
		while (++i < (sp->width - 1) + 1) {
			if (ft_strchr(sp->flags, '0') && !sp->acc)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
}

void getChar(t_spec *sp, va_list argp)
{
	int side;
	int c;

	c = va_arg(argp, int);
	side = 0;
	ft_putstr(sp->text);
	if (ft_strchr(sp->flags, '-'))
		side = 1;
	if (!ft_strchr(sp->flags, '-'))
	{
		printWidthChar(sp);
		side = 1;
	}
	ft_putchar(c);
	if (side == 0)
		printWidthChar(sp);
}