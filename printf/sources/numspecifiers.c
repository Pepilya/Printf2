/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numspecifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:46:50 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:05:31 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	choice_1(t_spec *sp, char *toprint, char c)
{
	if (!sp->ispoint && c != 0 && sp->flag_zero == 1)
	{
		if ((sp->flag_grid && (sp->type == 'x' || sp->type == 'X'))
		|| sp->type == 'p')
			ft_putstr(sp->hex);
		else
			write(1, &c, 1);
		c = 0;
	}
	printwidth(sp, toprint, 0, 0);
	if (sp->ispoint && sp->flag_zero == 1 && c != 0)
	{
		if ((sp->flag_grid && (sp->type == 'x' || sp->type == 'X'))
		|| sp->type == 'p')
			ft_putstr(sp->hex);
		else
			write(1, &c, 1);
		c = 0;
	}
	printaccuracy(sp, toprint, 0, 0);
	return (c);
}

char	choice_2(t_spec *sp, char *toprint, char c)
{
	if (c != 0)
	{
		if ((sp->flag_grid && (sp->type == 'x' || sp->type == 'X'))
		|| sp->type == 'p')
			ft_putstr(sp->hex);
		else
			write(1, &c, 1);
		c = 0;
	}
	printaccuracy(sp, toprint, 0, 0);
	return (c);
}

void	choice(t_spec *sp, char *toprint, char c)
{
	if ((!sp->flag_minus && sp->flag_zero == 1)
		|| (!sp->flag_minus && (!sp->flag_zero || sp->flag_zero == -1)))
		c = choice_1(sp, toprint, c);
	if (sp->flag_minus && sp->flag_zero == 1 && sp->acc > 0)
		c = choice_2(sp, toprint, c);
	if (c != 0)
	{
		if ((sp->flag_grid && (sp->type == 'x' || sp->type == 'X'))
		|| sp->type == 'p')
			ft_putstr(sp->hex);
		else
			write(1, &c, 1);
	}
	ft_putstr(toprint);
	if (sp->flag_minus && sp->flag_zero == 1)
		printwidth(sp, toprint, 0, 0);
	if (sp->flag_minus && (!sp->flag_zero || sp->flag_zero == -1))
	{
		printaccuracy(sp, toprint, 0, 0);
		printwidth(sp, toprint, 0, 0);
	}
}

char	isgrid(t_spec *sp)
{
	if (sp->type == 'o')
		return ('0');
	else if (sp->type == 'x' || sp->type == 'p')
	{
		sp->hex = "0x";
		return ('x');
	}
	else if (sp->type == 'X')
	{
		sp->hex = "0X";
		return ('X');
	}
	return (0);
}

char	pissign(t_spec *sp)
{
	char c;

	c = 0;
	if ((sp->flag_grid && (sp->type == 'x' || sp->type == 'o'
	|| sp->type == 'X')) || sp->type == 'p')
		c = isgrid(sp);
	else if ((sp->flag_plus || sp->flag_space || sp->sign) && sp->type != 'u')
	{
		if (sp->sign)
			c = '-';
		else if (sp->flag_plus)
			c = '+';
		else
			c = ' ';
	}
	return (c);
}
