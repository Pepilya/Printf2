/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:40:13 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 14:46:26 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_spec	*deletelem(t_spec *lst)
{
	t_spec	*prev;
	t_spec	*next;

	prev = lst->prev;
	next = lst->next;
	if (prev != NULL)
		prev->next = lst->next;
	if (next != NULL)
		next->prev = lst->prev;
	free(lst);
	return (prev);
}

void	delete(t_spec *sp)
{
	t_spec *tmp;

	tmp = sp;
	while (sp != NULL)
	{
		ft_strdel(&sp->text);
		sp = sp->next;
	}
	while (tmp != NULL)
	{
		sp = tmp;
		tmp = tmp->next;
		deletelem(sp);
	}
}

int		lasttxt(t_spec *sp, int result)
{
	if (sp->text != NULL)
	{
		ft_putstr(sp->text);
		result += ft_strlen(sp->text);
	}
	return (result);
}

int		toprint(t_spec *sp, va_list argp, int result)
{
	while (sp->next != NULL)
	{
		if (sp->type == '%')
			getpercent(sp);
		else if (sp->type == 's')
			getstring(sp, argp);
		else if (sp->type == 'c')
			printchar(sp, argp);
		else if (sp->type == 'd' || sp->type == 'i')
			printnum(sp, argp);
		else if (sp->type == 'p')
			printpointer(sp, argp);
		else if (sp->type == 'X' || sp->type == 'o' || sp->type == 'u'
		|| sp->type == 'x' || sp->type == 'U')
			printunsignednum(sp, argp, 0, 0);
		else if (sp->type == 'f')
			getdb(sp, argp, 0, 0);
		else
			getrest(sp);
		result += sp->count;
		sp = sp->next;
	}
	return (lasttxt(sp, result));
}

int		ft_printf(const char *f, ...)
{
	t_spec	*sp;
	va_list	argp;
	int		result;

	result = 0;
	va_start(argp, f);
	sp = checkstring(f);
	while (sp->prev != NULL)
		sp = sp->prev;
	result = toprint(sp, argp, result);
	va_end(argp);
	delete(sp);
	return (result);
}
