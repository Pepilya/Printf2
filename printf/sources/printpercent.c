/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:17:58 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 16:19:22 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printwidthpercent(t_spec *sp)
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

void	getpercent(t_spec *sp)
{
	if (sp->acc_zero == 1)
		sp->flag_zero = 1;
	ft_putstr(sp->text);
	if (sp->flag_minus == 0)
		printwidthpercent(sp);
	ft_putchar('%');
	if (sp->flag_minus == 1)
		printwidthpercent(sp);
	counting(sp, 0, 1);
}
