/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:36:51 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:40:40 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			addwidth(const char *s, t_spec *sp, int i)
{
	int start;

	start = i;
	while (s[i + 1] && (s[i + 1] >= '0' && s[i + 1] <= '9'))
		i++;
	sp->width = toint(s, start, i - start + 1);
	return (i);
}

void		addflags(t_spec *sp, char c)
{
	if (c == ' ')
		sp->flag_space = 1;
	else if (c == '+')
		sp->flag_plus = 1;
	else if (c == '-')
		sp->flag_minus = 1;
	else if (c == '#')
		sp->flag_grid = 1;
	else if (c == '0' && sp->flag_zero != -1)
		sp->flag_zero = 1;
}

int			valid(const char *s, t_spec *sp, int i, char *flags)
{
	while (s[i] && sp->type == 0)
	{
		if (ft_strchr(flags, s[i]))
			addflags(sp, s[i]);
		else if (s[i] > '0' && s[i] <= '9')
			i = addwidth(s, sp, i);
		else if (s[i] == '.')
		{
			i = setaccuracy(sp, s, i + 1);
			continue ;
		}
		else if (s[i] == 'L' || s[i] == 'h' || s[i] == 'l' || s[i] == 'j'
		|| s[i] == 'z')
			setmod(sp, s, i);
		else
		{
			sp->type = s[i];
			break ;
		}
		i++;
	}
	return (i);
}

t_spec		*checkstring(const char *f)
{
	int		i;
	int		st;
	t_spec	*sp;

	i = 0;
	st = 0;
	sp = NULL;
	while (f[i])
	{
		if (f[i] == '%')
		{
			sp = getspec(sp);
			sp->text = ft_strsub(f, st, i - st);
			i++;
			i = valid(f, sp, i, " +-#0");
			st = i + 1;
		}
		if (!f[i])
			break ;
		i++;
	}
	sp = getspec(sp);
	sp->text = ft_strsub(f, st, i - st);
	return (sp);
}
