#include "printf.h"

void toUpper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper((char) str[i]);
		i++;
	}
}

char *changeUnNumType(t_spec *sp, unsigned long long int d)
{
	char *string;
	int base;

	base = 10;
	if (sp->type == 'X' || sp->type == 'x')
		base = 16;
	if (sp->type == 'o')
		base = 8;
	if (sp->mod == 0)
		string = ft_itoa_base(d, base);
	if (sp->mod == 1)
		string = ft_itoa_base((unsigned char) d, base);
	if (sp->mod == 2)
		string = ft_itoa_base((unsigned short) d, base);
	if (sp->mod == 3)
		string = ft_itoa_base_ulong((unsigned long long int) d, base);
	if (sp->mod == 4)
		string = ft_itoa_base_ulong((unsigned long int) d, base);
	if (sp->type == 'X')
		toUpper(string);
	return string;
}

// Печать целочисленных значений
void printUnsignedNum(t_spec *sp, unsigned long long int d)
{
	char *toPrint;
	int check;

	ft_putstr(sp->text);
	toPrint = changeUnNumType(sp, d);
	check = isDecimal(sp);
	if (ft_strchr(sp->flags, '+') && check)
	{
		if (!ft_strchr(toPrint, '-'))
			ft_putchar('+');
		cutLength(sp);
	} else if (ft_strchr(sp->flags, ' ') && check)
	{
		if (!ft_strchr(toPrint, '-'))
			ft_putchar(' ');
		cutLength(sp);
	}
	if (sp->acc > 0 && sp->acc > sp->width)
		printAccuracy(sp, toPrint);
	else
		printWidth(sp, toPrint);
}