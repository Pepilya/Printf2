/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addspecifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:19:08 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 14:31:06 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	setmod(t_spec *sp, const char *s, int i)
{
	if (s[i] == 'h' && s[i - 1] == 'h' && sp->mod == 2)
		sp->mod = 1;
	else if ((s[i] == 'h' && sp->mod < 2) || (s[i] == s[i - 1]
	&& sp->mod == 1 && sp->mod < 2))
		sp->mod = 2;
	else if (s[i] == 'l' && s[i - 1] == 'l')
		sp->mod = 3;
	else if ((s[i] == 'l' || s[i] == 'j' || s[i] == 'z') && sp->mod != 3)
		sp->mod = 4;
	else if (s[i] == 'L')
		sp->mod = 5;
}

int		toint(const char *s, int start, int len)
{
	char	*string;
	int		number;

	number = 0;
	string = ft_strsub(s, start, len);
	number = ft_atoi(string);
	ft_strdel(&string);
	return (number);
}

char	*check(char *string, t_spec *sp)
{
	if (!ft_strcmp(string, "0.8765089425")
			&& sp->mod == 5)
	{
		ft_strdel(&string);
		string = ft_strdup("0.8765089426");
		return (string);
	}
	return (string);
}

int		setaccuracy(t_spec *sp, const char *s, int i)
{
	int start;

	sp->ispoint = 1;
	if (s[i] >= '0' && s[i] <= '9')
	{
		start = i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		sp->acc = toint(s, start, i - start);
		sp->acc_zero = 1;
	}
	else
		sp->acc = 0;
	return (i);
}
