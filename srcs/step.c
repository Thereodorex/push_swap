/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rage2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:50:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/01 16:48:15 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_c		step_rb(t_param *p, t_c cm, t_list *a, t_list *b)
{
	t_c		tmp;
	t_c		min;

	++cm.c_rb;
	min = cm;
	min.c_rb = 1000000;
	tmp = min;
	if ((b->order > a->prev->order && a->prev->order > a->order) ||
	(b->order < a->order && b->order > a->prev->order) ||
	(b->order < a->order && a->prev->order > a->order))
		return (cm);
	if (b->next != p->b)
		min = step_rb(p, cm, a, b->next);
	return (min);
}

static t_c		step_rrb(t_param *p, t_c cm, t_list *a, t_list *b)
{
	t_c		tmp;
	t_c		min;

	++cm.c_rrb;
	min = cm;
	min.c_rb = 1000000;
	tmp = min;
	if ((b->order > a->prev->order && a->prev->order > a->order) ||
	(b->order < a->order && b->order > a->prev->order) ||
	(b->order < a->order && a->prev->order > a->order))
		return (cm);
	if (b->prev != p->b)
		min = step_rrb(p, cm, a, b->prev);
	return (min);
}

static t_c		step_ra(t_param *p, t_c cm, t_list *a, t_list *b)
{
	t_c		tmp;
	t_c		min;

	++cm.c_ra;
	min = cm;
	min.c_ra = 1000000;
	tmp = min;
	if ((b->order > a->prev->order && a->prev->order > a->order) ||
	(b->order < a->order && b->order > a->prev->order) ||
	(b->order < a->order && a->prev->order > a->order))
		return (cm);
	if (a->next != p->a)
		min = step_ra(p, cm, a->next, b);
	if (b->next != p->b)
		tmp = step_rb(p, cm, a, b->next);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	if (b->prev != p->b)
		tmp = step_rrb(p, cm, a, b->prev);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	return (min);
}

static t_c		step_rra(t_param *p, t_c cm, t_list *a, t_list *b)
{
	t_c		tmp;
	t_c		min;

	++cm.c_rra;
	min = cm;
	min.c_rra = 1000000;
	tmp = min;
	if ((b->order > a->prev->order && a->prev->order > a->order) ||
	(b->order < a->order && b->order > a->prev->order) ||
	(b->order < a->order && a->prev->order > a->order))
		return (cm);
	if (a->prev != p->a)
		min = step_rra(p, cm, a->prev, b);
	if (b->next != p->b)
		tmp = step_rb(p, cm, a, b->next);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	if (b->prev != p->b)
		tmp = step_rrb(p, cm, a, b->prev);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	return (min);
}

t_c				step(t_param *p, t_c cm)
{
	t_c		tmp;
	t_c		min;

	if ((p->b->order > p->a->prev->order && p->a->prev->order > p->a->order) ||
	(p->b->order < p->a->order && p->b->order > p->a->prev->order) ||
	(p->b->order < p->a->order && p->a->prev->order > p->a->order))
		return (cm);
	min = step_ra(p, cm, p->a->next, p->b);
	tmp = step_rra(p, cm, p->a->prev, p->b);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	tmp = step_rb(p, cm, p->a, p->b->next);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	tmp = step_rrb(p, cm, p->a, p->b->prev);
	if (c_sum(&min) > c_sum(&tmp))
		min = tmp;
	c_sum(&min);
	return (min);
}
