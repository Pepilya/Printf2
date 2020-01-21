#include "printf.h"


void printWidthString(t_spec *sp, char *s)
{
	int i;
	int size;

	size = ft_strlen(s);
	i = 0;
	while (i < sp->width - size)
	{
		ft_putchar(32);
		i++;
	}
}

void getString(t_spec *sp, va_list argp)
{
	int side;
	char *s;

	s = va_arg(argp, char *);
	side = 0;
	ft_putstr(sp->text);
	if (!ft_strchr(sp->flags, '-'))
	{
		printWidthString(sp, s);
		side = 1;
	}
	ft_putstr(s);
	if (side == 0)
		printWidthString(sp, s);
}