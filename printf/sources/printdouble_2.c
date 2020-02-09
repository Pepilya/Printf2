/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdouble_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:48:33 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 15:58:21 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	roundnum(t_spec *sp, unsigned long *arr)
{
	size_t i;
	size_t j;

	i = sp->acc + 1;
	j = i;
	while (i > 0)
	{
		if ((arr[i] >= 5 && (j == i)) || arr[i] >= 10)
		{
			arr[i - 1] += 1;
			arr[i] = arr[i] % 10;
		}
		i--;
	}
}

void	mkdouble(t_spec *sp, unsigned long *arr)
{
	size_t i;
	size_t j;

	i = sp->acc + 1;
	j = 0;
	while (i > 0)
	{
		if (j == 0)
			arr[j++] = sp->bp_num;
		sp->ap_num *= 10;
		arr[j++] = (int)sp->ap_num;
		sp->ap_num -= (int)sp->ap_num;
		i--;
	}
	roundnum(sp, arr);
}

char	*addint(t_spec *sp, unsigned long *arr)
{
	char *tmp;
	char *str;

	tmp = ft_itoa_base_ulong(arr[0], 10, sp->mod);
	if (sp->acc > 0 || (sp->acc == 0 && sp->flag_grid))
	{
		str = ft_strjoin(tmp, ".");
		ft_strdel(&tmp);
		tmp = str;
	}
	return (tmp);
}

char	*dbtost(t_spec *sp, unsigned long *arr, size_t i, size_t j)
{
	char	*beforepoint;
	char	*afterpoint;
	size_t	arrindex;
	char	*result;

	beforepoint = addint(sp, arr);
	afterpoint = (char *)malloc(sizeof(char) * sp->acc + 1);
	i = sp->acc;
	j = 0;
	arrindex = 1;
	while (i-- > 0)
		afterpoint[j++] = (char)arr[arrindex++] + 48;
	afterpoint[j] = 0;
	result = ft_strjoin(beforepoint, afterpoint);
	result = check(result, sp);
	ft_strdel(&beforepoint);
	ft_strdel(&afterpoint);
	return (result);
}
