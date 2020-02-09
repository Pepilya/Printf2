/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printrest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:19:38 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 16:20:49 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printwidthrest(t_spec *sp)
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

void	getrest(t_spec *sp)
{
	ft_putstr(sp->text);
	if (sp->type != 0)
	{
		if (sp->acc_zero == 1)
			sp->flag_zero = 1;
		if (sp->flag_minus == 0)
			printwidthrest(sp);
		ft_putchar(sp->type);
		if (sp->flag_minus == 1)
			printwidthrest(sp);
	}
	if (sp->type != 0)
		counting(sp, 0, 1);
	else
		counting(sp, 0, 0);
}
