/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:38:58 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 12:30:26 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		setcolor2(t_param *p, t_com c)
{
	if (p->a && (c == ra || c == rr))
	{
		p->a->prev->color = 2;
		p->a->color = 1;
	}
	if (p->b && (c == rb || c == rr))
	{
		p->b->prev->color = 2;
		p->b->color = 1;
	}
	if (p->a && (c == rra || c == rrr))
	{
		p->a->color = 2;
		p->a->prev->color = 1;
	}
	if (p->b && (c == rrb || c == rrr))
	{
		p->b->color = 2;
		p->b->prev->color = 1;
	}
}

static void		setcolor(t_param *p, t_com c)
{
	if (p->a && (c == sa || c == ss))
	{
		p->a->color = 2;
		p->a->next->color = 2;
	}
	if (p->b && (c == sb || c == ss))
	{
		p->b->color = 2;
		p->b->next->color = 2;
	}
	if (c == pa || c == pb)
	{
		if (p->b && c == pa)
			p->b->color = 1;
		else if (p->b)
			p->b->color = 2;
		if (p->a && c == pa)
			p->a->color = 2;
		else if (p->a)
			p->a->color = 1;
	}
	setcolor2(p, c);
}

static void		print_cur(t_list *cur)
{
	if (cur->color == 1)
	{
		ft_printf("%{01:00}");
		cur->color = 0;
	}
	else if (cur->color == 2)
	{
		ft_printf("%{02:00}");
		cur->color = 0;
	}
	ft_printf(" %2d", cur->data);
	ft_printf("%{99:99}");
}

void			list_print(char *name, t_list *start)
{
	t_list		*cur;

	cur = start;
	ft_printf("%s:", name);
	if (!start)
	{
		printf("\n");
		return ;
	}
	print_cur(cur);
	cur = cur->next;
	while (cur != start)
	{
		print_cur(cur);
		cur = cur->next;
	}
	ft_printf("\n");
}

void			psw_debug(t_param *p, t_com com)
{
	char	ch;

	ch = 0;
	if (!p->d.on)
		return ;
	if (p->d.color)
		setcolor(p, com);
	list_print("A", p->a);
	list_print("B", p->b);
	ft_printf("\n");
	if (p->d.step)
		while (ch != '\n')
			read(0, &ch, 1);
}
