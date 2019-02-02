/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:43:33 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/02 20:14:39 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		check_num(char *ptr)
{
	int		minus;
	char	*tmp;
	int		i;

	minus = 0;
	i = 0;
	if (*ptr == '-')
	{
		++ptr;
		minus = 1;
	}
	else if (*ptr == '+')
		++ptr;
	tmp = ptr;
	while (*tmp && *tmp != ' ')
	{
		if ((i += (i || *tmp != '0' ? 1 : 0)) > 10)
			STOP;
		if (!ft_isdigit(*tmp++))
			STOP;
	}
	if (ptr[0] >= '2' && ptr[1] >= '1' && ptr[2] >= '4' && ptr[3] >= '7' &&
		ptr[4] >= '4' && ptr[5] >= '8' && ptr[6] >= '3' && ptr[7] >= '6' &&
		ptr[8] >= '4' && (minus ? ptr[9] == '9' : ptr[9] > '7'))
		STOP;
}

static void		get_nums(t_param *p, char *ptr)
{
	t_list		*tmp;

	while (*ptr)
	{
		check_num(ptr);
		if (!(p->a = list_pushback(p->a, list_new(ft_atoi(ptr)))))
			STOP;
		tmp = p->a;
		while (tmp != p->a->prev)
		{
			if (tmp->data == p->a->prev->data)
				STOP;
			tmp = tmp->next;
		}
		if (*ptr == '-' || *ptr == '+')
			ptr++;
		while (ft_isdigit(*ptr))
			ptr++;
		while (*ptr == ' ')
			ptr++;
	}
}

static void		get_flags(t_param *p, char *ptr)
{
	if (*ptr == 'v')
		p->d.on = 1;
	else if (*ptr == 'c')
		p->d.color = 1;
	else if (*ptr == 's')
		p->d.step = 1;
	else
		STOP;
}

void			get_args(t_param *p, int argc, char **argv, int i)
{
	char		*ptr;

	while (++i < argc)
	{
		ptr = argv[i];
		while (*ptr && !ft_isdigit(*ptr) &&
				!(*ptr == '-' && ft_isdigit(*(ptr + 1))))
		{
			if (*ptr == '-' && *(++ptr))
				while (*ptr && *ptr != ' ')
					get_flags(p, ptr++);
			else if (*ptr == ' ')
				ptr++;
			else if (*ptr != '\0')
				STOP;
			if (*ptr == '\0' && ++i < argc)
				ptr = argv[i];
		}
		while (i < argc)
		{
			get_nums(p, ptr);
			if (++i < argc)
				ptr = argv[i];
		}
	}
}

void			com_print(t_com com)
{
	if (com == sa)
		ft_printf("sa\n");
	else if (com == sb)
		ft_printf("sb\n");
	else if (com == ss)
		ft_printf("ss\n");
	else if (com == pa)
		ft_printf("pa\n");
	else if (com == pb)
		ft_printf("pb\n");
	else if (com == ra)
		ft_printf("ra\n");
	else if (com == rb)
		ft_printf("rb\n");
	else if (com == rr)
		ft_printf("rr\n");
	else if (com == rra)
		ft_printf("rra\n");
	else if (com == rrb)
		ft_printf("rrb\n");
	else if (com == rrr)
		ft_printf("rrr\n");
}
