#include "printf.h"


void roundNum(t_spec *sp, unsigned long *arr)
{
	size_t i;
	size_t j;

	i = sp->acc + 1;
	j = i;
	while (i > 0)
	{
		if ((arr[i] >= 5 && j == i) || arr[i] > 10)
		{
			arr[i - 1] += 1;
			arr[i] = arr[i] % 10;
		}
		i--;
	}
}

void createDouble(t_spec *sp, unsigned long *arr)
{
	size_t i;
	size_t j;

	i = sp->acc + 1;
	j = 0;
	while (i > 0)
	{
		if (j == 0)
			arr[j++] = sp->bp_num;
		sp->ap_num *= 10;
		arr[j++] = (int)sp->ap_num;
		sp->ap_num -= (int)sp->ap_num ;
		i--;
	}
	roundNum(sp, arr);
}

char *addInt(t_spec *sp, unsigned long *arr)
{
	char *tmp;
	char *str;

	tmp = ft_itoa_base_ulong(arr[0], 10);
	if (ft_strchr(sp->flags, '+'))
	{
		str = ft_strjoin("+", tmp);
		ft_strdel(&tmp);
		tmp = str;

	}
	str = ft_strjoin(tmp, ".");
	ft_strdel(&tmp);
	return str;
}


char *doubleToString(t_spec *sp, unsigned long *arr)
{
	char *beforePoint;
	char *afterPoint;
	size_t i;
	size_t j;
	size_t arrIndex;
	char *result;

	beforePoint = addInt(sp, arr);
	afterPoint = (char *)malloc(sizeof(char) * sp->acc + 1);
	i = sp->acc;
	j = 0;
	arrIndex = 1;
	while (i-- > 0)
		afterPoint[j++] = (char)arr[arrIndex++] + 48;
	afterPoint[j] = 0;
	result = ft_strjoin(beforePoint, afterPoint);
	ft_strdel(&beforePoint);
	ft_strdel(&afterPoint);
	return result;
}

void printDouble(t_spec *sp, char *toPrint)
{
	int i;
	int len;

	len = ft_strlen(toPrint);
	if (ft_strchr(sp->flags, '-')) {
		ft_putstr(toPrint);
		i = 0;
		while (++i < (sp->width - len) + 1)
			ft_putchar(' ');
	} else {
		i = 0;
		while (++i < (sp->width - len) + 1) {
			if (ft_strchr(sp->flags, '0'))
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putstr(toPrint);
	}
}

void getDouble(t_spec *sp, va_list argp)
{
	unsigned long *arr;
	char *str;
	long double num;

	if (sp->mod == 5)
		num = va_arg(argp, long double);
	else
		num = (long double)va_arg(argp, double);
	if (num < 0)
	{
		sp->sign = -1;
		num = -num;
	}
	if (sp->isPoint == 0)
		sp->acc = 6;
	sp->bp_num = (unsigned long)num;
	sp->ap_num = num - (unsigned long)num;
	arr = (unsigned long *)malloc(sizeof(unsigned long) *
			(sp->acc + 2 + ft_strlen(ft_itoa_base_long(sp->bp_num, 10))));
	createDouble(sp, arr);
	str = doubleToString(sp, arr);
	printDouble(sp, str);
}