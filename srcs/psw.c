/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rage1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:50:57 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 14:10:45 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				check(t_param *p)
{
	t_list		*tmp;

	tmp = p->a;
	while (tmp->next != p->a)
	{
		if (tmp->next->order < tmp->order)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void		psw_splita(t_param *p, int max)
{
	int		size;

	size = max - 3;
	while (size-- > 0)
	{
		DO(p, pb);
	}
	psw_simple(p, 3);
}

static void		short_way(t_param *p)
{
	t_c		cm;

	cm.c_rr = 0;
	cm.c_ra = 0;
	cm.c_rb = 0;
	cm.c_rrr = 0;
	cm.c_rra = 0;
	cm.c_rrb = 0;
	cm = step(p, cm);
	while (cm.c_rr--)
		DO(p, rr);
	while (cm.c_rrr--)
		DO(p, rrr);
	while (cm.c_ra--)
		DO(p, ra);
	while (cm.c_rb--)
		DO(p, rb);
	while (cm.c_rra--)
		DO(p, rra);
	while (cm.c_rrb--)
		DO(p, rrb);
	DO(p, pa);
}

static void		psw_rot(t_param *p, int max)
{
	int		i;
	t_list	*tmp;

	if (p->a->order == max)
	{
		DO(p, ra);
		return ;
	}
	i = 1;
	tmp = p->a->next;
	while (tmp->order != max)
	{
		++i;
		tmp = tmp->next;
	}
	DO(p, max - i >= i ? ra : rra);
}

void			psw_main(t_param *p)
{
	int		max;

	if ((max = set_order(p->a)) < 4)
	{
		psw_simple(p, max);
		return ;
	}
	if (!check(p))
		return ;
	psw_splita(p, max);
	while (p->b)
		short_way(p);
	while (check(p))
		psw_rot(p, max);
}
