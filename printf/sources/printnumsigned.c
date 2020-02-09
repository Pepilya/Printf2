/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnumsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:58:45 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 17:11:17 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*iszero(char *string)
{
	string = (char*)malloc(sizeof(char) * 1);
	ft_bzero(string, 1);
	return (string);
}

char			*changenumtype(t_spec *sp, long long int d)
{
	char	*string;
	int		base;

	base = 10;
	string = NULL;
	if (sp->type != 'f' && sp->mod == 5)
		sp->mod = 0;
	if (sp->ispoint && sp->acc == 0 && d == 0)
		return (iszero(string));
	if (sp->type == 'X' || sp->type == 'x' || sp->type == 'p')
		base = 16;
	if (sp->type == 'o')
		base = 8;
	if (sp->mod == 0)
		string = ft_itoa_base(d, base);
	if (sp->mod == 1 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((char)d, base);
	if (sp->mod == 2 && (sp->type == 'd' || sp->type == 'i'))
		string = ft_itoa_base((short)d, base);
	if (sp->mod == 3)
		string = ft_itoa_base_long((long long int)d, base);
	if (sp->mod == 4)
		string = ft_itoa_base_long((long int)d, base);
	return (string);
}

void			counting(t_spec *sp, char c, int len)
{
	int size;
	int prefix;

	prefix = 0;
	if (c == '+' || c == '-' || c == ' ' || (c == '0' && sp->flag_grid))
		prefix = 1;
	if (c == 'X' || c == 'x')
		prefix = 2;
	if (sp->acc > len && sp->acc >= sp->width
	&& sp->type != 'c' && sp->type != 's'
	&& sp->type != '%')
		size = sp->acc + prefix;
	else if (sp->type == 's' && sp->acc > 0
	&& sp->acc >= sp->width && len > sp->acc)
		size = sp->acc + prefix;
	else if (sp->width > len || (sp->type == 's' && sp->width > sp->acc
	&& sp->acc > 0))
		size = sp->width + prefix;
	else
		size = len + prefix;
	len = 0;
	if (sp->text != NULL)
		len = ft_strlen(sp->text);
	sp->count = len + size;
}

long long int	iscorrecttype(t_spec *sp, long long int lli)
{
	if (sp->mod != 3 && sp->mod != 4)
		lli = (int)lli;
	if (sp->mod == 2)
		lli = (short)lli;
	if (sp->mod == 1)
		lli = (char)lli;
	return (lli);
}

void			printnum(t_spec *sp, va_list argp)
{
	char			*toprint;
	long long int	lli;
	char			c;

	ft_putstr(sp->text);
	lli = va_arg(argp, long long int);
	lli = iscorrecttype(sp, lli);
	if (sp->acc_zero == 1)
		sp->flag_zero = 1;
	if (lli < 0)
	{
		sp->flag_plus = 0;
		sp->flag_space = 0;
		sp->sign = 1;
		lli = -lli;
	}
	c = pissign(sp);
	if (lli == -9223372036854775807 - 1)
		toprint = changeunnumtype(sp, lli);
	else
		toprint = changenumtype(sp, lli);
	choice(sp, toprint, c);
	counting(sp, c, ft_strlen(toprint));
	ft_strdel(&toprint);
}
