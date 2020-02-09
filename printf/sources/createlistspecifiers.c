/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createlistspecifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipepelia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:35:49 by ipepelia          #+#    #+#             */
/*   Updated: 2020/02/09 14:39:41 by ipepelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init(t_spec *sp)
{
	sp->flag_grid = 0;
	sp->flag_minus = 0;
	sp->flag_plus = 0;
	sp->flag_space = 0;
	sp->flag_zero = 0;
	sp->acc_zero = 0;
	sp->count = 0;
	sp->sign = 0;
	sp->width = 0;
	sp->ispoint = 0;
	sp->acc = 0;
	sp->mod = 0;
	sp->type = 0;
	sp->bp_num = 0;
	sp->ap_num = 0;
	sp->text = NULL;
	sp->next = NULL;
	sp->prev = NULL;
}

t_spec	*getspec(t_spec *sp)
{
	t_spec *tmp;

	tmp = NULL;
	if (sp == NULL)
	{
		sp = (t_spec *)malloc(sizeof(t_spec));
		init(sp);
		return (sp);
	}
	while (sp->next != NULL)
		sp = sp->next;
	sp->next = (t_spec *)malloc(sizeof(t_spec));
	init(sp->next);
	tmp = sp;
	sp = sp->next;
	sp->prev = tmp;
	return (sp);
}
