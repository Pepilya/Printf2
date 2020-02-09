/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:21:05 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 16:22:26 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	printwidthstring(t_spec *sp, int size)
{
	int i;

	if (sp->ispoint && size >= sp->acc)
		size = sp->acc;
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

void	getstring(t_spec *sp, va_list argp)
{
	int		side;
	char	*s;
	int		size;
	int		i;

	s = va_arg(argp, char *);
	if (s == NULL)
		s = "(null)";
	size = ft_strlen(s);
	side = 0;
	ft_putstr(sp->text);
	if (!sp->flag_minus)
	{
		printwidthstring(sp, size);
		side = 1;
	}
	i = 0;
	if (size >= sp->acc && sp->ispoint)
		write(1, &s[i++], sp->acc);
	else
		write(1, &s[i++], size);
	if (side == 0)
		printwidthstring(sp, size);
	counting(sp, 0, ft_strlen(s));
}
