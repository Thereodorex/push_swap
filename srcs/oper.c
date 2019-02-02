/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:08:44 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/01 17:56:11 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			set_order(t_list *a)
{
	int		q;
	t_list	*cur;
	t_list	*max;
	int		res;

	q = 1;
	cur = a;
	while ((cur = cur->next) != a)
		q++;
	res = q;
	while (q)
	{
		while (cur->order)
			cur = cur->next;
		max = cur;
		while ((cur = cur->next) != a)
			if (!cur->order && cur->data > max->data)
				max = cur;
		max->order = q--;
	}
	return (res);
}

int			c_sum(t_c *cm)
{
	while (cm->c_ra && cm->c_rb)
	{
		--(cm->c_ra);
		--(cm->c_rb);
		++(cm->c_rr);
	}
	while (cm->c_rra && cm->c_rrb)
	{
		--(cm->c_rra);
		--(cm->c_rrb);
		++(cm->c_rrr);
	}
	return (cm->c_rr + cm->c_ra + cm->c_rb +
							cm->c_rrr + cm->c_rra + cm->c_rrb);
}

t_list		*o_swap(t_list *start)
{
	t_list		*node;

	if (!start)
		return (NULL);
	node = start->next;
	start = list_cut(start, node);
	return (list_pushfront(start, node));
}

t_list		*o_push(t_list *dst, t_list **src)
{
	t_list	*tmp;

	tmp = *src;
	if (!tmp)
		return (dst);
	*src = list_cut(*src, tmp);
	return (list_pushfront(dst, tmp));
}

void		do_op(t_param *p, t_com com)
{
	if (com < pa)
	{
		if (com == sa || com == ss)
			SWAP(p->a);
		if (com == sb || com == ss)
			SWAP(p->b);
	}
	else if (com == pa)
		PUSH(p->a, p->b);
	else if (com == pb)
		PUSH(p->b, p->a);
	else if (com < rra)
	{
		if (com == ra || com == rr)
			ROT(p->a);
		if (com == rb || com == rr)
			ROT(p->b);
	}
	else
	{
		if (com == rra || com == rrr)
			RROT(p->a);
		if (com == rrb || com == rrr)
			RROT(p->b);
	}
}
