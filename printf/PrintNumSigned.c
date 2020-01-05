#include "printf.h"

// ОБработка значения модификаторы. Приведение типа (h hh l ll) пока работают только h и hh
char *changeNumType(t_spec *sp, long long int d)
{
	char *string;
	int base;

	base = 10;
	if (sp->type == 'p')
		base = 16;
	if (sp->mod == 0)
		string = ft_itoa_base(d, base);
	if (sp->mod == 1 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((char) d, base);
	if (sp->mod == 2 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((short) d, base);
	if (sp->mod == 3)
		string = ft_itoa_base_long((long long int) d, base);
	if (sp->mod == 4)
		string = ft_itoa_base_long((long int) d, base);
	return string;
}

// Печать целочисленных значений
void printNum(t_spec *sp, long long int d)
{
	char *toPrint;
	int check;

	ft_putstr(sp->text);
	toPrint = changeNumType(sp, d);
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