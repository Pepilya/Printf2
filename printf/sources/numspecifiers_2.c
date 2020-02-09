/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numspecifiers_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:05:52 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:10:42 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printaccuracy(t_spec *sp, char *toprint, int i, int len)
{
	int size;

	if (!sp->ispoint)
		return ;
	if ((sp->acc >= sp->width && sp->flag_zero != 1) || sp->type == 'o')
	{
		if ((sp->flag_grid == 1 && (sp->type == 'x' || sp->type == 'X'))
				|| sp->type == 'p')
			sp->acc -= 2;
		else if (sp->flag_plus == 1 || sp->sign == 1
				|| sp->flag_space == 1 || (sp->flag_grid && sp->type == 'o'))
			sp->acc -= 1;
	}
	len = ft_strlen(toprint);
	size = sp->acc - len;
	i = 0;
	while (i < size)
	{
		if (sp->flag_zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

void	printwidth(t_spec *sp, char *toprint, int i, int len)
{
	int size;

	len = ft_strlen(toprint);
	if (sp->width <= sp->acc)
		return ;
	if (sp->flag_plus == 1 || sp->sign == 1 || sp->flag_space == 1
			|| (sp->flag_grid && sp->type == 'o'))
		sp->width -= 1;
	else if ((sp->flag_grid == 1 && (sp->type == 'x' || sp->type == 'X'))
			|| sp->type == 'p')
		sp->width -= 2;
	if (sp->acc > len)
		size = sp->width - sp->acc;
	else
		size = sp->width - len;
	i = 0;
	while (i < size)
	{
		if (sp->flag_zero == 1 && !sp->ispoint && !sp->flag_minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int		isdecimal(t_spec *sp)
{
	if (sp->type == 'x' || sp->type == 'X' || sp->type == 'o'
			|| sp->type == 'p')
	{
		return (0);
	}
	else
		return (1);
}
