/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:06:08 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 20:20:33 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

static int		test(t_param *p)
{
	t_list	*tmp;

	if (p->b)
		return (1);
	tmp = p->a->next;
	while (tmp != p->a)
	{
		if (tmp->data < tmp->prev->data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static t_com	strtocom(char *str)
{
	if (!ft_strcmp(str, "ra"))
		return (ra);
	if (!ft_strcmp(str, "rb"))
		return (rb);
	if (!ft_strcmp(str, "rr"))
		return (rr);
	if (!ft_strcmp(str, "rra"))
		return (rra);
	if (!ft_strcmp(str, "rrb"))
		return (rrb);
	if (!ft_strcmp(str, "rrr"))
		return (rrr);
	if (!ft_strcmp(str, "pa"))
		return (pa);
	if (!ft_strcmp(str, "pb"))
		return (pb);
	if (!ft_strcmp(str, "sa"))
		return (sa);
	if (!ft_strcmp(str, "sb"))
		return (sb);
	if (!ft_strcmp(str, "ss"))
		return (ss);
	return (err);
}

static void		get_commands(t_param *p)
{
	char		buf[5];
	char		*line;
	t_com		tmp;

	line = NULL;
	get_next_line(0, &line);
	while (line)
	{
		if ((tmp = strtocom(line)) != err)
		{
			DO_C(p, tmp);
		}
		else
			STOP;
		ft_strdel(&line);
		if ((get_next_line(0, &line)) == -1)
			STOP;
	}
}

int				main(int argc, char **argv)
{
	t_param		p;

	p.a = NULL;
	p.b = NULL;
	p.d.on = 0;
	p.d.color = 0;
	get_args(&p, argc, argv, 0);
	p.d.step = 0;
	if (!p.a)
		return (0);
	get_commands(&p);
	ft_printf(test(&p) ? "KO" : "OK");
	list_del(p.a);
	list_del(p.b);
	return (0);
}
