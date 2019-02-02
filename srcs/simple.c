/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:36:01 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 12:16:20 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		psw_simplest(t_param *p, t_list *a)
{
	if (a->next->order > a->prev->order && a->order < a->prev->order)
	{
		DO(p, sa);
		DO(p, ra);
	}
	else if (a->order < a->next->order && a->order > a->prev->order)
	{
		DO(p, ra);
		DO(p, ra);
	}
	else if (a->order > a->next->order && a->order < a->prev->order)
	{
		DO(p, sa);
	}
	else if (a->order > a->next->order && a->prev->order < a->next->order)
	{
		DO(p, ra);
		DO(p, sa);
	}
	else if (a->order > a->prev->order && a->prev->order > a->next->order)
		DO(p, ra);
}

void			psw_simple(t_param *p, int max)
{
	if (max == 3)
		psw_simplest(p, p->a);
	else if (max == 2 && p->a->next->order < p->a->order)
		DO(p, sa);
}
