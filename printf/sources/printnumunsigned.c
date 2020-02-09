/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:06:31 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 16:17:39 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				upper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper((char)str[i]);
		i++;
	}
}

char				*changeunnumtype(t_spec *sp, unsigned long long int d)
{
	char	*string;
	int		base;

	base = 10;
	if (sp->type != 'f' && sp->mod == 5)
		sp->mod = 0;
	if (sp->ispoint && sp->acc == 0 && d == 0)
		return (iszero());
	if (sp->type == 'X' || sp->type == 'x' || sp->type == 'p')
		base = 16;
	if (sp->type == 'o')
		base = 8;
	if (sp->mod == 0)
		string = ft_itoa_base_ulong(d, base, sp->mod);
	if (sp->mod == 1)
		string = ft_itoa_base_ulong((unsigned char)d, base, sp->mod);
	if (sp->mod == 2)
		string = ft_itoa_base_ulong((unsigned short)d, base, sp->mod);
	if (sp->mod == 3)
		string = ft_itoa_base_ulong((unsigned long long int)d, base, sp->mod);
	if (sp->mod == 4)
		string = ft_itoa_base_ulong((unsigned long int)d, base, sp->mod);
	if (sp->type == 'X')
		upper(string);
	return (string);
}

unsigned long long	diffspec(t_spec *sp, unsigned long long lli)
{
	if (sp->type == 'U')
		sp->mod = 4;
	if (sp->mod != 3 && sp->mod != 4)
		lli = (unsigned int)lli;
	if (sp->acc_zero == 1)
		sp->flag_zero = 1;
	if (lli == 0 && sp->type != 'o')
		sp->flag_grid = 0;
	return (lli);
}

void				printunsignednum(t_spec *sp, va_list argp, char c, int ch)
{
	char					*toprint;
	unsigned long long int	lli;

	ft_putstr(sp->text);
	lli = va_arg(argp, unsigned long long int);
	lli = diffspec(sp, lli);
	ch = isdecimal(sp);
	if (!ch)
	{
		sp->flag_space = 0;
		sp->flag_plus = 0;
	}
	c = pissign(sp);
	toprint = changeunnumtype(sp, lli);
	if ((sp->flag_zero == 1 && (size_t)sp->acc > ft_strlen(toprint) &&
	sp->type == 'o') || (lli == 0 && ft_strchr(toprint, '0')
	&& ft_strlen(toprint) == 1))
	{
		sp->flag_grid = 0;
		c = 0;
	}
	choice(sp, toprint, c);
	counting(sp, c, ft_strlen(toprint));
	ft_strdel(&toprint);
}

void				printpointer(t_spec *sp, va_list argp)
{
	char	*toprint;
	char	*lli;
	char	c;
	int		check;

	ft_putstr(sp->text);
	lli = va_arg(argp, char *);
	if (sp->acc_zero == 1)
		sp->flag_zero = 1;
	check = isdecimal(sp);
	if (!check)
	{
		sp->flag_space = 0;
		sp->flag_plus = 0;
	}
	c = pissign(sp);
	toprint = changeunnumtype(sp, (unsigned long long)lli);
	choice(sp, toprint, c);
	counting(sp, c, ft_strlen(toprint));
	ft_strdel(&toprint);
}
