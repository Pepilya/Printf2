/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:42:31 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:47:57 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				printwidthdouble(t_spec *sp, int size)
{
	int i;

	if (sp->flag_plus == 1 || sp->sign == 1 || sp->flag_space == 1)
		sp->width -= 1;
	if (sp->flag_minus)
	{
		i = 0;
		while (++i < (sp->width - (size) + 1))
			ft_putchar(' ');
	}
	else
	{
		i = 0;
		while (++i < (sp->width - (size) + 1))
		{
			if (sp->flag_zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
}

void				printdouble(t_spec *sp, char *toprint, char c)
{
	int len;

	len = ft_strlen(toprint);
	ft_putstr(sp->text);
	if (!sp->flag_minus)
	{
		if ((sp->flag_plus || sp->flag_space || sp->sign) && sp->flag_zero == 1)
		{
			write(1, &c, 1);
			c = 0;
		}
		printwidthdouble(sp, len);
	}
	if ((sp->flag_plus || sp->flag_space || sp->sign) && c != 0)
		write(1, &c, 1);
	ft_putstr(toprint);
	if (sp->flag_minus == 1)
		printwidthdouble(sp, len);
}

long	double		isminus(t_spec *sp, long double num)
{
	if (num < 0)
	{
		sp->sign = 1;
		num = -num;
	}
	return (num);
}

void				getdb(t_spec *sp, va_list argp, char c, long double num)
{
	unsigned long	*arr;
	char			*str;

	if (sp->mod == 5)
		num = va_arg(argp, long double);
	else
		num = (long double)va_arg(argp, double);
	if (num != num)
		num = 0;
	num = isminus(sp, num);
	if (sp->ispoint == 0)
		sp->acc = 6;
	sp->bp_num = (unsigned long)num;
	sp->ap_num = num - (unsigned long)num;
	arr = (unsigned long *)malloc(sizeof(unsigned long) *
			(sp->acc + 2
			+ ft_strlen(ft_itoa_base_long(sp->bp_num, 10))));
	mkdouble(sp, arr);
	str = dbtost(sp, arr, 0, 0);
	c = pissign(sp);
	printdouble(sp, str, c);
	counting(sp, c, ft_strlen(str));
}
