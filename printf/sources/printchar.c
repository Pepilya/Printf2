/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:41:04 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:42:11 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printwidthchar(t_spec *sp)
{
	int i;

	if (sp->flag_minus == 1)
	{
		i = 0;
		while (++i < (sp->width - 1) + 1)
			ft_putchar(' ');
	}
	else
	{
		i = 0;
		while (++i < (sp->width - 1) + 1)
		{
			if (sp->flag_zero && !sp->acc)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
}

void	printchar(t_spec *sp, va_list argp)
{
	int c;

	if (sp->acc_zero == 1)
		sp->flag_zero = 1;
	c = va_arg(argp, int);
	ft_putstr(sp->text);
	if (sp->flag_minus == 0)
		printwidthchar(sp);
	ft_putchar(c);
	if (sp->flag_minus == 1)
		printwidthchar(sp);
	counting(sp, 0, 1);
}
